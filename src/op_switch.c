/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opswitch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:27:25 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/16 21:42:16 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_op		*op_get(char *new_op)
{
	int				i;
	static t_op		ops[11] = {
		{"sa", STACK_A + SWAP, swap},
		{"sb", STACK_B + SWAP, swap},
		{"ss", STACK_A + STACK_B + SWAP, swap},
		{"pa", STACK_A + PUSH, push},
		{"pb", STACK_B + PUSH, push},
		{"ra", STACK_A + ROTATE, rotate},
		{"rb", STACK_B + ROTATE, rotate},
		{"rr", STACK_A + STACK_B + ROTATE, rotate},
		{"rra", STACK_A + REVERSE, reverse},
		{"rrb", STACK_B + REVERSE, reverse},
		{"rrr", STACK_A + STACK_B + REVERSE, reverse},
	};

	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(new_op, ops[i].name))
			return (&ops[i]);
		i += 1;
	}
	return (NULL);
}

static void	op_apply(t_op *op, t_list **stack_a, t_list **stack_b)
{
	if (op->option & 1)
		op->fn(stack_a, stack_b);
	if (op->option >> 1 & 1)
		op->fn(stack_b, stack_a);
}

int			op_try(t_list **stack_a, t_list **stack_b)
{
	int				ret;
	char			*gnl_input;
	t_op			*op;

	gnl_input = NULL;
	while ((ret = get_next_line(0, &gnl_input)))
	{
		if (!(op = op_get(gnl_input)) || ret == -1)
		{
			ft_strdel(&gnl_input);
			return (0);
		}
		op_apply(op, stack_a, stack_b);
		ft_strdel(&gnl_input);
	}
	ft_strdel(&gnl_input);
	return (1);
}

int			op_tryn(t_list **s_a, t_list **s_b, char *name, int n)
{
	int		i;
	t_op	*op;

	i = 0;
	while (i < n)
	{
		if (!(op = op_get(name)))
			return (-1);
		op_apply(op, s_a, s_b);
		i += 1;
	}
	return (1);
}
