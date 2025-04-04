/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabloolmo <pabloolmo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:18:27 by pabloolmo         #+#    #+#             */
/*   Updated: 2025/03/24 17:42:52 by pabloolmo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_swap(char *op, int *arr, int size)
{
	int	temp_val;

	if (size <= 0)
		return;
	temp_val = arr[0];
	arr[0] = arr[1];
	arr[1] = temp_val;
	ft_putendl_fd(op, 1);
}

void	stack_push(char *op, t_stack_data *data)
{
	int	temp_val;

	if (ft_strncmp(op, "pa", 3) == 0)
	{
		if (data->size_b <= 0)
			return;
		temp_val = data->stack_b[0];
		ft_memmove(data->stack_a + 1, data->stack_a, sizeof(int) * data->size_a);
		data->stack_a[0] = temp_val;
		data->size_b--;
		ft_memmove(data->stack_b, data->stack_b + 1, sizeof(int) * data->size_b);
		data->size_a++;
	}
	else if (ft_strncmp(op, "pb", 3) == 0)
	{
		if (data->size_a <= 0)
			return;
		temp_val = data->stack_a[0];
		ft_memmove(data->stack_b + 1, data->stack_b, sizeof(int) * data->size_b);
		data->stack_b[0] = temp_val;
		data->size_a--;
		ft_memmove(data->stack_a, data->stack_a + 1, sizeof(int) * data->size_a);
		data->size_b++;
	}
	ft_putendl_fd(op, 1);
}

void	stack_rotate(int *arr, int size, char *dir, char *stack_name)
{
	int	temp_val;

	if (size < 0)
		return;
	if (ft_strncmp(dir, "up", 5) == 0)
	{
		temp_val = arr[0];
		ft_memmove(arr, arr + 1, sizeof(int) * (size - 1));
		arr[size - 1] = temp_val;
		write(1, "r", 1);
	}
	else if (ft_strncmp(dir, "down", 5) == 0)
	{
		temp_val = arr[size - 1];
		ft_memmove(arr + 1, arr, sizeof(int) * (size - 1));
		arr[0] = temp_val;
		write(1, "rr", 2);
	}
	ft_putendl_fd(stack_name, 1);
}