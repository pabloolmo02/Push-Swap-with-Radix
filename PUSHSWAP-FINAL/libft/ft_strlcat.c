/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:43:34 by polmo-lo          #+#    #+#             */
/*   Updated: 2024/04/29 15:20:24 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize )
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	if (destsize <= i)
		return (destsize + ft_strlen(src));
	while (src[j] && i + 1 < destsize)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i + ft_strlen(&src[j]));
}
