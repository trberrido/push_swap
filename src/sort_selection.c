/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:52:37 by thberrid          #+#    #+#             */
/*   Updated: 2019/05/18 21:24:58 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list		*selection(t_list **s_a, t_list **s_b, t_list **ops, int len)
{
	int		pushed;

	pushed = pushbn_desc(s_a, s_b, ops, len);
	if (pushed == FT_ERROR)
		return (NULL);
	pushed = pushan_asc(s_a, s_b, ops, pushed);
	if (pushed == FT_ERROR)
		return (NULL);
	return (*ops);
}
