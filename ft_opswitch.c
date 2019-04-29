/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opswitch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:27:25 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/29 13:05:11 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_op		*ft_opget(char *new_op)
{
	int				i;
	static t_op		ops[11] = {
		{"sa", PS_A, ft_swap},
		{"sb", PS_B, ft_swap},
		{"ss", PS_BOTH, ft_swap},
		{"pa", PS_PUSHA, ft_swap},
		{"pb", PS_PUSHB, ft_swap},
		{"ra", PS_A, ft_rotate},
		{"rb", PS_B, ft_rotate},
		{"rr", PS_BOTH, ft_rotate},
		{"rra", PS_A, ft_reverse},
		{"rrb", PS_B, ft_reverse},
		{"rrr", PS_BOTH, ft_reverse},
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

void		ft_opapply(t_op *op, t_list **stack_a, t_list **stack_b)
{
	if (op->option >> 2 & 1)
	{
		if (op->option & 1)
			ft_push(stack_b, stack_a);
		else
			ft_push(stack_a, stack_b);
	}
	else
	{
		if (op->option & 1)
			op->fn(stack_a);
		if (op->option >> 1 & 1)
			op->fn(stack_b);
	}
}

int			ft_optry(t_list **stack_a, t_list **stack_b)
{
	int				ret;
	char			*new_op;
	t_op			*op;

	new_op = NULL;
	while ((ret = get_next_line(0, &new_op)))
	{
		if (!(op = ft_opget(new_op)) || ret == -1)
		{
			ft_strdel(&new_op);
			return (0);
		}
		ft_opapply(op, stack_a, stack_b);
		ft_putendl(new_op);
		ft_stackprint(*stack_a, 'A');
		ft_stackprint(*stack_b, 'B');
		ft_putendl("\n\n\n");
		ft_strdel(&new_op);
	}
	ft_strdel(&new_op);
	return (1);
}

int			ft_optryn(t_list **s_a, t_list **s_b, char *name, int n)
{
	int		i;
	t_op	*op;

	i = 0;
	while (i < n)
	{
		if (!(op = ft_opget(name)))
			return (-1);
		ft_opapply(op, s_a, s_b);
		i += 1;
	}
	return (1);
}
