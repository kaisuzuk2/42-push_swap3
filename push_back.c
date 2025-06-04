/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:07:04 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/04 23:13:02 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_a_rotate(t_stack *stk_a)
{
	int	max;
	int	mid;

	max = get_max_node_index(stk_a);
	mid = stk_a->size / 2;
	if (max > mid)
	{
		while (max--)
			reverse_rotate_a(stk_a);
	}
	else
	{
		while (max--)
			rotate_a(stk_a);
	}
}

static void	push_back_check(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*stk_a_tail;
	t_node	*stk_b_top;

	stk_a_tail = stk_a->dummy_node->prev;
	stk_b_top = stk_b->dummy_node->next;
	if (stk_b_top == stk_b->dummy_node)
		return ;
	if (stk_b_top->rank < stk_a_tail->rank)
		reverse_rotate_a(stk_a);
}

void	push_back(t_stack *stk_a, t_stack *stk_b)
{
	while (stk_b->size)
	{
		push_back_check(stk_a, stk_b);
		push_a(stk_a, stk_b);
	}
	stack_a_rotate(stk_a);
}