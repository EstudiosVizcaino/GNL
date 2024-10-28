/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:49:54 by cvizcain          #+#    #+#             */
/*   Updated: 2024/10/28 20:06:43 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char* ft_read(char *s, int fd) {
    char *str;
    int n_chars;
    char *temp;
    
    str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!str)
        return (NULL);
    n_chars = 1;
    while (n_chars > 0) {
        n_chars = read(fd, str, BUFFER_SIZE);
        if (n_chars < 0)
            return (free(str), free(s), NULL);
        str[n_chars] = '\0';
        temp = s;
        s = ft_strjoin(s, str); // Use a function that joins strings
        free(temp);
        if (ft_strchr(str, '\n'))
            break;
    }
    free(str);
    return (s);
}

char *get_line(char *statica)
{
    char *line;
    char *tmpstatic;
    int tmp;
    
    tmpstatic = ft_substr(statica, 0, tmp);

    line = 
}
/// @brief Deletes the first line from statica and keeps the rest.
/// @param statica The input static string containing the remaining file content.
/// @return A dynamically allocated string containing the remaining content after the first line.
char *delete_line(char *statica)
{
    int tmp;
    char *tmpstatic;

    tmp = ft_strchr(statica, '\n') - statica;
    tmpstatic = ft_substr(statica, tmp, ft_strlen(statica));
    free (statica);
    return tmpstatic;
}
/// @brief Returns the next line from a file descriptor.
/// @param fd The file descriptor to read from.
/// @return A dynamically allocated string containing the next line, or NULL if no more lines.
char* get_next_line(int fd) 
{
    static char *static_string;
    char *line;
    
    static_string = ft_read(static_string, fd);
    line = get_line(static_string);
    static_string = delete_line(static_string);
    return (line);
}

//Actualmente solo imprime los últimos caracteres del fin de línea, buscar manera de concatenar e imprimir la cadena entera