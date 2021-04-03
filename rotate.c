/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:55:31 by user42            #+#    #+#             */
/*   Updated: 2021/04/01 10:33:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void
	rotate_opti(t_stack *a, t_stack *b, int idx_a, int idx_b)
{
	int	m1;
	int	m2;
	int	d1;
	int	d2;

	//printf("rotating a[%d] : %d and b[%d] : %d\n", idx_a, a->items[idx_a], idx_b, b->items[idx_b]);
	m1 = getmove(idx_a, a->top);
	m2 = getmove(idx_b, b->top);
	d1 = getdist(idx_a, a->top);
	d2 = getdist(idx_b, b->top);
	//printf("m1:%d\tm2:%d\td1:%d\td2:%d\n", m1, m2, d1, d2);
	if (m1 == 0 || m2 == 0)
	{
		if (m1 == 0)
			put_on_top(b, idx_b, B);
		else
			put_on_top(a, idx_a, A);
	}
	else if (m1 < 0 && m2 < 0)
	{
		if (d1 < d2)
		{
			while (d1-- > 0)
			{
				stack_operation(a, b, RRR);
				ft_putendl_fd("rrr", STDOUT);
				d2--;
			}
			while (d2-- > 0)
			{
				stack_operation(a, b, RRB);
				ft_putendl_fd("rrb", STDOUT);
			}
		}
		else
		{
			while (d2-- > 0)
			{
				stack_operation(a, b, RRR);
				ft_putendl_fd("rrr", STDOUT);
				d1--;
			}
			while (d1-- > 0)
			{
				stack_operation(a, b, RRA);
				ft_putendl_fd("rra", STDOUT);
			}
		}
	}
	else if (m1 > 0 && m2 > 0)
	{
		if (d1 < d2)
		{
			while (d1-- > 0)
			{
				stack_operation(a, b, RR);
				ft_putendl_fd("rr", STDOUT);
				d2--;
			}
			while (d2-- > 0)
			{
				stack_operation(a, b, RB);
				ft_putendl_fd("rb", STDOUT);
			}
		}
		else
		{
			while (d2-- > 0)
			{
				stack_operation(a, b, RR);
				ft_putendl_fd("rr", STDOUT);
				d1--;
			}
			while (d1-- > 0)
			{
				stack_operation(a, b, RA);
				ft_putendl_fd("ra", STDOUT);
			}
		}
	}
	else
	{
		if (d1 > b->top / 2)
		{
			d2 = b->top - d2;
			if (m1 < 0)
			{
				while (d1-- > 0)
				{
					stack_operation(a, b, RRR);
					ft_putendl_fd("rrr", STDOUT);
					d2--;
					if (d2 == 0)
						break;
				}
				while (d1-- > 0)
				{
					stack_operation(a, b, RRA);
					ft_putendl_fd("rra", STDOUT);
				}
				while (d2-- > 0)
				{
					stack_operation(a, b, RRB);
					ft_putendl_fd("rrb", STDOUT);
				}
			}
			else if (m1 > 0)
			{
				while (d1-- > 0)
				{
					stack_operation(a, b, RR);
					ft_putendl_fd("rr", STDOUT);
					d2--;
					if (d2 == 0)
						break;
				}
				while (d1-- > 0)
				{
					stack_operation(a, b, RA);
					ft_putendl_fd("ra", STDOUT);
				}
				while (d2-- > 0)
				{
					stack_operation(a, b, RB);
					ft_putendl_fd("rb", STDOUT);
				}
			}
		}
		else if (d2 > a->top / 2)
		{
			d1 = a->top - d1;
			if (m2 < 0)
			{
				while (d2-- > 0)
				{
					stack_operation(a, b, RRR);
					ft_putendl_fd("rrr", STDOUT);
					d1--;
					if (d1 == 0)
						break;
				}
				while (d2-- > 0)
				{
					stack_operation(a, b, RRB);
					ft_putendl_fd("rrb", STDOUT);
				}
				while (d1-- > 0)
				{
					stack_operation(a, b, RRA);
					ft_putendl_fd("rra", STDOUT);
				}
			}
			else if (m2 > 0)
			{
				while (d2-- > 0)
				{
					stack_operation(a, b, RR);
					ft_putendl_fd("rr", STDOUT);
					d1--;
					if (d1 == 0)
						break;
				}
				while (d2-- > 0)
				{
					stack_operation(a, b, RB);
					ft_putendl_fd("rb", STDOUT);
				}
				while (d1-- > 0)
				{
					stack_operation(a, b, RA);
					ft_putendl_fd("ra", STDOUT);
				}
			}
		}
		else
		{
			put_on_top(a, idx_a, A);
			put_on_top(b, idx_b, B);
		}
	}
}

int
	getinsertidx_r(t_stack *a, int nb_to_insert)
{
	int	i;

	if (nb_to_insert > getbval(a) || nb_to_insert < getlval(a))
		return (getibval(a));
	i = 1;
	while (i < a->top)
	{
		if (a->items[i] > nb_to_insert
		&& nb_to_insert > a->items[i - 1])
			return (i - 1);
		i++;
	}
	return (i);
}

int
	getinsertidx(t_stack *a, int nb_to_insert)
{
	int	i;

	if (nb_to_insert > getbval(a) || nb_to_insert < getlval(a))
		return (getilval(a));
	i = 1;
	while (i < a->top)
	{
		if (a->items[i] < nb_to_insert
		&& nb_to_insert < a->items[i - 1])
			return (i - 1);
		i++;
	}
	return (i - 1);
}

void
	put_on_top(t_stack *stack, int idx, int stack_id)
{
	if (idx >= stack->top / 2)
	{
		idx = (stack->top - 1) - idx;
		while (idx-- > 0)
		{
			rotate(stack);
			if (stack_id == A)
				ft_putendl_fd("ra", STDOUT);
			else if (stack_id == B)
				ft_putendl_fd("rb", STDOUT);
		}
	}
	else
	{
		idx++;
		while (idx-- > 0)
		{
			rrotate(stack);
			if (stack_id == A)
				ft_putendl_fd("rra", STDOUT);
			else
				ft_putendl_fd("rrb", STDOUT);
		}
	}
}

