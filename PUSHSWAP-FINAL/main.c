/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabloolmo <pabloolmo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:13:04 by pabloolmo         #+#    #+#             */
/*   Updated: 2025/04/04 12:53:30 by pabloolmo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int arg_count, char **arg_values)
{
	t_stack_data	*data;

	check_input_args(arg_count, arg_values);
	data = malloc(sizeof * data);
	if (data == NULL)
		exit(1);
	init_stacks(arg_count, arg_values, data);
	combine_arguments(arg_count, arg_values, data);
	process_numbers(data);
	check_sorted_or_duplicates(data, 0);
	generate_indices(data);
	if (data->size_a == 2 && data->stack_a[0] > data->stack_a[1])
		stack_swap("sa", data->stack_a, data->size_a);
	else if (data->size_a == 3)
		sort_triple(data);
	else if (data->size_a >= 4 && data->size_a <= 5)
		sort_quadruple_quintuple(data);
	else
		sort_with_radix(data);
	check_sorted_or_duplicates(data, 1);
	cleanup_and_exit(data, "Error\n");
	return (0);
}