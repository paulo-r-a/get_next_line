/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parobert <parobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:49:08 by parobert          #+#    #+#             */
/*   Updated: 2021/10/08 15:46:19 by parobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *b, size_t n)
{
	size_t	i;
	char	*b_ptr;

	b_ptr = (char *)b;
	i = 0;
	while (i < n)
	{
		*(b_ptr + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(num * size);
	if (ptr != NULL)
		ft_bzero(ptr, num * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *source, size_t n)
{
	size_t	i;

	if (source == NULL || dest == NULL)
		return (0);
	i = 0;
	if (n == 0)
		return (ft_strlen(source));
	while (i < n - 1)
	{
		if (*(source + i) == '\0')
			break ;
		*(dest + i) = *(source + i);
		i++;
	}
	*(dest + i) = '\0';
	return (ft_strlen(source));
}

size_t	ft_strlcat(char *dest, const char *source, size_t n)
{
	size_t	i;

	if (source == NULL || dest == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*(dest + i) == '\0')
			break ;
		i++;
	}
	if (n > i)
		ft_strlcpy((dest + i), source, (n - i));
	return (i + ft_strlen(source));
}
