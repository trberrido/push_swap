/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_bubble.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:28:24 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/04 14:26:40 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			ft_needaswap(t_list **stack_a, t_list **ops, int len)
{
	int		current;
	int		next;

	if (len >= 2)
	{
		current = ((t_plate *)(*stack_a)->content)->value;
		next = ((t_plate *)(*stack_a)->next->content)->value;
		if (current > next)
		{
			ft_swap(stack_a);
			if (!ft_opadd(ops, "sa"))
				return (-1);
		}
	}
	return (1);
}

t_list			*ft_bubble(t_list **stack_a, t_list **stack_b, t_list **ops, int len)
{
	if (!ft_needaswap(stack_a, ops, len))
	{

			ft_putendl("lol");
		return (NULL);
	}
	if (ft_isshifted(*stack_a) == 1)
	{
		if (!ft_minimumontop(stack_a, ops))
			return (NULL);
	}
	if (!ft_stacksort_check(*stack_a, *stack_b))
	{
		ft_rotate(stack_a);
		if (!ft_opadd(ops, "ra"))
			return (NULL);
		return (ft_bubble(stack_a, stack_b, ops, len));
	}
	return (*ops);
}
