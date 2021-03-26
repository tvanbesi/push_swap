/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:31:09 by tvanbesi          #+#    #+#             */
/*   Updated: 2019/11/14 22:32:10 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}
