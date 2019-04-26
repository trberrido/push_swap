/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_quicksort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:07:25 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/26 21:12:42 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		ft_getmedian(*stack)
{
	long	sum;

	sum = 0;
	while (stack)
	{
		sum += ((t_plate *)stack->content)->value;		
		stack = stack->next;
	}
	return (sum / ft_lstlen(stack));
}

static t_list	*ft_sliceit(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		median;
	int		i;

	median = ft_getmedian(*s_a);
	i = 0;
	while (i < len)
	{
		if (((t_plate *)(*s_a)->content)->value < median)
		{
			ft_push(s_a, s_b, ops);
			if (!ft_opadd(ops, "pb"))
				return (NULL);
		}
		else
		{
			ft_rotate(s_a, s_b, ops);
			if (!ft_opadd(ops, "ra"))
				return (NULL);
		}
		i += 1;
	}
	return (*ops);
}

t_list			*ft_quicksort(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	int		len;

	len = ft_lstlen(*stack_a);
	while (len > 3)
	{
		if (!ft_sliceit(stack_a, stack_b, ops, len))
			return (NULL);
		if (!ft_quicksort(stack_a, stack_b, ops)
			return (NULL);
		if (!ft_halfitback(stack_a, stack_b, ops, len))
			return (NULL);
		len = ft_lstlen(*stack_a);
	}
	if (!ft_minibubble(stack_a, ops))
		return (NULL);
	return (*ops)
}
