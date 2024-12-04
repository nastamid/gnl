/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:56:48 by nastamid          #+#    #+#             */
/*   Updated: 2024/12/04 19:38:44 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	contains_new_line(char *str)
{
	if (!str || *str == '\0')
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

t_list	*get_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	buf_to_content(char *buf, char *content)
{
	int	i;

	if (buf == NULL || content == NULL)
		return (0);
	i = 0;
	while (buf[i])
	{
		content[i] = buf[i];
		i++;
	}
	content[i] = '\0';
	printf("content: %s \n", content);
	return (1);
}

int	create_node(t_list *list, char *buf)
{
	t_list	*last_node;
	t_list	*new_node;

	last_node = get_last_node(list);
	if (last_node == NULL)
	{
		list = malloc(sizeof(t_list));
		list->content = malloc(BUFFER_SIZE + 1);
		buf_to_content(buf, list->content);
		list->next = NULL;
	}
	new_node = malloc(sizeof(t_list));
	new_node->content = malloc(BUFFER_SIZE + 1);
	new_node->next = NULL;
	list->next = new_node;
	return (1);
}

char * get_combined_str(t_list *list)
{
	
}

char	*get_next_line(int fd)
{
	char			*buf;
	static t_list	*list;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE))
	{
		buf[BUFFER_SIZE] = '\0';
		create_node(list, buf);
	}
	return (NULL);
}
