/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabloolmo <pabloolmo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:52:50 by pabloolmo         #+#    #+#             */
/*   Updated: 2025/04/04 12:52:54 by pabloolmo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	cleanup_and_exit(t_stack_data *data, char *err_msg)
{
	if (err_msg)
		write(2, err_msg, ft_strlen(err_msg));
	if (data != NULL)
	{
		if (data->stack_a != NULL)
			free(data->stack_a);
		if (data->stack_b != NULL)
			free(data->stack_b);
		if (data->combined_args != NULL)
			free(data->combined_args);
		if (data != NULL)
			free(data);
	}
	exit(1);
}

void	check_input_args(int arg_count, char **arg_values)
{
	int	i;
	int	k;

	i = 0;
	if (arg_count < 2)
		cleanup_and_exit(NULL, "");
	while (++i < arg_count)
	{
		k = 0;
		if (!arg_values[i][0] || (arg_values[i][0] && arg_values[i][0] == ' '))
			cleanup_and_exit(NULL, "Error\n");
		while (arg_values[i][k] != '\0')
		{
			if ((!(ft_isdigit(arg_values[i][k])) && (arg_values[i][k] != ' ')
			&& (arg_values[i][k] != '-' && arg_values[i][k] != '+' && arg_values[i][k] != ' '))
			|| (arg_values[i][k] == '-' && arg_values[i][k + 1] == '\0')
			|| (arg_values[i][k] == '+' && arg_values[i][k + 1] == '\0')
			|| (arg_values[i][k] == '-' && arg_values[i][k + 1] == ' ')
			|| (arg_values[i][k] == '+' && arg_values[i][k + 1] == ' '))
				cleanup_and_exit(NULL, "Error\n");
			k++;
		}
	}
}

void	combine_arguments(int arg_count, char **arg_values, t_stack_data *data)
{
	char	*temp;
	char	*temp2;
	int		i;

	i = 0;
	temp2 = ft_strdup("");
	while (++i < arg_count && arg_values[i] != NULL)
	{
		temp = ft_strjoin(temp2, arg_values[i]);
		if (temp2)
			free(temp2);
		if (i != arg_count - 1)
		{
			temp2 = ft_strjoin(temp, " ");
			if (temp)
				free(temp);
			temp = temp2;
		}
	}
	data->combined_args = ft_strdup(temp);
	if (data->combined_args == NULL)
		cleanup_and_exit(data, "Error\n");
	if (temp)
		free(temp);
}