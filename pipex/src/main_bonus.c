/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:38:14 by angassin          #+#    #+#             */
/*   Updated: 2023/05/02 18:02:58 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	outfile_append_open(char *file);
static void	initial_checks(int argc, char **argv, char **envp);
static void	heredoc(const char *limiter);
static void	read_stdin(const char *limiter, int fd);

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	j;
	int	fdin;
	int	fdout;

	initial_checks(argc, argv, envp);
	if (ft_strncmp("here_doc", argv[1], 9) == OK)
	{
		i = 3;
		fdout = outfile_append_open(argv[argc - 1]);
		heredoc(argv[2]);
	}
	else
	{
		i = 2;
		fdin = infile_open(argv[1]);
		duplicate(fdin, STDIN_FILENO, "duplication of the infile failed");
		fdout = outfile_open(argv[argc - 1]);
	}
	j = i;
	while (i < argc - 2)
		create_process(argv[i++], envp);
	duplicate(fdout, STDOUT_FILENO, "duplication of the outfile failed");
	return (lastcmd_process(argc, argv[i], envp, j));
}

/* Checks number of args, environment variable and infile accessibility */
static void	initial_checks(int argc, char **argv, char **envp)
{
	if (argc < 5)
		error_exit("Wrong number of args");
	if (!envp || envp[0][0] == '\0')
		error_exit("Envp error");
	if (ft_strncmp("here_doc", argv[1], 9) != OK)
	{
		if (access(argv[1], R_OK) != OK)
			error_exit(argv[1]);
	}
}

static int	outfile_append_open(char *file)
{
	int	fd;

	fd = -1;
	fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		error_exit(file);
	return (fd);
}

/* Creates a child process to prompt the user */
static void	heredoc(const char *limiter)
{
	int			fd[2];
	int			pid;

	if (pipe(fd) == -1)
		error_exit("could not create pipe");
	pid = fork();
	if (pid == -1)
		error_exit("could not create process");
	if (pid == CHILD)
	{
		close(fd[0]);
		read_stdin(limiter, fd[1]);
		close(fd[1]);
	}
	close(fd[1]);
	duplicate(fd[0], STDIN_FILENO, "could not read from the pipe");
	close(fd[0]);
}

static void	read_stdin(const char *limiter, int fd)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			error_exit("could not read user input");
		if (ft_strncmp(limiter, line, ft_strlen(limiter)) == OK
			&& ft_strlen(limiter) == (ft_strlen(line) - 1))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(line);
}
