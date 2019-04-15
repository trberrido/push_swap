/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:27:25 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/15 19:45:48 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_getop(char *new_op, t_list **stack_a, t_list **stack_b)
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
		{
			ft_opapply(&ops[i], stack_a, stack_b);
			break ;
		}
		i += 1;
	}
	return ((i < 11));
}

int			ft_optry(t_list **stack_a, t_list **stack_b)
{
	int				ret;
	char			*new_op;

	new_op = NULL;
	while ((ret = get_next_line(0, &new_op)))
	{
		if (!ft_getop(new_op, stack_a, stack_b) || ret == -1)
		{
			ft_strdel(&new_op);
			return (0);
		}
		ft_stackprint(*stack_a, 'A');
		ft_stackprint(*stack_b, 'B');
	}
	ft_strdel(&new_op);
	return (1);
}
