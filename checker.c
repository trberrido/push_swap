/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:36:26 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/23 15:03:06 by thberrid         ###   ########.fr       */
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
	if (ac < 2 || !ft_argscheck(ac, av))
		ft_putendl_fd("Error", 2);
	else if (!ft_stackfill(ac, av, &stack_a))
		ft_putendl_fd("Error", 2);
	else if (!ft_optry(&stack_a, &stack_b))
		ft_putendl_fd("Error", 2);
	else if (!ft_stacksort_check(stack_a, stack_b))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	ft_stacksdel(&stack_a, &stack_b, &ops);
	return (0);
}
