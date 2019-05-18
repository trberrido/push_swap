/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:28:10 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 20:06:29 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_ops;

	stack_a = NULL;
	stack_b = NULL;
	stack_ops = NULL;
	if (ac < 2)
		return (0);
	if (!args_check(ac, av))
		ft_putendl_fd("Error", 2);
	else if (!stack_fill(ac, av, &stack_a))
		ft_putendl_fd("Error", 2);
	else if (!sort_check(stack_a, stack_b))
	{
		if (!sort_switch(&stack_a, &stack_b, &stack_ops))
			ft_putendl_fd("Error", 2);
		else
			ft_lstiter(stack_ops, op_write);
	}
	stacks_del(&stack_a, &stack_b, &stack_ops);
	return (0);
}
