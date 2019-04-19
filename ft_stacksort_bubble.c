/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksort_bubble.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:28:24 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/19 16:16:35 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list		*ft_bubble(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	ft_push(stack_a, stack_b);
	if (!ft_opadd(ops, "NAN"))
		return (NULL);
	return (*ops);
}
