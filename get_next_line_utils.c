/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekulow <dekulow@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:43:02 by dekulow           #+#    #+#             */
/*   Updated: 2024/01/31 13:43:02 by dekulow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr != '\0')
		ptr++;
	return ((size_t)(ptr - s));
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (c % 256))
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*cs1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cs1 = (char *)s1;
	if (!s1)
	{
		cs1 = (char *)malloc(sizeof(char) * 1);
		cs1[0] = '\0';
	}
	dst = (char *)malloc(sizeof(char) * (ft_strlen(cs1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (cs1[i] != '\0')
	{
		dst[i] = cs1[i];
		i++;
	}
	while (s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[ft_strlen(cs1) + ft_strlen(s2)] = '\0';
	return (free(cs1), dst);
}
