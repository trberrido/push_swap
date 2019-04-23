/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:05 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/23 15:13:57 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list		*ft_stacksort(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	int				i;
	int				stack_len;
	static t_algo	algos[2] = {
		{ft_bubble, 0},
		{ft_selection, 100},
	};

	i = 0;
	ft_stacksort_pre(stack_a, stack_b, ops);
	if (ft_stacksort_check(stack_a, stack_b))
		return (ops);
	stack_len = ft_lstlen(*stack_a);
	while (stack_len > algos[i].limit && i + 1 < 2)
		i += 1;
	algos[i].fn(stack_a, stack_b, ops);
	ft_stacksort_post(stack_a, stack_b, ops);
	return (*ops);
}
