/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:20:48 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/17 19:11:31 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

/*
** DEF belows are used for option in struct s_op
** 0000 0000
** .... .PBA
*/

# define PS_A 1
# define PS_B 2
# define PS_BOTH 3
# define PS_PUSHA 5
# define PS_PUSHB 6

typedef struct	s_plate
{
	int		value;
}				t_plate;

typedef struct	s_op
{
	char	name[4];
	char	option;
	void	(*fn)(t_list **);
}				t_op;

typedef strcut	s_algo
{
	void	(*fn)(t_list **, t_list **, t_list **);
	int		limit;
}				t_algo;

int				ft_argscheck(int ac, char **av);
int				ft_goto_nextnb(char *str);

int				ft_stackfill(int ac, char **av, t_list **stack_a);

void			ft_stackprint(t_list *stack, char name);
void			ft_stacksdel(t_list **stack_a, t_list **stack_b);

void			ft_opwrite(t_list *ops);
t_list			*ft_sortslaunch(t_list **s_a, t_list **s_b, t_list **ops);

int				ft_optry(t_list **stack_a, t_list **stack_b);
void			ft_opapply(t_op *op, t_list **stack_a, t_list **stack_b);
void			ft_push(t_list **stack_from, t_list **stack_to);
void			ft_swap(t_list **stack);
void			ft_rotate(t_list **stack);
void			ft_reverse(t_list **stack);

#endif
