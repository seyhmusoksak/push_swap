/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:29:25 by soksak            #+#    #+#             */
/*   Updated: 2024/02/25 19:21:30 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	single_rotate(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->isrr == 1 && node->cost)
	{
		rra(a, 1);
		node->cost--;
	}
	while (node->target_node->isrr == 1 && node->target_node->cost)
	{
		rrb(b, 1);
		node->target_node->cost--;
	}
	while (node->isrr == 0 && node->cost)
	{
		ra(a, 1);
		node->cost--;
	}
	while (node->target_node->isrr == 0 && node->target_node->cost)
	{
		rb(b, 1);
		node->target_node->cost--;
	}
}

static void	rotate(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost && node->target_node->cost)
	{
		rr(a, b);
		node->cost--;
		node->target_node->cost--;
	}
	while (node->cost)
	{
		ra(a, 1);
		node->cost--;
	}
	while (node->target_node->cost)
	{
		rb(b, 1);
		node->target_node->cost--;
	}
}

static void	rev_rotate(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost && node->target_node->cost)
	{
		rrr(a, b);
		node->cost--;
		node->target_node->cost--;
	}
	while (node->cost)
	{
		rra(a, 1);
		node->cost--;
	}
	while (node->target_node->cost)
	{
		rrb(b, 1);
		node->target_node->cost--;
	}
}

void	finish_sort(t_stack **a, t_stack **b)
{
	while (nodeofindex(get_thelargest(b), b)->cost)
	{
		if (nodeofindex(get_thelargest(b), b)->isrr == 1)
			rrb(b, 1);
		else
			rb(b, 1);
		nodeofindex(get_thelargest(b), b)->cost--;
	}
	while (*b)
		pa(a, b);
}

void	sort_it(t_stack **a, t_stack **b)
{
	t_stack	*node;

	pb(a, b);
	pb(a, b);
	while (*a)
	{
		gettarget(a, b);
		node = get_themincost(a);
		if (node->isrr != node->target_node->isrr)
			single_rotate(a, b, node);
		else if (node->isrr == node->target_node->isrr)
		{
			if (node->isrr == 0)
				rotate(a, b, node);
			else
				rev_rotate(a, b, node);
		}
		pb(a, b);
	}
	finish_sort(a, b);
}
