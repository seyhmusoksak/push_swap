/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:27:28 by soksak            #+#    #+#             */
/*   Updated: 2024/02/22 00:33:48 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "Libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				content;
	int				isrr;
	int				cost;
	struct s_stack	*next;
	struct s_stack	*target_node;
}					t_stack;



int		ft_atoi(const char *str);
void	arg_check(int ac, char **argv);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	print_error(void);
int		space_check(char *str);
void	free_split(char **split);
int		my_atoi(const char *str);
void	ft_fill_stack(char **argv, t_stack **a);
int is_sorted(t_stack **stack);
char	**arg_join(char **argv);
char	*my_strjoin(char *s1, char *s2);


# endif
