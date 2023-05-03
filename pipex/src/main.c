/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:16:47 by angassin          #+#    #+#             */
/*   Updated: 2023/05/03 08:42:28 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fdin;
	int	fdout;

	if (argc != 5)
		error_exit("Wrong number of args");
	if (!envp || envp[0][0] == '\0')
		error_exit("Envp error");
	if (access(argv[1], R_OK) != OK)
		error_exit(argv[1]);
	fdin = infile_open(argv[1]);
	duplicate(fdin, STDIN_FILENO, "duplication of the infile failed");
	fdout = outfile_open(argv[argc - 1]);
	i = 2;
	while (i < argc - 2)
		create_process(argv[i++], envp);
	duplicate(fdout, STDOUT_FILENO, "duplication of the outfile failed");
	return (lastcmd_process(argc, argv[i], envp, 2));
}
