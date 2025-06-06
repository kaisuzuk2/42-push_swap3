/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:09:07 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/05 22:41:06 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_total_cost(t_cost *cst)
{
	return (cst->rr + cst->rrr + cst->ra + cst->rb + cst->rra + cst->rrb);
}

static void	cost_init(t_cost *cst)
{
	cst->rr = 0;
	cst->rrr = 0;
	cst->ra = 0;
	cst->rb = 0;
	cst->rra = 0;
	cst->rrb = 0;
}

static void	calc_b_cost(t_cost *cst, t_stack *stk_b, int rank)
{
	t_node	*max;
	t_node	*min;
	t_node	*cur;
	int		i;

	if (stk_b->size == 0)
		return ;
	cur = stk_b->dummy_node->next;
	max = get_max_node(stk_b);
	min = get_min_node(stk_b);
	i = 1;
	if (rank > max->rank)
	{
		cst->rb = get_max_node_index(stk_b);
		cst->rrb = stk_b->size - get_max_node_index(stk_b);
	}
	else if (rank < min->rank)
	{
		cst->rb = get_min_node_index(stk_b);
		cst->rrb = stk_b->size - get_min_node_index(stk_b);
	}
	else
	{
		while (cur != stk_b->dummy_node)
		{
			if (cur->rank > rank && cur->next->rank < rank)
				break;
			i++;
			cur = cur->next;
		}
		cst->rb = i;
		cst->rrb = stk_b->size - i;
	}
}

static void	calc_optimization(t_cost *cst)
{
	if ((cst->ra + cst->rb) <= (cst->rra + cst->rrb))
	{
		cst->rra = 0;
		cst->rrb = 0;
	}
	else
	{
		cst->ra = 0;
		cst->rb = 0;
	}
	while (cst->ra && cst->rb)
	{
		cst->ra--;
		cst->rb--;
		cst->rr++;
	}
	while (cst->rra && cst->rrb)
	{
		cst->rra--;
		cst->rrb--;
		cst->rrr++;
	}
}

t_cost	*calc_cost(t_stack *stk_a, t_stack *stk_b)
{
	t_cost	*best_cst;
	t_cost	*cur_cst;
	t_node	*dummy_node;
	t_node	*cur_node;
	int		i;

	best_cst = NULL;
	i = 0;
	dummy_node = stk_a->dummy_node;
	cur_node = dummy_node->next;
	while (cur_node != dummy_node)
	{
		cur_cst = (t_cost *)malloc(sizeof(t_cost));
		cost_init(cur_cst);
		calc_b_cost(cur_cst, stk_b, cur_node->rank);
		cur_cst->ra = i;
		cur_cst->rra = stk_a->size - i;
		calc_optimization(cur_cst);
		if (!best_cst || get_total_cost(cur_cst) < get_total_cost(best_cst))
		{
			if (best_cst)
				free(best_cst);
			best_cst = (t_cost *)malloc(sizeof(t_cost));
			if (!best_cst) 
				return (NULL);
			*best_cst = *cur_cst;
		}
		free(cur_cst);
		i++;
		cur_node = cur_node->next;
	}
	// ft_printf("### best_cst\n");
	// ft_printf("rr = %d / rrr = %d / ra = %d / rb = %d / rra = %d / rrb = %d\n", best_cst->rr, best_cst->rrr, best_cst->ra, best_cst->rb, best_cst->rra, best_cst->rrb);
	return (best_cst);
}
