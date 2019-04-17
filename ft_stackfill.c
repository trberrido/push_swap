/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:55:28 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/16 18:09:38 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		ft_stacksdel(t_list **stack_a, t_list **stack_b, t_list **stack_op)
{
	if (*stack_a)
		ft_lstdel(stack_a, &ft_bzero);
	if (*stack_b)
		ft_lstdel(stack_b, &ft_bzero);
	if (*stack_op)
		ft_lstdel(stack_op, &ft_bzero);
}

static int	ft_checktwins(t_list *stack, int value)
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

void		ft_stackprint(t_list *stack, char name)
{
	ft_putchar(name);
	ft_putendl(":");
	if (!stack)
		ft_putendl("empty stack");
	while (stack)
	{
		ft_putnbr(((t_plate *)stack->content)->value);
		ft_putendl("");
		stack = stack->next;
	}
	ft_putendl("");
}

int			ft_stackfill(int ac, char **av, t_list **stack)
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
			ft_lstappend(stack, ft_lstnew(&newplate, sizeof(t_plate)));
			if (!ft_checktwins(*stack, newplate.value))
			{
				ft_lstdel(stack, &ft_memerase);
				return (0);
			}
			j += ft_goto_nextnb(&av[i][j]);
		}
		i += 1;
	}
	return (1);
}
