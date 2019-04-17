/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:36:26 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/16 17:37:56 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		ft_checkfinal(t_list *stack_a, t_list *stack_b)
{
	int		prev;
	int		curr;

	if (!stack_b)
	{
		prev = ((t_plate *)stack_a->content)->value;
		while (stack_a)
		{
			curr = ((t_plate *)stack_a->content)->value;
			if (curr < prev)
				return (0);
			curr = prev;
			stack_a = stack_a->next;
		}
		return (1);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!ft_argscheck(ac, av))
		ft_putendl_fd("Error", 2);
	else if (!ft_stackfill(ac, av, &stack_a))
		ft_putendl_fd("Error", 2);
	else if (!ft_optry(&stack_a, &stack_b))
		ft_putendl_fd("Error", 2);
	else if (!ft_checkfinal(stack_a, stack_b))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	ft_stacksdel(&stack_a, &stack_b, NULL);
	return (0);
}
