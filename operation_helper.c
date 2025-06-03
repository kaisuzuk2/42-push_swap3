/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:32:13 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/03 22:15:34 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_node(t_stack *stk)
{
	t_node	*cur;
	t_node	*max;
	t_node	*dummy_node;
	int		i;

	dummy_node = stk->dummy_node;
	cur = dummy_node->next;
	max = cur;
	i = 0;
	while (cur != dummy_node)
	{
		if (cur->rank > max->rank)
			max = cur;
		cur = cur->next;
	}
	cur = dummy_node->next;
	while (cur != max)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

int	min_node(t_stack *stk)
{
	t_node *cur;
	t_node *min;
	t_node *dummy_node;
	int i;

	dummy_node = stk->dummy_node;
	cur = dummy_node->next;
	min = cur;
	i = 0;
	while (cur != dummy_node)
	{
		if (cur->rank < min->rank)
			min = cur;
		cur = cur->next;
	}
	cur = dummy_node;
	while (cur != min)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}