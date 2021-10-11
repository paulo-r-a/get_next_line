/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parobert <parobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:49:08 by parobert          #+#    #+#             */
/*   Updated: 2021/10/11 09:26:04 by parobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	len;

	ptr = malloc(num * size);
	i = 0;
	len = num * size;
	if (ptr != NULL)
	{
		while (i < len)
		{
			*(char *)(ptr + i) = 0;
			i++;
		}
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
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

int	ft_free_pointers(void **ptr1, void **ptr2, int return_value)
{
	if (*ptr1 != NULL)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (*ptr2 != NULL)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (return_value);
}
