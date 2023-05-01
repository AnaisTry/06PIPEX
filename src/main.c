/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:16:47 by angassin          #+#    #+#             */
/*   Updated: 2023/04/26 15:11:20 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**get_commands_paths(char **envp);
static void	init(int argc, char **argv, t_pipex *elems, char **envp);
// static void	infile_init(t_pipex *elems);
// static void	outfile_init(t_pipex *elems);

int	main(int argc, char **argv, char **envp)
{
	t_pipex	elems;

	if (argc < 5)
	{
		perror("Wrong number of args");
		return (1);
	}
	if (!envp || envp[0][0] == '\0')
	{
		perror("Envp error");
		return (2);
	}
	if (access(argv[1], R_OK) != 0)
	{
		perror(argv[1]);
		return (3);
	}
	init(argc, argv, &elems, envp);
	// pipex(&elems);
	return (0);
}

static void	init(int argc, char **argv, t_pipex *elems, char **envp)
{
	//elems->argc = -1;
	elems->fd_in = -1;
	elems->fd_out = -1;
	//elems->argv = NULL;
	//elems->envp = NULL;
	elems->paths = NULL;
	elems->argc = argc;
	elems->argv = argv;
	elems->envp = envp;
	elems->paths = get_commands_paths(envp);
	// infile_init(elems);
	// outfile_init(elems);
}

/* returns the paths to the commands from the environment list */
static char	**get_commands_paths(char **envp)
{
	int		i;
	char	**path;
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
	path = ft_split(path_str, ':');
	return (path);
}


