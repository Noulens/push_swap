/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:23:06 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/17 21:37:13 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_int *a)
{
	long	x;

	x = INT_MIN;
	while (a)
	{
		if (a->digit < x)
			return (0);
		x = a->digit;
		a = a->next;
	}
	return (1);
}