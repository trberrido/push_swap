/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:20:48 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/07 16:20:47 by thberrid         ###   ########.fr       */
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

typedef struct	s_algo
{
	t_list	*(*fn)(t_list **, t_list **, t_list **, int);
	int		limit;
}				t_algo;

int				ft_argscheck(int ac, char **av);
int				ft_goto_nextnb(char *str);

t_list			*ft_stackfill(int ac, char **av, t_list **stack_a);

void			ft_stackprint(t_list *stack, char name);
void			ft_stacksdel(t_list **stack_a, t_list **stack_b, t_list **ops);

void			ft_stacksort_post(t_list **ops);

int				ft_stacksort_check(t_list *stack_a, t_list *stack_b);

t_list			*ft_stacksort(t_list **stack_a, t_list **stack_b, t_list **ops);

void			ft_opwrite(t_list *ops);

t_list			*ft_opadd(t_list **ops, char *name);
t_list			*ft_opaddn(t_list **ops, char *name, int n);

int				ft_findnextmax(t_list *stack);

t_op			*ft_opget(char *new_op);
int				ft_optry(t_list **stack_a, t_list **stack_b);
int				ft_optryn(t_list **s_a, t_list **s_b, char *name, int n);
void			ft_opapply(t_op *op, t_list **stack_a, t_list **stack_b);

void			ft_push(t_list **stack_from, t_list **stack_to);
void			ft_swap(t_list **stack);
void			ft_rotate(t_list **stack);
void			ft_reverse(t_list **stack);

t_list			*ft_selection(t_list **stack_a, t_list **stack_b, t_list **ops, int len);
t_list			*ft_selection_b(t_list **stack_a, t_list **stack_b, t_list **ops, int len);

int				ft_needaswap(t_list **stack_a, t_list **ops, int len);
t_list			*ft_bubble(t_list **stack_a, t_list **stack_b, t_list **ops, int len);

t_list			*ft_rorrr(t_list **s, t_list **ops, char *str, int min);

t_list			*ft_slice_b(t_list **s_a, t_list **s_b, t_list **ops, int len);
t_list			*ft_slice(t_list **s_a, t_list **s_b, t_list **ops, int len);
t_list			*ft_quicksort(t_list **stack_a, t_list **stack_b, t_list **ops, int len);

t_list			*ft_insertion(t_list **stack_a, t_list **stack_b, t_list **ops, int len);

int			ft_stackissorted(t_list *stack);
int			ft_isasc(t_list *stack);

t_list			*ft_minimumontop(t_list **stack_a, t_list **ops);
t_list			*ft_maximumontop(t_list **stack, t_list **ops);

t_list			*ft_lstgetn(t_list *stack, int n);
int				ft_isshifted(t_list *stack);
int				ft_findminimum(t_list *stack);
int				ft_findmaximum(t_list *stack);
int				ft_findposition(t_list *stack, int searched_value);
int				ft_countbreaks(t_list *stack);
int				ft_getmedian(t_list *stack, int len);
int				ft_getquartile(t_list *stack, int len);

#endif
