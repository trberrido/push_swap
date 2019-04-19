/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:05 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/19 18:45:52 by thberrid         ###   ########.fr       */
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
	stack_len = ft_lstlen(*stack_a);
	while (stack_len > algos[i].limit && i + 1 < 2)
		i += 1;
	return (algos[i].fn(stack_a, stack_b, ops));
}
