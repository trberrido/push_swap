/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:20:33 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 19:11:30 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	need_swap(t_list **stack_a, t_list **ops, int len)
{
	int		current;
	int		next;

	if (len >= 2)
	{
		current = ((t_plate *)(*stack_a)->content)->value;
		next = ((t_plate *)(*stack_a)->next->content)->value;
		if (current > next)
		{
			swap(stack_a, NULL);
			if (!op_add(ops, "sa"))
				return (FT_ERROR);
			return (1);
		}
	}
	return (0);
}

t_list		*bubble(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	if (need_swap(s_a, ops, ft_lstlen(*s_a)) == FT_ERROR)
		return (NULL);
	if (is_shifted(*s_a) == 1)
	{
		if (!pullup(s_a, ops, findn_min(*s_a, 1), 'a'))
			return (NULL);
	}
	if (!sort_check(*s_a, *s_b))
	{
		rotate(s_a, s_b);
		if (!op_add(ops, "ra"))
			return (NULL);
		return (bubble(s_a, s_b, ops, len));
	}
	return (*ops);
}
