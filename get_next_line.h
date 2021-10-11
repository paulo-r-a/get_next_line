/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parobert <parobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:49:21 by parobert          #+#    #+#             */
/*   Updated: 2021/10/08 13:11:40 by parobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_calloc(size_t num, size_t size);

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dest, const char *source, size_t n);

size_t	ft_strlcat(char *dest, const char *source, size_t n);

void	ft_bzero(void *b, size_t n);

char	*get_next_line(int fd);

#endif
