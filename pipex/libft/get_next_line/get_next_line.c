/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:41:24 by angassin          #+#    #+#             */
/*   Updated: 2023/02/25 15:07:21 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

const char	*read_and_append(char *already_read, int fd, ssize_t status);
const char	*append(const char *buff, char *already_read);
const char	*extract_line(char **already_read);
const char	*keep_leftover(char *left_over);

/*
	Reads the text file pointed to by the file descriptor, one line at a time
	Return : 
			- the line that was read including the terminating \n character if
			  present
			- NULL if error or nothing else to read
	Bonus :
			- only one static variable
			- manages multiple file descriptors at the same time

	1. checks if correct fd and possible to fill buffer
	2. as long as not reached newline or EOF, appends buffer to already_read, 
	   protect in case of pb with read
	3. finds line and extract
	4. removes the line that was found from already_read[fd]
*/
char	*get_next_line(int fd)
{
	static char	*already_read[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	already_read[fd] = (char *)read_and_append(already_read[fd], fd, 1);
	if (!already_read[fd])
		return (NULL);
	line = (char *)extract_line(&already_read[fd]);
	if (line)
		already_read[fd] = (char *)keep_leftover(already_read[fd]);
	return (line);
}

/*
	As long as not reached newline or EOF, appends buffer to already_read

	1. Fills buffer and checks error
	2. Null terminates the string placed in the buffer
	3. Appends content of buffer and frees old already_read
	4. Frees buffer
*/
const char	*read_and_append(char *already_read, int fd, ssize_t status)
{
	char		*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (!buff)
	{
		free(already_read);
		return (NULL);
	}
	*buff = '\0';
	while ((status > 0) && (!ft_strchr(buff, '\n')))
	{
		status = read(fd, buff, BUFFER_SIZE);
		if (status < 0)
		{
			free(buff);
			free(already_read);
			return (NULL);
		}
		buff[status] = '\0';
		already_read = (char *)append(buff, already_read);
	}
	free(buff);
	return (already_read);
}

/*
	Appends content of buffer and frees old already_read
*/
const char	*append(const char *buff, char *already_read)
{
	char	*old;

	if (!already_read)
	{
		already_read = ft_strdup(buff);
		if (!already_read)
			return (NULL);
	}
	else
	{
		old = already_read;
		already_read = ft_strjoin(already_read, buff);
		if (!already_read)
		{
			free(old);
			return (NULL);
		}
		free(old);
	}
	return (already_read);
}

/*
	Finds the line and returns it
*/
const char	*extract_line(char **already_read)
{
	size_t	line_len;
	char	*line;
	char	*end_of_line;

	if (*already_read && !(*already_read)[0])
	{
		free(*already_read);
		*already_read = NULL;
		return (NULL);
	}
	end_of_line = ft_strchr(*already_read, '\n');
	line_len = end_of_line - *already_read;
	line = ft_substr(*already_read, 0, line_len + 1);
	if (!line)
	{
		free (*already_read);
		*already_read = NULL;
		return (NULL);
	}
	return (line);
}

/*
	Removes the line that was found from already_read[fd]
	and keeps only what is found after \n

	1. Handles error
	2. calculate size of left_over and store it
*/
const char	*keep_leftover(char *left_over)
{
	size_t			nb_chars_left;
	char			*end_of_line;
	char			*to_remove;
	unsigned int	start;

	if (!left_over)
		return (NULL);
	end_of_line = ft_strchr(left_over, '\n');
	start = (end_of_line - left_over + 1);
	nb_chars_left = ft_strlen(left_over) - start;
	to_remove = left_over;
	left_over = ft_substr(left_over, start, nb_chars_left);
	free(to_remove);
	if (!left_over)
		return (NULL);
	return (left_over);
}
