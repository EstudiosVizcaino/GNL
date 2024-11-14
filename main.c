/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvizcain <cvizcain@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:08:29 by cvizcain          #+#    #+#             */
/*   Updated: 2024/11/14 12:31:00 by cvizcain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>  // for open
#include <stdio.h>


int	main (int argc, char **argv)
{
	int fd;
	char *line;

	line = "";
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
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	if (line == NULL)
        printf("\nEnd of file reached or error reading line.\n");
		
	close (fd);
	return (0);
}