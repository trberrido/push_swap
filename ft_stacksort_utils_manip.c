/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_utils_manip.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:36:21 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/19 19:54:47 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_list	*ft_rorrr(t_list **s, t_list **ops, char *str, int min)
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

t_list			*ft_stackrewind(t_list *stack, t_list **ops)
{
	int		stack_len;
	int		i;

	i = 0;
	stack_len = ft_lstlen(stack);
	while (i < stack_len)
	{
		if (!ft_opadd(ops, "pa"))
			return (NULL);
		i += 1;
	}
	return (*ops);
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
		if (minimum_position < stack_len / 2)
			ft_rorrr(stack, ops, "ra", stack_minimum);
		else
			ft_rorrr(stack, ops, "rra", stack_minimum);
		if (!*ops)
			return (NULL);
	}
	return (*stack);
}
