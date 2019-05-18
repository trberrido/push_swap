/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:53:21 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/16 18:59:25 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		check_twins(t_list *stack, int value)
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

static t_list	*add_plate(t_list **stack, t_plate *newplate)
{
	t_list		*newlist;

	newlist = ft_lstnew(newplate, sizeof(t_plate));
	if (!newlist)
		return (NULL);
	ft_lstappend(stack, newlist);
	return (newlist);
}

t_list			*stack_fill(int ac, char **av, t_list **stack)
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
			if (!add_plate(stack, &newplate))
				return (NULL);
			if (!check_twins(*stack, newplate.value))
			{
				ft_lstdel(stack, &ft_memerase);
				return (NULL);
			}
			j += goto_nextnb(&av[i][j]);
		}
		i += 1;
	}
	return (*stack);
}
