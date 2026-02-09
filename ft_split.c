/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeffers <ajeffers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:09:54 by ajeffers          #+#    #+#             */
/*   Updated: 2025/10/13 15:38:38 by ajeffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			counter++;
			while (*s && *s != c)
				s++;
		}
	}
	return (counter);
}

static void	free_split(char **res, size_t i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
}

static char	**logic(char **res, size_t *i, char const *s, char c)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (s[start])
	{
		while (s[start] == c)
			start++;
		if (!s[start])
			break ;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		res[*i] = ft_substr(s, start, end - start);
		if (!res[*i])
		{
			free_split(res, *i);
			return (NULL);
		}
		(*i)++;
		start = end;
	}
	res[*i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = count_words(s, c);
	res = (char **)malloc((count + 1) * (sizeof(char *)));
	if (res == NULL)
		return (NULL);
	i = 0;
	res = logic(res, &i, s, c);
	return (res);
}
