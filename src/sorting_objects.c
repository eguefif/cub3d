/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:10:52 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/19 10:29:08 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_list	*partition(t_list *first, t_list *last);

void	sort_objects_by_distance(t_list *first, t_list *last)
{
	t_list	*pivot;

	if (first == last)
		return ;
	pivot = partition(first, last);
	if (pivot != NULL && pivot->next != NULL)
		sort_objects_by_distance(pivot->next, last);
	if (pivot != NULL && first != pivot)
		sort_objects_by_distance(first, pivot);
}

static t_list	*partition(t_list *first, t_list *last)
{
	t_list		*pivot;
	t_list		*front;
	t_object	*temp;

	pivot = first;
	front = first;
	while (front != NULL && front != last)
	{
		if (front->object->distance > last->object->distance)
		{
			pivot = first;
			temp = first->object;
			first->object = front->object;
			front->object = temp;
			first = first->next;
		}
		front = front->next;
	}
	temp = first->object;
	first->object = last->object;
	last->object = temp;
	return (pivot);
}

t_list	*last_node(t_list *head)
{
	t_list	*last;

	last = head;
	while (last != NULL && last->next != NULL)
		last = last->next;
	return (last);
}
