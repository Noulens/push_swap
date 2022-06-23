/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:23:06 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/23 20:13:35 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_display(t_int *top)
{
	t_int	*p;

	p = top;
	if (!top)
		return ;
	while (p != NULL)
	{
		printf("%ld\n", p->digit);
		p = p->next;
	}
}

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

int	ft_max(t_int *top)
{
	int		max;
	t_int	*tmp;

	max = INT_MIN;
	tmp = top;
	while (tmp)
	{
		if ((tmp)->digit > max)
			max = (tmp)->digit;
		tmp = (tmp)->next;
	}
	return (max);
}

int	ft_min(t_int *top)
{
	int		min;
	t_int	*tmp;

	min = INT_MAX;
	tmp = top;
	while (tmp)
	{
		if ((tmp)->digit < min)
			min = (tmp)->digit;
		tmp = (tmp)->next;
	}
	return (min);
}

int	ft_median(t_int *top, int nb)
{
	int		nb;
	int		median;
	t_int	*tmp;
	int		i;

	tmp = top;
	nb = ft_lstsizem(top, nb);
	if (nb % 2 == 0)
		median = nb / 2 + 1;
	else
		median = (nb + 1) / 2;
	i = 1;
	while (i < median)
	{
		i++;
		tmp = tmp->next;
	}
	median = tmp->digit;
	return (median);
}
