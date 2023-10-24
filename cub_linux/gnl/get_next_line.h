/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:07:03 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/23 15:02:08 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

/******
* Utils *
******/

size_t	ft_strlen(const char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_strchr_gnl(char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
