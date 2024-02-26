/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:48:22 by soksak            #+#    #+#             */
/*   Updated: 2024/02/26 11:39:31 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	is_arg_only_space(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) || arg[i] == '-'
			|| arg[i] == '+')
			return (1);
		i++;
	}
	print_error();
	return (0);
}

static void	int_check(int ac, char **av)
{
	int	i;

	if (ac < 2)
		exit(0);
	i = 1;
	while (av[i])
	{
		my_atoi(av[i]);
		is_arg_only_space(av[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	char	**arg_ar;

	int_check(argc, argv);
	arg_check(argc, argv);
	b = malloc(sizeof(t_stack *));
	a = malloc(sizeof(t_stack *));
	arg_ar = arg_join(argv);
	ft_fill_stack(arg_ar, a);
	free_split(arg_ar);
	if (is_sorted(a))
	{
		free_stack(a, b);
		system("leaks push_swap");
		exit(0);
	}
	if (ft_stacklast(*a)->index < 5)
		sort_min(a, b, ft_stacklast(*a)->index);
	else
	{
		setrr(a);
		setcost(a, b);
		sort_it(a, b);
		free_stack(a, b);
	}
}
