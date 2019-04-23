/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:31:05 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/23 14:31:17 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			ft_stacksdel(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	if (stack_a && *stack_a)
		ft_lstdel(stack_a, &ft_bzero);
	if (stack_b && *stack_b)
		ft_lstdel(stack_b, &ft_bzero);
	if (ops && *ops)
		ft_lstdel(ops, &ft_bzero);
}

