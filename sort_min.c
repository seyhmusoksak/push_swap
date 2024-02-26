/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:50:32 by soksak            #+#    #+#             */
/*   Updated: 2024/02/26 05:20:28 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	threesort(t_stack **a)
{
	if (is_sorted(a))
		return ;
	if ((*a)->content < (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
	{
		ra(a, 1);
		sa(a, 1);
		reindex(*a);
		rra(a, 1);
	}
	else if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->next->content > (*a)->next->next->content)
		{
			sa(a, 1);
			rra(a, 1);
		}
		else if ((*a)->content < (*a)->next->next->content)
			sa(a, 1);
		else if ((*a)->content > (*a)->next->next->content)
			ra(a, 1);
	}
	else
		rra(a, 1);
}

static void	sortfour(t_stack **a, t_stack **b, int smallest)
{
	if (is_sorted(a))
		return ;
	if (smallest > ft_stacklast(*a)->index / 2)
	{
		smallest = ft_stacklast(*a)->index - smallest + 1;
		while (smallest)
		{
			rra(a, 1);
			smallest--;
		}
	}
	else
	{
		while (smallest)
		{
			ra(a, 1);
			smallest--;
		}
	}
	pb(a, b);
	threesort(a);
	pa(a, b);
}

static void	sortfive(t_stack **a, t_stack **b, int smallest)
{
	if (smallest > 3)
	{
		while (smallest++ < ft_stacklast((*a))->index + 1)
			rra(a, 1);
	}
	else
	{
		while (smallest)
		{
			ra(a, 1);
			smallest--;
		}
	}
	pb(a, b);
	sortfour(a, b, get_thesmallest(a));
	pa(a, b);
}

void	sort_min(t_stack **a, t_stack **b, int max_index)
{
	if (max_index == 1)
		sa(a, 1);
	else if (max_index == 2)
		threesort(a);
	else if (max_index == 3)
		sortfour(a, b, get_thesmallest(a));
	else if (max_index == 4)
		sortfive(a, b, get_thesmallest(a));
	free_stack(a, b);
}
