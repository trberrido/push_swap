/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_utils_manip.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:36:21 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/04 21:10:41 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*ft_rorrr(t_list **s, t_list **ops, char *str, int min)
{
	void	(*f)(t_list **);

	f = (ft_opget(str))->fn;
	while (*s && ((t_plate *)(*s)->content)->value != min)
	{
		if (!ft_opadd(ops, str))
			return (NULL);
		f(s);
	}
	return (*ops);
}

t_list			*ft_maximumontop(t_list **stack, t_list **ops)
{
	int		stack_maximum;
	int		maximum_position;
	int		stack_len;

	stack_len = ft_lstlen(*stack);
	stack_maximum = ft_findmaximum(*stack);
	maximum_position = ft_findposition(*stack, stack_maximum);
	if (maximum_position > 0)
	{
		if (maximum_position <= stack_len / 2)
			ft_rorrr(stack, ops, "rb", stack_maximum);
		else
			ft_rorrr(stack, ops, "rrb", stack_maximum);
		if (!*ops)
			return (NULL);
	}
	return (*stack);
}

t_list			*ft_minimumontop(t_list **stack, t_list **ops)
{
	int		stack_minimum;
	int		minimum_position;
	int		stack_len;

	stack_len = ft_lstlen(*stack);
	stack_minimum = ft_findminimum(*stack);
	minimum_position = ft_findposition(*stack, stack_minimum);
	if (minimum_position > 0)
	{
		if (minimum_position <= stack_len / 2)
			ft_rorrr(stack, ops, "ra", stack_minimum);
		else
			ft_rorrr(stack, ops, "rra", stack_minimum);
		if (!*ops)
			return (NULL);
	}
	return (*stack);
}
