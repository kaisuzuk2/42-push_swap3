/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:55:24 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/03 22:02:54 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *char_to_int(char **argv, int size)
{
	int i;
	int *res;
	long tmp;
	
	res = malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	i = 1;
	while (i < size)
	{
		tmp = ft_atol(argv[i]);
		if (!(tmp >= INT_MIN && tmp <= INT_MAX))
			return (free(res), NULL);
		res[i - 1] = tmp;	
		i++;
	}
	return (res);
}





#include <stdio.h>
int main(int argc, char **argv)
{
	t_stack *stk_a;
	t_stack *stk_b;
	int *arr;
	
	if (ft_is_digit(argv, argc))
		return (ft_printf(ERROR), 0);
	arr = char_to_int(argv, argc);
	if (!arr)
		return (0);
	if (ft_is_sort(arr, argc - 1))
		return (0);
	stk_a = stack_utils(arr, argc - 1);
	stk_b = make_stack();
	if (!stk_b)
		return (0);


	if (stk_a->size <= 3)
		sort_three(stk_a);
	else if (stk_a->size <= 5)
		sort_five(stk_a, stk_b);
	
	t_node *dummy_node = stk_a->dummy_node;
	t_node *cur = dummy_node->next;
	while (cur != dummy_node)
	{
		printf("%d ", cur->rank);
		cur = cur->next;
	}
}