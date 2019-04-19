/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_selection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:36:39 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/19 18:59:30 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list			*ft_selection(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	while (*stack_a)
	{
		if (!ft_minimumontop(stack_a, ops))
			return (NULL);
		ft_push(stack_a, stack_b);
		if (!ft_opadd(ops, "pb"))
			return (NULL);
	}
	if (!ft_stackrewind(*stack_b, ops))
		return (NULL);
	return (*ops);
}
