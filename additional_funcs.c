/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:41:47 by soksak            #+#    #+#             */
/*   Updated: 2024/02/25 19:22:24 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setrr(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index <= ft_stacklast(*stack)->index / 2)
			tmp->isrr = 0;
		else
			tmp->isrr = 1;
		tmp = tmp->next;
	}
}

void	setcost(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *a;
	tmp2 = *b;
	while (tmp)
	{
		if (tmp->isrr == 0)
			tmp->cost = tmp->index;
		else
			tmp->cost = ft_stacklast(*a)->index - tmp->index + 1;
		tmp = tmp->next;
	}
	if (tmp2)
	{
		while (tmp2)
		{
			if (tmp2->isrr == 0)
				tmp2->cost = tmp2->index;
			else
				tmp2->cost = ft_stacklast(*b)->index - tmp2->index + 1;
			tmp2 = tmp2->next;
		}
	}
}

t_stack	*nodeofindex(int index, t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node)
	{
		if (node->index == index)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	gettarget(t_stack **a, t_stack **b)
{
	t_stack	*a_tmp;
	t_stack	*b_tmp;

	a_tmp = *a;
	b_tmp = *b;
	while (a_tmp)
	{
		a_tmp->target_node = nodeofindex(get_thesmallest(b), b);
		while (b_tmp)
		{
			if (a_tmp->content > b_tmp->content
				&& a_tmp->target_node->content < b_tmp->content)
				a_tmp->target_node = b_tmp;
			b_tmp = b_tmp->next;
		}
		if (a_tmp->target_node->content > a_tmp->content)
			a_tmp->target_node = nodeofindex(get_thelargest(b), b);
		b_tmp = *b;
		a_tmp = a_tmp->next;
	}
}

t_stack	*get_themincost(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*ret;

	tmp = *a;
	ret = tmp;
	while (tmp)
	{
		if (tmp->target_node->cost + tmp->cost
			< ret->target_node->cost + ret->cost)
			ret = tmp;
		else if (tmp->target_node->cost + tmp->cost
			== ret->target_node->cost + ret->cost)
		{
			if (tmp->target_node->isrr == ret->target_node->isrr
				&& ret->isrr != ret->target_node->isrr)
				ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}
