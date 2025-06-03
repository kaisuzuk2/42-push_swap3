/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:58:01 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/03 19:58:27 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *stk_a)
{
	t_node *top;
	t_node *mid;
	t_node *tail;
	t_node *dummy_node;

	dummy_node = stk_a->dummy_node;
	top = dummy_node->next;
	mid = top->next;
	tail = mid->next;

	if (top->rank < mid->rank && mid->rank < tail->rank)
		return ;
	if (top->rank < mid->rank && mid->rank > tail->rank && top->rank < tail->rank) // 1 3 2 
		(reverse_rotate(stk_a, REVERSE_ROTATE_A), swap(stk_a, SWAP_A));
	else if (top->rank < mid->rank && mid->rank > tail->rank && top->rank > tail->rank) // 2 3 1
		reverse_rotate(stk_a, REVERSE_ROTATE_A);
	else if (top->rank > mid->rank && mid->rank > tail->rank) // 3 2 1
		(swap(stk_a, SWAP_A), reverse_rotate(stk_a, REVERSE_ROTATE_A));
	else if (top->rank > mid->rank && mid->rank < tail->rank && top->rank < tail->rank) // 2 1 3
		swap(stk_a, SWAP_A);
	else // 3 1 2
		rotate(stk_a, ROTATE_A);
}