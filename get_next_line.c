/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:49:54 by cvizcain          #+#    #+#             */
/*   Updated: 2024/09/18 17:53:49 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(char *s, int fd)
{
	char	*str;
	int		n_chars;

	str = malloc(sizeof(char) * BUFFER_SIZE);
	if (!str)
		return (NULL);
	n_chars = 1;
	while (n_chars > 0)
	{
		n_chars = read(fd, str, BUFFER_SIZE);
		if (n_chars < 0)
			return (free(str), free(s), NULL);
		
		
		if (ft_strchr(str, '\n'))
			break;
		
	}

	s = str;
	return (s);
}

char *get_next_line(int fd)
{
	static char *estatica = NULL;
	estatica = ft_read(estatica, fd);
	return (estatica);
}
//Actualmente solo imprime los últimos caracteres del fin de línea, buscar manera de concatenar e imprimir la cadena entera