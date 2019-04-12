/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:43:54 by thberrid          #+#    #+#             */
/*   Updated: 2019/04/12 14:36:54 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct	s_plate
{
	int		value;
}				t_plate;

int				ft_argscheck(int ac, char **av);
t_list			*ft_stackfill(int ac, char **av, t_list *stack_a);

#endif
