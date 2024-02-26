/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_movements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:54:41 by soksak            #+#    #+#             */
/*   Updated: 2024/02/25 13:01:52 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b, int print)
{
	int	tmp;
	int	tmp2;

	if ((*b)->next == NULL)
		return ;
	tmp = (*b)->content;
	tmp2 = (*b)->next->content;
	(*b)->content = tmp2;
	(*b)->next->content = tmp;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	rb(t_stack **b, int print)
{
	t_stack	*tmp;

	tmp = (*b)->next;
	ft_stacklast((*b))->next = (*b);
	(*b)->next = NULL;
	(*b) = tmp;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stack **b, int print)
{
	t_stack	*tmp;
	int		lastindex;

	tmp = ft_stacklast((*b));
	lastindex = ft_stacklast((*b))->index;
	ft_stacklast((*b))->next = *b;
	while ((*b))
	{
		if ((*b)->index == lastindex - 1)
		{
			(*b)->next = NULL;
			break ;
		}
		(*b) = (*b)->next;
	}
	(*b) = tmp;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}
