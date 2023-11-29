/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:07:03 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/29 15:17:51 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
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
