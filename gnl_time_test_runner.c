/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_time_test_runner.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:12:57 by nastamid          #+#    #+#             */
/*   Updated: 2024/11/20 16:16:44 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		lines;
	double	time_taken;

	clock_t start_time, end_time;
	lines = 1;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	start_time = clock();
	while ((line = get_next_line(fd)))
	{
		printf("%d->%s", lines++, line);
		free(line);
	}
	end_time = clock();
	time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("\nTime taken: %.6f seconds\n", time_taken);
	close(fd);
	return (0);
}
