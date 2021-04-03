/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:47:25 by user42            #+#    #+#             */
/*   Updated: 2021/04/01 09:51:17 by user42           ###   ########.fr       */
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
	printf("__________\n");
	printf("%-15s%-15s\n", "STACK A", "STACK B");
	while (top_a > 0 || top_b > 0)
	{
		top_a--;
		top_b--;
		if (top_a >= 0 && top_b >= 0)
			printf("%-15d%-15d\n", a->items[top_a], b->items[top_b]);
		else if (top_a >= 0)
			printf("%-15d%-15s\n", a->items[top_a], "");
		else if (top_b >= 0)
			printf("%-15s%-15d\n", "", b->items[top_b]);
	}
}
