/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:36:26 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/12 15:30:07 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_op;

	stack_a = NULL;
	stack_op = NULL;	
	if (!ft_argscheck(ac, av))
		ft_putendl("Error");
/*	else if (!ft_stackfill(ac, av, stack_a))
		ft_putendl("Error");
	else if (!ft_opget(stack_op, stack_a))
		ft_putendl("Error");
	else if (ft_opprocess(stack_a, stack_op))
		ft_putendl("OK");
*/	else
		ft_putendl("KO");
	return (0);
}
