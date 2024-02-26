/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:27:28 by soksak            #+#    #+#             */
/*   Updated: 2024/02/26 05:32:14 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				content;
	int				isrr;
	int				cost;
	struct s_stack	*next;
	struct s_stack	*target_node;
}					t_stack;

void	arg_check(int ac, char **argv);
char	**ft_split(char const *s, char c);
void	print_error(void);
int		my_atoi(const char *str);
void	ft_fill_stack(char **argv, t_stack **a);
int		is_sorted(t_stack **stack);
char	**arg_join(char **argv);
char	*my_strjoin(char *s1, char *s2);
void	reindex(t_stack *stack);
t_stack	*ft_stacklast(t_stack *stack);
void	sort_min(t_stack **a, t_stack **b, int max_index);
int		get_thesmallest(t_stack **stack);
int		get_thelargest(t_stack **stack);
t_stack	*nodeofindex(int index, t_stack **stack);
void	setrr(t_stack **stack);
void	setcost(t_stack **a, t_stack **b);
void	gettarget(t_stack **a, t_stack **b);
t_stack	*get_themincost(t_stack **a);
void	sort_it(t_stack **a, t_stack **b);
void	free_stack(t_stack **a, t_stack **b);

//Movements
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
