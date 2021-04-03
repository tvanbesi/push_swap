/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:58:03 by user42            #+#    #+#             */
/*   Updated: 2021/04/01 15:48:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <time.h>

static int
	invalidarg(char *arg)
{
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
		if (!ft_isdigit(*arg++))
			return (1);
	return (0);
}

static void
	checker(t_stack *a, t_stack *b)
{
	int		r;
	int		operation;
	char	*line;

	//printstacks(a, b);
	while ((r = prompt(&line)) > 0)
	{
		operation = getoperation(line);
		free(line);
		if (operation == INVALID)
		{
			ft_putendl_fd("Error", STDERR);
			return ;
		}
		stack_operation(a, b, operation);
		//printstacks(a, b);
		//sleep(1);
		//nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
	}
	if (r == 0)
	{
		free(line);
		if (issorted(a, ascending, 0) && b->top == 0)
			ft_putendl_fd("OK", STDOUT);
		else
			ft_putendl_fd("KO", STDOUT);
	}
	else if (r == -1)
		ft_putendl_fd("Error", STDERR);
}

int
	main(int argc, char **argv)
{
	int		i;
	t_stack	stack_a;
	t_stack	stack_b;
	int		*items_a;
	int		*items_b;

	i = 1;
	if (argc < 2)
		return (0);
	if (!(items_a = malloc((argc - 1) * sizeof(int)))
	|| !(items_b = malloc((argc - 1) * sizeof(int))))
		return (-1);
	while (i < argc)
	{
		if (invalidarg(argv[i]))
		{
			ft_putendl_fd("Error", STDERR);
			free(items_a);
			free(items_b);
			return (-1);
		}
		items_a[argc - 1 - i] = ft_atoi(argv[i]);
		i++;
	}
	// check for duplicates and over INTMAX
	stack_a.maxsize = argc - 1;
	stack_a.top = stack_a.maxsize;
	stack_a.items = items_a;
	stack_b.maxsize = stack_a.maxsize;
	stack_b.top = 0;
	stack_b.items = items_b;
	checker(&stack_a, &stack_b);
	//printstacks(&stack_a, &stack_b);
	free(items_a);
	free(items_b);
	return (0);
}
