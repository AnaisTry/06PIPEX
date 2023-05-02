/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:17:56 by angassin          #+#    #+#             */
/*   Updated: 2023/05/02 17:15:26 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**commands_paths_array(char **envp);
static char	*command_access(char *cmd, char **paths);

/*
	Creates a child process : send to the pipe the output of the execution
	of the command passed in argument.
	Parent process : wait and then read the output of the child from the pipe.
	The child process has it's own copy of the parent's file's decriptors.
*/
void	create_process(char *argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		error_exit("could not create pipe");
	pid = fork();
	if (pid == -1)
		error_exit("could not create process");
	if (pid == CHILD)
	{
		close(fd[0]);
		duplicate(fd[1], STDOUT_FILENO, "could not write to the pipe");
		close(fd[1]);
		execute(argv, envp);
	}
	close(fd[1]);
	duplicate(fd[0], STDIN_FILENO, "could not read from the pipe");
	close(fd[0]);
}

int	lastcmd_process(int argc, char *argv, char **envp, int arg_counter)
{
	int	pid;
	int	status;
	int	exit_status;

	pid = fork();
	if (pid == -1)
		error_exit("could not create process");
	if (pid == CHILD)
		execute(argv, envp);
	waitpid(pid, &status, 0);
	arg_counter++;
	exit_status = WEXITSTATUS(status);
	while (arg_counter <= argc - 2)
	{
		waitpid(-1, &status, 0);
		arg_counter++;
	}
	return (exit_status);
}

/*
	Executes the command sent in argument, execve returns only in case
	of failure as the execve() function overlays the current process image
	with a new process image.
*/
void	execute(char *argv, char **envp)
{
	char	**paths;
	char	*cmd_path;
	char	**cmd;

	if (!argv || !argv[0])
		error_exit("parse error near """);
	cmd = ft_split(argv, ' ');
	if (cmd == NULL)
		error_exit("parsing of the command failed");
	paths = commands_paths_array(envp);
	cmd_path = command_access(cmd[0], paths);
	if (cmd_path == NULL)
	{
		ft_free_array(cmd);
		ft_free_array(paths);
		exit(127);
	}
	execve(cmd_path, cmd, envp);
	perror("could not execute the command");
	ft_free_array(cmd);
	free(cmd_path);
	exit(127);
}

/*
	Returns an array of the different paths to the executables
	or NULL if the PATH environment variable is not found.
*/
static char	**commands_paths_array(char **envp)
{
	int		i;
	char	**paths;
	char	*path_str;

	path_str = NULL;
	if (envp == NULL)
		return (0);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == OK)
		{
			path_str = &envp[i][5];
			break ;
		}
		++i;
	}
	if (path_str == NULL)
		return (NULL);
	paths = ft_split(path_str, ':');
	return (paths);
}

/*
	Returns the path to the command given in argument if exists.
	Otherwise displays error and return NULL.
*/
static char	*command_access(char *cmd, char **paths)
{
	int		i;
	char	*cmd_address;
	char	*error;

	if (access(cmd, X_OK) == OK)
		return (cmd);
	i = -1;
	while (paths[++i])
	{
		cmd_address = variadic_strjoin(3, paths[i], "/", cmd);
		if (access(cmd_address, X_OK) == OK)
			return (cmd_address);
		free(cmd_address);
	}
	error = variadic_strjoin(3, "pipex: ", cmd, ": command not found\n");
	ft_putstr_fd(error, STDERR_FILENO);
	free(error);
	return (NULL);
}
