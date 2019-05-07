/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:31:31 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/30 21:31:32 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	t_list	*stack;
	int		median;

	if (!ft_stackfill(ac, av, &stack))
		return (0);
	ft_stackprint(stack, ':');
	median = ft_getquartile(stack, ft_lstlen(stack));
	ft_putnbr(median);
	ft_putendl("");
	return (0);
}
