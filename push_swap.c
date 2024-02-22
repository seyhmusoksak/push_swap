/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:48:22 by soksak            #+#    #+#             */
/*   Updated: 2024/02/22 00:48:00 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	char	**arg_ar;

	a = malloc(sizeof(t_stack *));
	if (argc >= 2)
	{
		arg_check(argc, argv);
		arg_ar = arg_join(argv);
		ft_fill_stack(arg_ar, a);
		if(is_sorted(a))
			exit(0);
	}
}
