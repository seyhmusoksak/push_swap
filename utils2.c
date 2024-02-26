/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:50:32 by soksak            #+#    #+#             */
/*   Updated: 2024/02/26 05:16:59 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reindex(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

int	get_thesmallest(t_stack **stack)
{
	t_stack	*tmp;
	int		smallest;
	int		index;

	tmp = *stack;
	smallest = tmp->content;
	index = tmp->index;
	while (tmp)
	{
		if (tmp->content < smallest)
		{
			smallest = tmp->content;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	get_thelargest(t_stack **stack)
{
	t_stack	*tmp;
	int		largest;
	int		index;

	tmp = *stack;
	largest = tmp->content;
	index = tmp->index;
	while (tmp)
	{
		if (tmp->content > largest)
		{
			largest = tmp->content;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	while (*b)
	{
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
	free(*a);
	free(*b);
}
