/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeffers <ajeffers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:57:30 by ajeffers          #+#    #+#             */
/*   Updated: 2026/02/09 20:45:23 by ajeffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_len(t_stack *a)
{
	int counter;

	counter = 0;
	if (a == NULL)
		return (0);
	while (a)
	{
		counter++;
		a = a->next;
	}
	return (counter);
}

int swap(t_stack **a)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;

    if (!a || !*a || !(*a)->next)
		return (0);
	first = *a;
	second = first->next;
	third = second->next;
	*a = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if(third)
		third->prev = first;
	return (1);
}

