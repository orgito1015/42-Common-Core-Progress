/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:35:35 by oleka             #+#    #+#             */
/*   Updated: 2025/11/12 11:35:37 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

t_lines	ft_return_lines(char *s, size_t n)
{
	t_lines	lines;
	size_t	i;

	lines = ft_zeroed();
	if (!s)
		return (lines);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
	{
		lines.line = ft_substr(s, 0, i + 1);
		lines.remainder = ft_substr(s, i + 1, ft_n_or_l(s, 'l') - (i + 1));
	}
	else
	{
		lines.line = ft_substr(s, 0, i);
		lines.remainder = NULL;
	}
	if (n == 0 && lines.remainder == NULL && ft_n_or_l(lines.line, 'n'))
		lines.remainder = ft_strdup("");
	return (lines);
}

char	*invalid_n(char **lines, char **temp, ssize_t n)
{
	if (n < 0)
	{
		free(*lines);
		*lines = NULL;
		return (NULL);
	}
	if (n == 0)
	{
		if (*lines && **lines)
		{
			*temp = *lines;
			*lines = NULL;
			return (*temp);
		}
		free(*lines);
		*lines = NULL;
	}
	return (NULL);
}

char	*return_something(char c)
{
	if (c == 'b')
		return (malloc(sizeof(char) * (BUFFER_SIZE + 1)));
	if (c == 'l')
		return (malloc(1));
	return (NULL);
}

static ssize_t	ft_read_loop(int fd, char **lines, char *buffer)
{
	ssize_t	n;
	char	*temp;

	while (!ft_n_or_l(*lines, 'n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			return (n);
		buffer[n] = '\0';
		temp = ft_concatenate(*lines, buffer);
		if (!temp)
			return (-1);
		free(*lines);
		*lines = temp;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*lines;
	char		*temp;
	char		*buffer;
	ssize_t		n;
	t_lines		lines_struct;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = return_something('b');
	if (!buffer)
		return (NULL);
	n = ft_read_loop(fd, &lines, buffer);
	if (n <= 0)
	{
		free(buffer);
		return (invalid_n(&lines, &temp, n));
	}
	free(buffer);
	lines_struct = ft_return_lines(lines, n);
	temp = lines_struct.line;
	free(lines);
	lines = lines_struct.remainder;
	return (temp);
}

/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("Line %d: %s", i, line);
		if (line[0] == '\0')
			printf("(empty line)\n");
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
*/
