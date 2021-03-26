/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:11:21 by user42            #+#    #+#             */
/*   Updated: 2021/03/26 13:52:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void
	sort_three(t_stack *a, t_stack *b)
{
	int	ilow;
	int	ibig;

	ilow = getilval(a);
	ibig = getibval(a);
	if (ibig == 0)
	{
		stack_operation(a, b, SA);
		ft_putendl_fd("sa", STDOUT);
	}
	else if (ilow == a->top - 1)
	{
		stack_operation(a, b, RA);
		ft_putendl_fd("ra", STDOUT);
		stack_operation(a, b, SA);
		ft_putendl_fd("sa", STDOUT);
		stack_operation(a, b, RRA);
		ft_putendl_fd("rra", STDOUT);
	}
	else
	{
		if (a->items[a->top - 1] > a->items[a->top - 2])
		{
			stack_operation(a, b, SA);
			ft_putendl_fd("sa", STDOUT);
		}
		stack_operation(a, b, RRA);
		ft_putendl_fd("rra", STDOUT);
	}
}
