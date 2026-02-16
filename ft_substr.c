/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeffers <ajeffers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:07:49 by ajeffers          #+#    #+#             */
/*   Updated: 2026/02/16 13:10:40 by ajeffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	n;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub_str = (char *)malloc(sizeof(char) * 1);
		if (sub_str == NULL)
			return (NULL);
		sub_str[0] = '\0';
		return (sub_str);
	}
	n = min(len, ft_strlen(s + start));
	sub_str = (char *)malloc(sizeof(char) * (n + 1));
	if (sub_str == NULL)
		return (NULL);
	ft_strlcpy(sub_str, s + start, n + 1);
	return (sub_str);
}
