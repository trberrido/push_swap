/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:55:28 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/23 14:43:26 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		ft_checktwins(t_list *stack, int value)
{
	t_list	*current;
	t_plate *plate;

	if (!stack)
		return (0);
	current = stack;
	while (current->next)
	{
		plate = (t_plate *)current->content;
		if (plate->value == value)
			return (0);
		current = current->next;
	}
	return (1);
}

static t_list	*ft_addplate(t_list **stack, t_plate *newplate)
{
	ft_lstappend(stack, ft_lstnew(newplate, sizeof(t_plate)));
	return (ft_lstgetlast(*stack));
}

t_list			*ft_stackfill(int ac, char **av, t_list **stack)
{
	int		i;
	int		j;
	t_plate	newplate;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			newplate.value = ft_atoi(&av[i][j]);
			if (!ft_addplate(stack, &newplate))
				return (NULL);
			if (!ft_checktwins(*stack, newplate.value))
			{
				ft_lstdel(stack, &ft_memerase);
				return (NULL);
			}
			j += ft_goto_nextnb(&av[i][j]);
		}
		i += 1;
	}
	return (*stack);
}
