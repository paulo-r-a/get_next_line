/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parobert <parobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:49:14 by parobert          #+#    #+#             */
/*   Updated: 2021/10/10 21:29:52 by parobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_oldadd_n_to_line(char *chr_ptr, int *endline)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(chr_ptr);
	i = 0;
	while (i < len)
	{
		if (chr_ptr[i] == '\n')
		{
			*endline = 1;
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

static size_t	ft_add_n_to_line(char *chr_ptr, int *endline, size_t readsize)
{
	size_t	i;

	i = 0;
	while (i < readsize)
	{
		if (chr_ptr[i] == '\n')
		{
			*endline = 1;
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

static void	ft_line_allocation(int fd, char **line, char **old, int *endline)
{
	char	*buffer;
	char	*line_updt;
	ssize_t	i;
	size_t	n;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (buffer != NULL)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
		{
			free(buffer);
			buffer = NULL;
			*endline = 1;
			return ;
		}
		if (i == -1)
		{
			free(buffer);
			buffer = NULL;
			*endline = 2;
			return ;
		}
		n = ft_add_n_to_line(buffer, endline, i);
		line_updt = (char *)ft_calloc(ft_strlen(*line) + n + 1, sizeof(char));
/*		if (line_updt == NULL)
		{
			free(buffer);
			buffer = NULL;
			free(*line);
			*line = NULL;
			free(*old);
			*old = NULL;
		}*/
		if (line != NULL)
			ft_strlcpy(line_updt, *line, (ft_strlen(*line) + 1));
		ft_strlcat(line_updt, buffer, (ft_strlen(*line) + n + 1));
		free(*line);
		*line = line_updt;
		line_updt = NULL;
		if (*endline == 1)
		{
			ft_strlcpy(*old, buffer + n, i - n + 1);
			free(buffer);
			buffer = NULL;
			return ;
		}
	}
}

static void	ft_old_line_allocation(char **line, char **old, int *endline)
{
	size_t	n;

	if (ft_strlen(*old) == 0)
		return ;
	n = ft_oldadd_n_to_line(*old, endline);
	*line = (char *)malloc((n + 1) * sizeof(char));
	if (*line == NULL)
	{
		*endline = 2;
		return;
	}
	(*line)[n] = '\0';
	ft_strlcpy(*line, *old, n + 1);
	ft_strlcpy(*old, (*old + n), BUFFER_SIZE - n);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*old;
	int			endline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	endline = 0;
	if (old == NULL)
		old = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
//	if (read(fd, old, 0) == -1)
//		return (NULL);
	ft_old_line_allocation(&line, &old, &endline);
	if (endline == 1)
		return (line);
	if (endline == 2)
		return (NULL);
	ft_line_allocation(fd, &line, &old, &endline);
	if (endline == 2)
		return (NULL);
	return (line);
}
