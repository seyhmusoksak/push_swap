/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:27:28 by soksak            #+#    #+#             */
/*   Updated: 2024/01/17 13:57:15 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"


typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;



void	arg_check(char **str);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);



# endif
