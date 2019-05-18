/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:41:37 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/17 19:20:28 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				goto_nextnb(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		i += 1;
	while (str[i] && ft_isdigit(str[i]))
		i += 1;
	return (i);
}

static int		args_digit(int ac, char **av)
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
				&& av[i][j] != '-' && av[i][j] != '+')
				return (0);
			if (av[i][j] == '-' && av[i][j] == '+'
				&& !ft_isdigit(av[i][j + 1]))
				return (0);
			j += 1;
		}
		i += 1;
	}
	return (1);
}

static int		args_int(int ac, char **av)
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
			value = ft_atol(&av[i][j]);
			if (value > FT_INTMAX || value < FT_INTMIN)
				return (0);
			j += goto_nextnb(&av[i][j]);
		}
		i += 1;
	}
	return (1);
}

int				args_check(int ac, char **av)
{
	if (ac < 2)
		return (1);
	if (!args_digit(ac, av))
		return (0);
	if (!args_int(ac, av))
		return (0);
	return (1);
}
