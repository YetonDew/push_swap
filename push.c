/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeffers <ajeffers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:30:00 by ajeffers          #+#    #+#             */
/*   Updated: 2026/02/16 13:10:40 by ajeffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **src, t_stack **dst)
{
	t_stack	*node;

	if (!src || !*src)
		return (0);
	node = *src;
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	node->next = *dst;
	if (*dst)
		(*dst)->prev = node;
	*dst = node;
	return (1);
}

void	pa(t_stack **a, t_stack **b)
{
	if (push(b, a))
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (push(a, b))
		write(1, "pb\n", 3);
}
