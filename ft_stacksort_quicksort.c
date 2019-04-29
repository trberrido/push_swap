/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_quicksort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:07:25 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/29 12:57:33 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				ft_getmedian(t_list *stack, int len)
{
	t_list	*current_lst;
	int		current_value;
	int		prev_min;
	int		i;
	int		min;

	i = 0;
	prev_min = FT_INTMIN;
	if (len % 2)
		len += 1;
	while (i < len / 2)
	{
		current_lst = stack;
		min = FT_INTMAX;
		while (current_lst)
		{
			current_value = ((t_plate *)current_lst->content)->value;
			if (current_value > prev_min && current_value < min)
				min = current_value;
			current_lst = current_lst->next;
		}
		prev_min = min;
		i += 1;
	}
	return (min);
}

static int		ft_separate(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		i;
	int		pushed;
	int		median;

	i = 0;
	pushed = 0;
	median = ft_getmedian(*s_a, len);
	while (i < len)
	{
		if (((t_plate *)(*s_a)->content)->value < median)
		{
			pushed += 1;
			ft_push(s_a, s_b);
			if (!ft_opadd(ops, "pb"))
				return (-1);
		}
		else
		{
			ft_rotate(s_a);
			if (!ft_opadd(ops, "ra"))
				return (-1);
		}
		i += 1;
	}
	return (pushed);
}

/*
**	SLICE N
**		IF N < 3
**			RETURN FN swap
**		ELSE
**			FN separate
**			FN slice remaining
**			RETURN FN rewind pushed 	___	rewind will push back
**											before recalling slice
*/

static t_list	*ft_slice(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		remaining;
	int		pushed;

	if (len >= 3)
	{
		if ((pushed = ft_separate(s_a, s_b, ops, len)) < 0)
			return (NULL);
		remaining = len - pushed;
		if (remaining < ft_lstlen(*s_a))
		{
			ft_optryn(s_a, s_b, "rra", remaining);
			if (!ft_opaddn(ops, "rra", remaining))
				return (NULL);
		}
		if (!ft_slice(s_a, s_b, ops, remaining))
			return (NULL);
		ft_optryn(s_a, s_b, "pa", pushed);
		if (!ft_opaddn(ops, "pa", pushed))
			return (NULL);
		return (ft_slice(s_a, s_b, ops, pushed));
	}
	return (ft_needaswap(s_a, ops));
}

t_list			*ft_quicksort(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	return (ft_slice(stack_a, stack_b, ops, ft_lstlen(*stack_a)));
}
