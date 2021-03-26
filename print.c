/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:47:25 by user42            #+#    #+#             */
/*   Updated: 2021/03/24 15:05:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void
	printstacks(t_stack *a, t_stack *b)
{
	int	top_a;
	int	top_b;

	top_a = a->top;
	top_b = b->top;
	ft_putendl_fd("STACK A:", STDOUT);
	while (top_a-- > 0)
	{
		ft_putnbr_fd(a->items[top_a], STDOUT);
		ft_putstr_fd("\n", STDOUT);
	}
	ft_putendl_fd("----------", STDOUT);
	ft_putendl_fd("STACK B:", STDOUT);
	while (top_b-- > 0)
	{
		ft_putnbr_fd(b->items[top_b], STDOUT);
		ft_putstr_fd("\n", STDOUT);
	}
	ft_putendl_fd("__________", STDOUT);
}
