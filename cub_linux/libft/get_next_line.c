/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:52:50 by nsoares-          #+#    #+#             */
/*   Updated: 2022/12/07 19:03:01 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*del_line_read(char *buffer)
{
	char			*new_line;
	size_t			i;
	size_t			j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_line[j++] = buffer[i++];
	new_line[j] = '\0';
	free(buffer);
	return (new_line);
}

char	*get_lin(char *buffer)
{
	char		*line;
	size_t		size;
	size_t		i;

	if (!*buffer)
		return (NULL);
	size = 0;
	while (buffer[size] && buffer[size] != '\n')
		size++;
	line = (char *)malloc((size + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_the_file(int fd, char *read_result)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(read_result, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(read_result);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		read_result = ft_gnl_strjoin(read_result, buffer);
	}
	free(buffer);
	return (read_result);
}

char	*get_next_line(int fd)
{
	static char	*sta_buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	sta_buffer[fd] = read_the_file(fd, sta_buffer[fd]);
	if (!sta_buffer[fd])
		return (NULL);
	line = get_lin(sta_buffer[fd]);
	sta_buffer[fd] = del_line_read(sta_buffer[fd]);
	return (line);
}

/* int main()
{
    int	fd1 = open("file.txt", O_RDONLY);
	int	fd2 = open("file1.txt", O_RDONLY);

	char *line;
	int i;

	i = 1;
	while (i < 5)
	{
		line = get_next_line(fd1);
		printf("fd_1 %2d| %s", i, line);
		if (!line)
			printf("\n");
		free(line);
		line = get_next_line(fd2);
		printf("fd_2 %2d| %s", i, line);
		if (!line)
			printf("\n");
		free(line);
		++i;
	}
	close(fd1);close(fd2);
	return (0);
} */
