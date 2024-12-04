/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:56:48 by nastamid          #+#    #+#             */
/*   Updated: 2024/12/04 15:56:48 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

#include <stdio.h>
char *get_next_line(int fd)
{
    char k;

    if (fd < 0)
        return (NULL);
    
     while(k = read(fd, BUFFER_SIZE, sizeof(char)))
     {
        printf("%c\n", k);
     }



}

