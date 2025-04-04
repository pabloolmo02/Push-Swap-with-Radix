/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabloolmo <pabloolmo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:44:04 by pabloolmo         #+#    #+#             */
/*   Updated: 2025/03/24 17:44:06 by pabloolmo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

void	sort_triple(t_stack_data *data)
{
	if (data->stack_a[2] != 2)
	{
		if (data->stack_a[0] == 2)
			stack_rotate(data->stack_a, data->size_a, "up", "a");
		else
			stack_rotate(data->stack_a, data->size_a, "down", "a");
	}
	if (data->stack_a[0] > data->stack_a[1])
		stack_swap("sa", data->stack_a, data->size_a);
}

void	sort_quadruple_quintuple(t_stack_data *data)
{
	while (data->size_b <= 1)
	{
		if (data->stack_a[0] == 0 || data->stack_a[0] == 1)
			stack_push("pb", data);
		else
			stack_rotate(data->stack_a, data->size_a, "up", "a");
	}
	if (data->stack_b[0] == 0)
		stack_swap("sb", data->stack_b, data->size_b);
	if (data->stack_a[2] != 4)
	{
		if (data->stack_a[0] == 4)
			stack_rotate(data->stack_a, data->size_a, "up", "a");
		else
			stack_rotate(data->stack_a, data->size_a, "down", "a");
	}
	if (data->stack_a[0] > data->stack_a[1])
		stack_swap("sa", data->stack_a, data->size_a);
	stack_push("pa", data);
	stack_push("pa", data);
}

int	is_stack_sorted(t_stack_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_a - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	radix_sort_stack_b(t_stack_data *data, int b_size, int bit_max, int bit_pos)
{
	while (b_size-- && bit_pos <= bit_max && !is_stack_sorted(data))
	{
		if (((data->stack_b[0] >> bit_pos) & 1) == 0)
			stack_rotate(data->stack_b, data->size_b, "up", "b");
		else
			stack_push("pa", data);
	}
	if (is_stack_sorted(data))
		while (data->size_b != 0)
			stack_push("pa", data);
}

void	sort_with_radix(t_stack_data *data)
{
	int	bit_pos;
	int	bit_max;
	int	size;

	bit_max = 0;
	size = data->size_a;
	while (size > 1 && ++bit_max)
		size /= 2;
	bit_pos = -1;
	while (++bit_pos <= bit_max)
	{
		size = data->size_a;
		while (size-- && !is_stack_sorted(data))
		{
			if (((data->stack_a[0] >> bit_pos) & 1) == 0)
				stack_push("pb", data);
			else
				stack_rotate(data->stack_a, data->size_a, "up", "a");
		}
		radix_sort_stack_b(data, data->size_b, bit_max, bit_pos + 1);
	}
	while (data->size_b != 0)
		stack_push("pa", data);
}