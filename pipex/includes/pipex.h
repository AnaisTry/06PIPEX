/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:29:35 by angassin          #+#    #+#             */
/*   Updated: 2023/05/02 18:45:48 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
/*									[Includes]								*/

# include <sys/errno.h>
// waitpid
# include <sys/wait.h>
// open
# include <fcntl.h>
// libft and other includes
# include "../libft/includes/libft.h"

/*									[Macros]								*/

# define OK 0
# define CHILD 0

/*									[Src]									*/

// pipex.c
void		create_process(char *argv, char **envp);
void		execute(char *argv, char **envp);
int			lastcmd_process(int argc, char *argv, char **envp, int arg_counter);

/*									[Utils]									*/

void		error_exit(char *error_msg);
int			infile_open(char *file);
int			outfile_open(char *file);
void		duplicate(int fd_src, int fd_dest, char *error);

#endif
