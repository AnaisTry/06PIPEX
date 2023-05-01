/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:17:56 by angassin          #+#    #+#             */
/*   Updated: 2023/04/29 14:07:18 by angassin         ###   ########.fr       */
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
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error_exit("could not write to the pipe");
		close(fd[1]);
		execute(argv, envp);
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error_exit("could not read from the pipe");
	close(fd[0]);
}

void	execute(char *argv, char **envp)
{
	char	**paths;
	char	*cmd_path;
	char	**cmd;

	if (!argv || !argv[0])
		error_exit("parse error near """);
	cmd = ft_split(argv, ' ');
	// check allocation
	paths = commands_paths_array(envp);
	cmd_path = command_access(cmd[0], paths);
	if (execve(cmd_path, cmd, envp) == -1)
	{
		perror("could not execute the command");
		ft_free_array(cmd);
		free(cmd_path);
		exit(127);
	}
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
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
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

	// if (access(cmd, X_OK) == OK)
	// 	return (cmd);
	i = -1;
	while (paths[++i])
	{
		cmd_address = variadic_strjoin(3, paths[i], "/", cmd);
		if (access(cmd_address, X_OK))
		{
			free(cmd);
			return (cmd_address);
		}
		free(cmd_address);
	}
	error = variadic_strjoin(2, cmd, ": command not found\n");
	write(STDERR_FILENO, error, ft_strlen(error));
	free(error);
	free(cmd);
	return (NULL);
}
// static void	first_command(int *files, int *fd, t_pipex *elems);

// void	pipex(t_pipex *elems)
// {
// 	int	fd[2];
// 	int	files[2];
// 	int	pid[2];

// 	if (pipe(fd) == -1)
// 		error_exit(elems, "pipe_error");
// 	files[0] = open(elems->argv[1], O_RDONLY, 0444);
// 	files[1] = -1;
// 	if (files[0] > 0)
// 		first_command(files, fd, elems);

// }

// static void	first_command(int *files, int *fd, t_pipex *elems)
// {
// 	int	i;

// 	if (elems->argv[2][0] == NULL)
// 		error_exit(elems, "Command");
// 	elems->cmds = ft_split(elems->argv[2], ' ');
// 	if (elems->cmds == NULL)
// 		error_exit(elems, ENOMEM);
// 	elems->cmds[0] = get_command_path(elems->cmds[0], elems->paths);

// }
// 	(void)argc;
// 	(void)argv;

// 		// in_out
// 	int	pid1;
// 	int pid2;

// 	if (pipe(fd) == -1)
// 		return (1);

// 	pid1 = fork();
// 	if (pid1 == -1 )
// 		return (2);
// 	//child process ls (cmd1)
// 	if (pid1 == 0)
// 	{
// 		//write : dest, src
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		//execve
// 		execlp("ls", "ls", "-l", NULL);
// 	}
// 	pid2 = fork();
// 	if (pid2 == -1)
// 		return (3);
// 	//child process wc (cmd 2)
// 	if (pid2 == 0)
// 	{
// 		//read
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("wc", "wc", "-l", NULL);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	//child, status, option
// 	waitpid(pid1, NULL, 0);
