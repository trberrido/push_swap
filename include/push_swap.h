/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:20:48 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 20:18:41 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

/*
** DEF belows are used for option in struct s_op
** 0000 0000
** ..RR SPBA
**   EO WU
**   VT AS
**   EA PH
**   RT
**   SE
**   E
*/

# define STACK_A 	1
# define STACK_B 	2
# define PUSH 		4
# define SWAP 		8
# define ROTATE 	16
# define REVERSE	32

typedef struct	s_plate
{
	int		value;
}				t_plate;

typedef struct	s_op
{
	char	name[4];
	char	option;
	void	(*fn)(t_list **, t_list **);
}				t_op;

typedef struct	s_algo
{
	t_list	*(*fn)(t_list **, t_list **, t_list **, int);
	int		limit;
}				t_algo;

int				args_check(int ac, char **av);
int				goto_nextnb(char *str);
t_list			*stack_fill(int ac, char **av, t_list **stack);
void			stacks_del(t_list **stack_a, t_list **stack_b, t_list **ops);
void			stack_print(t_list *stack, char name);

void			push(t_list **dst, t_list **src);
void			swap(t_list **stack, t_list **stack_useless);
void			rotate(t_list **stack, t_list **stack_useless);
void			reverse(t_list **stack, t_list **stack_useless);

t_op			*op_get(char *new_op);
int				op_try(t_list **s_a, t_list **s_b);
int				op_tryn(t_list **s_a, t_list **s_b, char *name, int n);
t_list			*op_add(t_list **ops, char *name);
t_list			*op_addn(t_list **ops, char *name, int n);
void			op_write(t_list *ops);

void			sort_post(t_list **ops);
int				sort_check(t_list *stack_a, t_list *stack_b);
int				is_shifted(t_list *stack);
int				count_breaks(t_list *stack);
int				find_position(t_list *stack, int searched_value);
int				find_median(t_list *stack, int len);
int				findn_min(t_list *stack, int n);
int				findn_max(t_list *stack, int n);

t_list			*pullup_minimum(t_list **stack, t_list **ops, char stack_id);
t_list			*pullup_maximum(t_list **stack, t_list **ops, char stack_id);
t_list			*pullup(t_list **stack, t_list **ops, int value, char stackid);
char			*shorterpath(t_list *stack, char stackid, int position);
t_list			*stack_pullup(t_list **s, t_list **ops, int value, char s_id);
int				pushan_asc(t_list **s_a, t_list **s_b, t_list **ops, int n);
int				pushbn_desc(t_list **s_a, t_list **s_b, t_list **ops, int n);
int				pushan_max(t_list **s_a, t_list **s_b, t_list **ops, int n);
int				pushbn_min(t_list **s_a, t_list **s_b, t_list **ops, int n);
int				pushanext_max(t_list **s_a, t_list **s_b, t_list **ops, int n);
int				pushbnext_min(t_list **s_a, t_list **s_b, t_list **ops, int n);
int				pushbrota(t_list **s_a, t_list **s_b, t_list **ops, int median);
int				pusharotb(t_list **s_a, t_list **s_b, t_list **ops, int median);
int				pushb_andswapb(t_list **s_a, t_list **s_b, t_list **ops, int p);
int				pusha_andswapa(t_list **s_a, t_list **s_b, t_list **ops, int p);
int				pushanext_max(t_list **s_a, t_list **s_b, t_list **ops, int n);
int				pushbnext_min(t_list **s_a, t_list **s_b, t_list **ops, int n);

t_list			*sort_switch(t_list **s_a, t_list **s_b, t_list **ops);
t_list			*bubble(t_list **s_a, t_list **s_b, t_list **ops, int len);
t_list			*quicksort(t_list **s_a, t_list **s_b, t_list **ops, int len);
t_list			*selection(t_list **s_a, t_list **s_b, t_list **ops, int len);

#endif
