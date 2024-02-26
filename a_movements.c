/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_movements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:20:02 by soksak            #+#    #+#             */
/*   Updated: 2024/02/25 19:22:38 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int print)
{
	int	tmp;
	int	tmp2;

	if ((*a)->next == NULL)
		return ;
	tmp = (*a)->content;
	tmp2 = (*a)->next->content;
	(*a)->content = tmp2;
	(*a)->next->content = tmp;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	ra(t_stack **a, int print)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	ft_stacklast((*a))->next = (*a);
	(*a)->next = NULL;
	(*a) = tmp;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rra(t_stack **a, int print)
{
	t_stack	*tmp;
	int		lastindex;

	tmp = ft_stacklast((*a));
	lastindex = ft_stacklast((*a))->index;
	ft_stacklast((*a))->next = *a;
	while ((*a))
	{
		if ((*a)->index == lastindex - 1)
		{
			(*a)->next = NULL;
			break ;
		}
		(*a) = (*a)->next;
	}
	(*a) = tmp;
	if (print)
		ft_putstr_fd("rra\n", 1);
}
