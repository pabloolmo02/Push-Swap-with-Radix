/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabloolmo <pabloolmo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:37:31 by polmo-lo          #+#    #+#             */
/*   Updated: 2024/06/07 15:21:28 by pabloolmo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*string;
	int		i;

	i = 0;
	string = (char *)malloc(sizeof(char) * ft_strlen(s1)+1);
	if (!string)
		return (NULL);
	while (s1[i] != 0)
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = 0;
	return (string);
}
