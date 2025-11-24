/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:35:41 by oleka             #+#    #+#             */
/*   Updated: 2025/11/12 11:35:43 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>

typedef struct s_lines
{
	char	*line;
	char	*remainder;
}	t_lines;
t_lines	ft_zeroed(void);
t_lines	ft_return_lines(char *s, size_t n);
char	*invalid_n(char **lines, char **temp, ssize_t n);
char	*return_something(char c);
char	*get_next_line(int fd);
int		ft_n_or_l(const char *s, char c);
char	*ft_strdup(const char *s);
char	*ft_concatenate(char *file_content, char *buffer);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
