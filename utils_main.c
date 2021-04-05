/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:22:33 by user42            #+#    #+#             */
/*   Updated: 2021/04/04 13:46:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int
	duplicates(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->top)
	{
		j = i + 1;
		while (j < a->top)
		{
			if (a->items[i] == a->items[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int
	invalidarg(char *arg)
{
	int	s;

	if (!*arg)
		return (1);
	s = 1;
	if (*arg == '+' || *arg == '-')
	{
		if (*arg == '-')
			s = -1;
		arg++;
	}
	if (s == 1)
	{
		if (ft_strlen(arg) > 10
		|| (ft_strlen(arg) == 10 && ft_strncmp(arg, "2147483647", 11) > 0))
			return (1);
	}
	else if (s == -1)
		if (ft_strlen(arg) > 10
		|| (ft_strlen(arg) == 10 && ft_strncmp(arg, "2147483648", 11) > 0))
			return (1);
	while (*arg)
		if (!ft_isdigit(*arg++))
			return (1);
	return (0);
}

void
	setstack(t_stack *stack, int maxsize, int top, int *items)
{
	stack->maxsize = maxsize;
	stack->top = top;
	stack->items = items;
}

int
	freeret(int *p1, int *p2, int ret)
{
	ft_putendl_fd("Error", STDERR);
	free(p1);
	free(p2);
	return (ret);
}
