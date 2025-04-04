/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:51:49 by polmo-lo          #+#    #+#             */
/*   Updated: 2024/06/06 21:23:13 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (f)(unsigned int, char))
{
	int		i;
	char	*x;

	i = 0;
	x = malloc(ft_strlen(s) + 1);
	if (!x)
		return (NULL);
	while (s[i] != '\0')
	{
		x[i] = f(i, s[i]);
		i++;
	}
	x[i] = '\0';
	return (x);
}
