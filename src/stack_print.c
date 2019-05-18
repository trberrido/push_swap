/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:00:00 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/17 15:27:01 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void			stack_print(t_list *stack, char name)
{
	ft_putstr("STACK ");
	ft_putchar(name);
	ft_putendl("");
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
