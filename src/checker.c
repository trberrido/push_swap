/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:36:26 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/19 17:37:23 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ops;

	stack_a = NULL;
	stack_b = NULL;
	ops = NULL;
	if (ac == 1)
		return (0);
	else if (!args_check(ac, av))
		ft_putendl_fd("Error", 2);
	else if (!stack_fill(ac, av, &stack_a))
		ft_putendl_fd("Error", 2);
	else if (!op_try(&stack_a, &stack_b))
		ft_putendl_fd("Error", 2);
	else if (!sort_check(stack_a, stack_b))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	stacks_del(&stack_a, &stack_b, &ops);
	return (0);
}
