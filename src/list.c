/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:35:54 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/15 19:41:52 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*init_list(void)
{
	t_list	*head;

	head = (t_list *) malloc(sizeof(t_list));
	head->object = NULL;
	head->next = NULL;
	return (head);
}

void	append_to_list(t_object *obj, t_list **head)
{
	t_list	*new_node;
	t_list	*current;

	new_node = (t_list*) malloc(sizeof(t_list));
	new_node->object = obj;
	new_node->next = NULL;
	current = *head;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

void	destroy_list(t_list	*head)
{
	t_list	*temp;

	while (head)
	{
		temp = head;
		head = temp->next;
		if (!temp->object)
			free(temp->object);
		free(temp);
	}
}
