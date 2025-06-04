/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:28:40 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/03 22:59:32 by kaisuzuk         ###   ########.fr       */
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
		max = max_node(stk_a);
		if (max <= 3)
		{
			while (max--)
				rotate(stk_a, ROTATE_A);
		}
		else
		{
			max = stk_a->size - max;
			while (max--)
				reverse_rotate(stk_a, REVERSE_ROTATE_A);
		}
		push(stk_b, stk_a, PUSH_B);
	}
	sort_three(stk_a);
	while (counter--)
	{
		push(stk_a, stk_b, PUSH_A);
		rotate(stk_a, ROTATE_A);
	}
}