/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:49:01 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/03 18:49:02 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stk)
{
	t_node	*top;
	t_node	*tail;
	t_node	*new_top;
	t_node	*dummy_node;

	dummy_node = stk->node;
	top = dummy_node->next;
	tail = dummy_node->prev;
	new_top = top->next;
	if (new_top == stk || top == stk)
		return ;
	stk->next = new_top;
	new_top->prev = stk;
	tail->next = top;
	top->prev = tail;
	top->next = stk;
	stk->prev = top;
}

void	reverse_rotate(t_stack *stk)
{
	t_node *top;
	t_node *tail;
	t_node *new_tail;
	t_node *dummy_node;

	top = dummy_node->next;
	tail = dummy_node->prev;
	new_tail = tail->prev;
	if (new_tail == stk || tail == stk)
		return ;
	stk->next = tail;
	tail->prev = stk;

	tail->next = top;
	top->prev = tail;

	stk->prev = new_tail;
	new_tail->next = stk;
}