/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabloolmo <pabloolmo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:44:56 by pabloolmo         #+#    #+#             */
/*   Updated: 2025/03/24 17:55:42 by pabloolmo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_sorted_or_duplicates(t_stack_data *data, int flag)
{
	int	j;

	j = 0;
	if (flag == 0)
	{
		while (flag < data->size_a)
		{
			j = flag + 1;
			while (j < data->size_a)
			{
				if (data->stack_a[flag] == data->stack_a[j])
					cleanup_and_exit(data, "Error\n");
				j++;
			}
			flag++;
		}
	}
	if (is_stack_sorted(data))
		cleanup_and_exit(data, NULL);
}

void	process_numbers(t_stack_data *data)
{
	char	**split_values;
	int		i;
	int		pos;

	pos = 0;
	split_values = ft_split(data->combined_args, ' ');
	i = 0;
	while (split_values[i] != NULL && split_values[i][0] != '\0')
	{
		data->stack_a[pos++] = convert_to_long(split_values[i++], data);
		free(split_values[i - 1]);
	}
	free(split_values);
}

void	init_stacks(int arg_count, char **arg_values, t_stack_data *data)
{
	int	i;

	i = 0;
	data->size_a = 0;
	data->size_b = 0;
	while (--arg_count)
	{
		if (ft_count_words(arg_values[i + 1], ' '))
			data->size_a += ft_count_words(arg_values[i + 1], ' ');
		else
			data->size_a++;
		i++;
	}
	data->stack_a = malloc(data->size_a * sizeof * data->stack_a);
	if (data->stack_a == NULL)
		cleanup_and_exit(data, "Error\n");
	data->stack_b = malloc(data->size_a * sizeof * data->stack_b);
	if (data->stack_b == NULL)
		cleanup_and_exit(data, "Error\n");
}

void	generate_indices(t_stack_data *data)
{
	int		i;
	int		j;
	int		k;
	int		*indexed_stack;

	indexed_stack = malloc(data->size_a * sizeof * indexed_stack);
	if (indexed_stack == NULL)
		cleanup_and_exit(data, "Error\n");
	i = -1;
	while (++i < data->size_a)
	{
		k = 0;
		j = -1;
		while (++j < data->size_a)
			if (data->stack_a[i] > data->stack_a[j])
				k++;
		indexed_stack[i] = k;
	}
	i = data->size_a;
	while (i--)
		data->stack_a[i] = indexed_stack[i];
	free(indexed_stack);
}

int	convert_to_long(const char *str, t_stack_data *data)
{
	int			i;
	long		sign;
	long long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (result > 2147483647 || (result * sign) < -2147483648 || ft_strlen(str) > 11)
			cleanup_and_exit(data, "Error\n");
		if (!(str[i] >= '0' && str[i] <= '9'))
			cleanup_and_exit(data, "Error\n");
		result = result * 10 + (str[i++] - '0');
	}
	return ((int)(result * sign));
}

int	ft_count_words(char const *s, char c)
{
	int	wordcount;

	wordcount = 0;
	while (*s)
	{
		if (*s != c)
		{
			wordcount++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (wordcount);
}