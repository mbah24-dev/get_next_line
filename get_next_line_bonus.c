/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:50:18 by mbah              #+#    #+#             */
/*   Updated: 2024/12/09 20:00:52 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	read_line_from_file(int fd, char **stash, char **temp_buffer)
{
	char	*buffer;
	int		readed;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return ;
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free_all(stash, temp_buffer, &buffer);
			return ;
		}
		buffer[readed] = '\0';
		*temp_buffer = ft_strdup(*stash);
		free_all(stash, 0, 0);
		*stash = ft_strjoin(*temp_buffer, buffer);
		free_all(temp_buffer, 0, 0);
		if (has_new_line(*stash))
			break ;
	}
	free_all(&buffer, 0, 0);
}

char	*parse_line_content(char **stash, char **line_data)
{
	char	*line;

	*line_data = ft_strdup(*stash);
	free_all(stash, 0, 0);
	*stash = extract_after_newline(*line_data);
	line = extract_before_newline(*line_data);
	free_all(line_data, 0, 0);
	return (line);
}

char	*extract_before_newline(const char *string)
{
	int		i;
	char	*res;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n' && string[i] != '\0')
		i++;
	res = ft_mcalloc((i + 1), sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		res[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
		res[i] = string[i];
	return (res);
}

char	*extract_after_newline(const char *string)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	j = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n' && string[i] != '\0')
		i++;
	while (string[j])
		j++;
	res = ft_mcalloc(((j - i) + 1), sizeof(char));
	j = 0;
	while (string[i + j])
	{
		res[j] = string[i + j];
		j++;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*temp_buf;
	char		*line;

	if ((fd < 0 || fd > 1023) || BUFFER_SIZE <= 0)
		return (NULL);
	temp_buf = NULL;
	line = NULL;
	read_line_from_file(fd, &stash[fd], &temp_buf);
	if (stash[fd] && *stash[fd] != '\0')
		line = parse_line_content(&stash[fd], &temp_buf);
	if (!line || *line == '\0')
	{
		free_all(&stash[fd], &temp_buf, &line);
		return (NULL);
	}
	return (line);
}
