/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:26:28 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 20:07:14 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ops;

	stack_fill(ac, av, &stack_b);
	pushan_asc(&stack_a, &stack_b, &ops, ft_lstlen(stack_b));
	if (sort_check(stack_a, stack_b))
		ft_putendl("OK");
	else
	{
		ft_putnbr(count_breaks(stack_a));
		ft_putendl("");
	}
	return (0);
}
