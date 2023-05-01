/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_example.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:16:47 by angassin          #+#    #+#             */
/*   Updated: 2023/04/24 15:49:04 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{

	(void)argc;
	(void)argv;
	(void)envp;

	int	fd[2];
	int	pid1;
	int pid2;

	if (pipe(fd) == -1)
		return (1);

	pid1 = fork();
	if (pid1 == -1 )
		return (2);
	//child process ls (cmd1)
	if (pid1 == 0)
	{
		//write : dest, src
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		//execve
		execlp("ls", "ls", "-l", NULL);
	}
	pid2 = fork();
	if (pid2 == -1)
		return (3);
	//child process wc (cmd 2)
	if (pid2 == 0)
	{
		//read
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("wc", "wc", "-l", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	//child, status, option
	waitpid(pid1, NULL, 0);
	return (0);
}

/* access() returns 0 if the action on the file was granted */
// static void	infile_check(const char *path)
// {
// 	char	*line_nb;
// 	char	*error;

// 	if (access(path, R_OK) != 0)
// 	{
// 		line_nb = ft_itoa(__LINE__ - 1);
// 		error = variadic_strjoin(7, __FILE__, ": ", __func__, ": line", line_nb,
// 				": ", path);
// 		free(line_nb);
// 		perror(error);
// 		free(error);
// 	}
// }