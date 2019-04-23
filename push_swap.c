/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:28:10 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/23 15:03:34 by thberrid         ###   ########.fr       */
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
	if (!ft_argscheck(ac, av))
		ft_putendl_fd("Error", 2);
	else if (!ft_stackfill(ac, av, &stack_a))
		ft_putendl_fd("Error", 2);
	else if (!ft_stacksort(&stack_a, &stack_b, &stack_ops))
		ft_putendl_fd("Error", 2);
	else
		ft_lstiter(stack_ops, ft_opwrite);
	ft_stacksdel(&stack_a, &stack_b, &stack_ops);
	return (0);
}
