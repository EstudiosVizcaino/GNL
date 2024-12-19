/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:49:54 by cvizcain          #+#    #+#             */
/*   Updated: 2024/12/19 20:50:39 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *static_str, int fd, char *str)
{
	int		n_chars;
	char	*temp;

	n_chars = 1;
	while (n_chars > 0)
	{
		n_chars = read(fd, str, BUFFER_SIZE);
		if (n_chars < 0)
			return (free(str), free(static_str), NULL);
		str[n_chars] = '\0';
		if (!static_str)
		{
			static_str = ft_strdup("");
			if (!static_str)
				return (free(str), NULL);
		}
		temp = static_str;
		static_str = ft_strjoin(static_str, str);
		if (!static_str)
			return (free (str), NULL);
		free(temp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (free(str), static_str);
}

static char	*get_line(char *statica)
{
	char	*line;
	int		len;

	len = 0;
	if (!statica || !statica[len])
		return (NULL);
	while (statica[len] && statica[len] != '\n')
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
static char	*delete_line(char *statica)
{
	char	*remaining_text;
	int		len;

	len = 0;
	if (!statica || !statica[len])
	{
		free (statica);
		return (NULL);
	}
	while (statica[len] && statica[len] != '\n')
		len++;
	if (statica[len] == '\n')
		len++;
	remaining_text = ft_substr(statica, len, ft_strlen(statica) - len);
	if (!remaining_text)
		return (free(statica), NULL);
	free(statica);
	return (remaining_text);
}

/// @brief Returns the next line from a file descriptor.
/// @param fd The file descriptor to read from.
/// @return A dynamically allocated string containing the next line, 
/// or NULL if no more lines.
char	*get_next_line(int fd)
{
	static char	*static_string = 0;
	char		*line;
	char		*str;

	line = NULL;
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	static_string = ft_read(static_string, fd, str);
	if (!static_string)
		return (NULL);
	line = get_line(static_string);
	if (!line)
		return (NULL);
	static_string = delete_line(static_string);
	return (line);
}
