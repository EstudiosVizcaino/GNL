/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:49:54 by cvizcain          #+#    #+#             */
/*   Updated: 2024/11/12 17:00:11 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *s, int fd, char *str)
{
	int		n_chars;
	char	*temp;

	n_chars = 1;
	while (n_chars > 0)
	{
		n_chars = read(fd, str, BUFFER_SIZE);
		if (n_chars < 0)
			return (free(str), free(s), NULL);
		str[n_chars] = '\0';
		if (!s)
		{
			s = ft_strdup("");
			if (!s)
				return (free(str), NULL);
		}
		temp = s;
		s = ft_strjoin(s, str);
		free(temp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (free(str), s);
}

char	*get_line(char *statica)
{
	char	*line;
	int		len;

	len = 0;
	if (!statica || !statica[len])
		return (NULL);
	while (statica[len] != '\n')
		len++;
	if (statica[len] == '\n')
		len++;
	line = ft_substr(statica, 0, len);
	return (line);
}

/// @brief Deletes the first line from statica and keeps the rest.
/// @param statica The input static string containing the remaining
/// file content.
/// @return A dynamically allocated string containing the remaining
/// content afterthe first line.
char	*delete_line(char *statica)
{
	char	*remaining_text;
	int		len;

	len = 0;
	if (!statica || !statica[len])
		return (NULL);
	while (statica[len] != '\n')
		len++;
	if (statica[len] == '\n')
		len++;
	remaining_text = ft_substr(statica, len, ft_strlen(statica) - len);
	free(statica);
	return (remaining_text);
}

/// @brief Returns the next line from a file descriptor.
/// @param fd The file descriptor to read from.
/// @return A dynamically allocated string containing the next line, 
/// or NULL if no more lines.
char	*get_next_line(int fd)
{
	static char	*static_string;
	char		*line;
	char		*str;

	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	static_string = ft_read(static_string, fd, str);
	line = get_line(static_string);
	static_string = delete_line(static_string);
	return (line);
}
