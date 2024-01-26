/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekulow <dekulow@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:23:51 by dekulow           #+#    #+#             */
/*   Updated: 2024/01/26 11:35:38 by dekulow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	byte_read;
	char		character;
	char		*line;
	int			index;

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	byte_read = 0;
	character = ' ';
	byte_read = read(fd, &character, 1);
	if (byte_read == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (free(line), NULL);
	while (byte_read > 0 && character != '\n')
	{
		line[index++] = character;
		byte_read = read(fd, &character, 1);
		if (index == BUFFER_SIZE + 1)
		{
			while (byte_read > 0 && character != '\n')
				byte_read = read(fd, &character, 1);
			return (line[index] = '\n', line);
		}
	}
	return (line);
}
