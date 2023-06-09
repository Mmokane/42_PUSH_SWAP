/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:06:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/04/18 13:01:05 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 5
#endif

char	*ft_remains(char *line)
{
	char	*str;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	str = ft_substr(line, (i + 1), ft_strlen(line));
	free (line);
	line = NULL;
	return (str);
}

char	*ft_ret_line(char **line)
{
	int	i;

	i = 0;
	if (line[0][i] == '\0')
	{
		free (*line);
		*line = NULL;
		return (NULL);
	}
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	return (ft_substr(*line, 0, (i + 1)));
}

char	*ft_read_line(int fd, char *line)
{
	char	*str;
	ssize_t	i;

	i = 1;
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (0);
	if (!line)
		line = ft_strdup("");
	while (ft_strchr(line) == 0 && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free (str);
			free (line);
			line = NULL;
			return (NULL);
		}
		str[i] = '\0';
		line = ft_strjoin(line, str);
	}
	free (str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, line);
	if (line == NULL)
		return (NULL);
	str = ft_ret_line(&line);
	if (str == NULL)
		return (NULL);
	line = ft_remains(line);
	return (str);
}
