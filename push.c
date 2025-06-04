/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:49:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/03 22:59:11 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *to_stack, t_stack *from_stack, char *op)
{
	t_node *node;
	t_node *top;
	t_node *from_dummy_node;
	t_node *to_dummy_node;

	from_dummy_node = from_stack->dummy_node;
	to_dummy_node = to_stack->dummy_node;
	node = from_dummy_node->next;
	top = to_dummy_node->next;
	if (node == from_dummy_node)
		return ;
	from_dummy_node->next = node->next;
	node->next->prev = from_dummy_node;
	from_stack->size--;
	if (top == to_dummy_node)
	{
		to_dummy_node->next = node;
		to_dummy_node->prev = node;
		node->prev = to_dummy_node;
		node->next = to_dummy_node;
		ft_printf("%s", op);
		return ;
	}
	node->prev = to_dummy_node;
	node->next = top;
	top->prev = node;
	to_dummy_node->next = node;
	to_stack->size++;
	ft_printf("%s", op);
}