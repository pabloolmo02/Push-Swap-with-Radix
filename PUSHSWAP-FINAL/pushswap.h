/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabloolmo <pabloolmo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:56:32 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/03/24 18:03:14 by pabloolmo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSHSWAP_H
#define PUSHSWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 
#include <limits.h>

# include "./libft/libft.h"

typedef struct s_stack_data
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	char	*combined_args;
}	t_stack_data;

/* Main functions */
void	cleanup_and_exit(t_stack_data *data, char *err_msg);
void	check_input_args(int arg_count, char **arg_values);
void	combine_arguments(int arg_count, char **arg_values, t_stack_data *data);
void	process_numbers(t_stack_data *data);
void	init_stacks(int arg_count, char **arg_values, t_stack_data *data);

/* Sorting operations */
void	stack_swap(char *op, int *arr, int size);
void	stack_push(char *op, t_stack_data *data);
void	stack_rotate(int *arr, int size, char *dir, char *stack_name);

/* Sorting algorithms */
void	sort_triple(t_stack_data *data);
void	sort_quadruple_quintuple(t_stack_data *data);
void	sort_with_radix(t_stack_data *data);
int		is_stack_sorted(t_stack_data *data);

/* Utils functions */
void	check_sorted_or_duplicates(t_stack_data *data, int flag);
void	generate_indices(t_stack_data *data);
int		convert_to_long(const char *str, t_stack_data *data);
int	ft_count_words(char const *s, char c);



#endif 