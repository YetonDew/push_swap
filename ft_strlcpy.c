/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeffers <ajeffers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:41:13 by ajeffers          #+#    #+#             */
/*   Updated: 2025/10/01 17:56:25 by ajeffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	copylen;

	srclen = ft_strlen(src);
	if (size > 0)
	{
		if (srclen >= size)
			copylen = size - 1;
		else
			copylen = srclen;
		ft_memmove(dst, src, copylen);
		dst[copylen] = '\0';
	}
	return (srclen);
}
