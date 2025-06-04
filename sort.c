/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:08:32 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/04 22:46:47 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_sort(t_stack *stk_a, t_stack *stk_b)
{
	t_cost	*cst;

	cst = calc_cost(stk_a, stk_b);
	if (!cst)
		return ; // malloc失敗時のエラー処理必要
	while (cst->rr)
		(rotate_both(stk_a, stk_b), cst->rr--);
	while (cst->rrr)
		(reverse_rotate_both(stk_a, stk_b), cst->rrr--);
	while (cst->ra)
		(rotate_a(stk_a), cst->ra--);
	while (cst->rb)
		(rotate_b(stk_b), cst->rb--);
	while (cst->rra)
		(reverse_rotate_a(stk_a), cst->rra--);
	while (cst->rrb)
		(reverse_rotate_b(stk_b), cst->rrb--);
	free(cst);
}

void	sort(t_stack *stk_a, t_stack *stk_b)
{
	while (stk_a->size > 5)
	{
		do_sort(stk_a, stk_b);
		push_b(stk_b, stk_a);
	}
	sort_five(stk_a, stk_b);
	push_back(stk_a, stk_b);
}