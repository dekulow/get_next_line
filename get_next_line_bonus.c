/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekulow <dekulow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:31:12 by dekulow           #+#    #+#             */
/*   Updated: 2024/02/14 17:31:14 by dekulow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line_content(const char *content)
{
	size_t	index;
	char	*read_line;

	index = 0;
	if (!content[index])
		return (NULL);
	while (content[index] != '\n' && content[index] != '\0')
		index++;
	read_line = (char *)malloc(sizeof(char) * (++index + 1));
	if (!read_line)
		return (NULL);
	index = 0;
	while (content[index] != '\n' && content[index] != '\0')
	{
		read_line[index] = content[index];
		index++;
	}
	if (content[index] == '\n')
	{
		read_line[index] = content[index];
		index++;
	}
	read_line[index] = '\0';
	return (read_line);
}

char	*ft_update_content(char *content)
{
	size_t	i;
	size_t	j;
	char	*new_content;

	i = 0;
	j = 0;
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	if (!content[i])
		return (free(content), NULL);
	new_content = (char *)malloc(sizeof(char) * ((ft_strlen(content) - i) + 1));
	if (!new_content)
		return (NULL);
	while (content[++i] != '\0')
		new_content[j++] = content[i];
	new_content[j] = '\0';
	return (free(content), new_content);
}

char	*ft_read_content(int fd, char *content)
{
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((ft_strchr(content, '\n') == NULL) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		content = ft_strjoin(content, buffer);
	}
	return (free(buffer), content);
}

char	*get_next_line(int fd)
{
	static char	*content[MAX_FD];
	char		*read_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	content[fd] = ft_read_content(fd, content[fd]);
	if (!content[fd])
		return (NULL);
	read_line = ft_read_line_content(content[fd]);
	content[fd] = ft_update_content(content[fd]);
	return (read_line);
}
