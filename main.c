/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:08:29 by cvizcain          #+#    #+#             */
/*   Updated: 2024/11/11 21:03:58 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>  // for open
#include <stdio.h>


int	main (int argc, char **argv)
{
	int fd;
	char *line;

	if (argc != 2)
	{
		printf("Usage: %s <file_name>\n", argv[0]);
        return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		{
			perror("Error opening file");
			return (1);
		}
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free (line);
	}

	if (line == NULL)
        printf("End of file reached or error reading line.\n");
		
	close (fd);
	return (0);
}