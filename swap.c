/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:48:58 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/03 18:48:59 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stk)
{
	t_node *top;
	t_node *new_top;
	t_node *dummy_node;

	dummy_node = stk->node;
	top = dummy_node->next;
	new_top = dummy_node->next;
	if (top == stk || new_top == stk)
		return ;
	stk->next = new_top;
	new_top->prev = stk;
	top->prev = new_top;
	top->next = new_top->next;
	new_top->next->prev = top;
	new_top->next = top;
}