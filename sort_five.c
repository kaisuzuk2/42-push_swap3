/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:28:40 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/04 22:47:58 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *stk_a, t_stack *stk_b)
{
	int max;
	int counter;

	counter = stk_a->size - 3;
	if (counter < 0)
		return ;
	while (stk_a->size > 3)
	{
		max = get_max_node_index(stk_a);
		if (max <= 3)
		{
			while (max--)
				rotate_a(stk_a);
		}
		else
		{
			max = stk_a->size - max;
			while (max--)
				reverse_rotate_a(stk_a);
		}
		push_b(stk_b, stk_a);
	}
	sort_three(stk_a);
	while (counter--)
	{
		push_a(stk_a, stk_b);
		rotate_a(stk_a);
	}
}