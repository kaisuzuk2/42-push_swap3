/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:49:01 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/03 19:49:42 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stk, char *op)
{
	t_node	*top;
	t_node	*tail;
	t_node	*new_top;
	t_node	*dummy_node;

	dummy_node = stk->dummy_node;
	top = dummy_node->next;
	tail = dummy_node->prev;
	new_top = top->next;
	if (new_top == dummy_node || top == dummy_node)
		return ;
	dummy_node->next = new_top;
	new_top->prev = dummy_node;
	tail->next = top;
	top->prev = tail;
	top->next = dummy_node;
	dummy_node->prev = top;
	ft_printf("%s", op);
}

void	reverse_rotate(t_stack *stk, char *op)
{
	t_node *top;
	t_node *tail;
	t_node *new_tail;
	t_node *dummy_node;

	dummy_node = stk->dummy_node;
	top = dummy_node->next;
	tail = dummy_node->prev;
	new_tail = tail->prev;
	if (new_tail == dummy_node || tail == dummy_node)
		return ;
	dummy_node->next = tail;
	tail->prev = dummy_node;

	tail->next = top;
	top->prev = tail;

	dummy_node->prev = new_tail;
	new_tail->next = dummy_node;
	ft_printf("%s", op);
}