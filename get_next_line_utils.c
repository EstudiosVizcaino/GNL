/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:55:02 by cvizcain          #+#    #+#             */
/*   Updated: 2024/11/14 11:10:52 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief f Locates the first occurrence of a character in a string.
///
/// This function searches for the first occurrence of the character `c` 
/// (converted to a `char`) in the string `s`. The function returns a pointer 
/// to the matched character within the string, or NULL if the character is 
/// not found.
///
/// If `c` is `\0` (the null terminator), the function returns a pointer to 
/// the terminator at the end of the string.
///
/// @param s The string to be searched.
/// @param c  The character to locate within the string.
/// @return A pointer to the first occurrence of `c` in `s`, or NULL if `c` 
/// is not found in `s`.
char	*ft_strchr(const char *s, int c)
{
	while (*s != (char) c && *s != '\0')
		++s;
	if (*s == (char)c)
		return ((char *) s);
	else
		return (NULL);
}

/// @brief Concatenates two strings into a new string.
/// This function creates a new string that is the result of concatenating 
/// the strings `s1` and `s2`. Memory for the new string is dynamically 
/// allocated and must be freed by the caller to avoid memory leaks.
///
/// If either `s1` or `s2` is NULL, the function returns NULL.
/// @param s1 The first string to be concatenated.
/// @param s2 The second string to be concatenated.
/// @return A pointer to the newly created concatenated string, or NULL 
/// if memory allocation fails or if either `s1` or `s2` is NULL.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1 && *s1)
		*(str + i++) = *s1++;
	while (s2 && *s2)
		*(str + i++) = *s2++;
	*(str + i) = '\0';
	return (str);
}

/// @brief Returns the lenght of the given string
/// @param s The string wanted to measure
/// @return Its lenght
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return 0;
	while (s[len])
		++len;
	return (len);
}

/// @brief Creates a substring from the given string.
///
/// This function extracts a substring from the input string `s`, starting from 
/// the specified `start` index and with a maximum length of `len` characters.
///
/// If the `start` index is beyond the length of `s`, the function returns 
/// an empty string. If `len` extends beyond the end of `s`, the function 
/// adjusts `len` to only include characters up to the end of `s`.
/// If `s` is NULL, the function returns NULL. The returned substring is 
/// dynamically allocated and must be freed by the caller to avoid memory leaks.
/// @param s The source string from which to create the substring.
/// @param start The starting index from where to begin the substring in `s`.
/// @param len The maximum length of the substring to extract.
/// @return A pointer to the newly allocated substring, or NULL if memory 
/// allocation fails or if `s` is NULL.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup("\0"));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (len)
	{
		*(str + i) = *(s + start + i);
		++i;
		len--;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
