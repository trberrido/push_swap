/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:32:17 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/23 14:32:31 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			ft_stackprint(t_list *stack, char name)
{
	ft_putchar(name);
	ft_putendl(":");
	if (!stack)
		ft_putendl("empty stack");
	while (stack)
	{
		ft_putnbr(((t_plate *)stack->content)->value);
		ft_putendl("");
		stack = stack->next;
	}
	ft_putendl("");
}

