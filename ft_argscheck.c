/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argscheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:18:45 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/12 15:50:56 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		ft_argsdigit(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isspace(av[i][j]) && !ft_isdigit(av[i][j])
					&& av[i][j] != '-')
				return (0);
			if (av[i][j] == '-' && !ft_isdigit(av[i][j + 1]))
				return (0);
			j += 1;
		}
		i += 1;
	}
	return (1);
}

static int		ft_argsint(int ac, char **av)
{
	int		i;
	int		j;
	long	value;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			value = ft_atol(av[i] + j);
			if (value > FT_INTMAX || value < FT_INTMIN)
				return (0);
			while (av[i][j] && (ft_isdigit(av[i][j]) || av[i][j] == '-'))
				j += 1;
		}
		i += 1;
	}
	return (1);
}

int				ft_argscheck(int ac, char **av)
{
	if (ac < 2)
		return (0);
	ft_putendl(">");
	if (!ft_argsdigit(ac, av))
		return (0);
	ft_putendl(">");
	if (!ft_argsint(ac, av))
		return (0);
	ft_putendl(">");
	return (1);
}
