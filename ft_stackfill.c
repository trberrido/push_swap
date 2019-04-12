/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:55:28 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/12 15:27:54 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		ft_checktwins(t_list *stack)
{
	t_list	*current;
	t_plate *plate;

	if (!stack)
		return (0);
	current = stack->next;
	while (current)
	{
		plate = (t_plate *)current->content;
		if (plate->value == ((t_plate *)stack->content)->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_list			*ft_stackfill(int ac, char **av, t_list *stack)
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
			newplate.value = ft_atoi(av[i] + j);
			ft_lstadd(&stack, ft_lstnew(&newplate, sizeof(t_plate)));
			if (!ft_checktwins(stack))
			{
				ft_lstdel(&stack, &ft_memerase);
				return (NULL);
			}
			while (av[i][j] && ft_isdigit(av[i][j]))
				j += 1;
		}
		i += 1;
	}
	return (stack);
}
