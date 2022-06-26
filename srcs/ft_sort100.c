/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:55:03 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/26 17:21:59 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_selectionb(t_int **topa, t_int **topb)
{
	t_int	*tmp;
	t_int	*max;
	t_int	*r;

	tmp = *topb;
	while (*topb)
	{
		max = tmp;
		r = tmp->next;
		while (r)
		{
			if (max->digit < r->digit)
				max = r;
			r = r->next;
		}
		ft_act_rotateb(topb, max->digit);
		ft_pusha(topa, topb);
		tmp = *topb;
	}
}

void	ft_selectiona(t_int **topa, t_int **topb)
{
	t_int	*tmp;
	t_int	*max;
	t_int	*r;

	tmp = *topa;
	while (ft_lstsize(*topa) > 3)
	{
		max = tmp;
		r = tmp->next;
		while (r)
		{
			if (max->digit > r->digit)
				max = r;
			r = r->next;
		}
		ft_act_rotatea(topa, max->digit);
		ft_pushb(topb, topa);
		tmp = *topa;
	}
	ft_sort3(topa, 3);
}

static int	ft_is_in_tab(int *tab, int low, int high, int target)
{
	while (low <= high)
	{
		if (tab[low] == target)
			return (1);
		low++;
	}
	return (0);
}
/*
static int	ft_shortcut(int *tab, int low, int high, t_int *topa)
{
	int		i;
	int		j;
	int		res;
	int		res2;

	i = 1;
	j = 1;
	while (!ft_is_in_tab(tab, low, high, topa->digit) && i++)
		topa = topa->next;
	res = topa->digit;
	topa = topa->next;
	while (topa && !ft_is_in_tab(tab, low, high, topa->digit))
		topa = topa->next;
	if (topa == NULL)
		return (res);
	res2 = topa->digit;
	while (topa && j++)
		topa = topa->next;
	if (i <= j)
		return (res);
	else
		return (res2);
}*/

static int	ft_shortcut(int *tab, int low, int high, t_int *topa)
{
	int		i;
	int		j;
	int		res;
	int		res2;
	t_int	*bottom;

	i = 0;
	j = 0;
	while (!ft_is_in_tab(tab, low, high, topa->digit))
	{
		++i;
		topa = topa->next;
	}
	res = topa->digit;
	bottom = ft_lstlast(topa);
	while (bottom != res && !ft_is_in_tab(tab, low, high, bottom->digit))
	{
		j++;
		bottom = bottom->bnext;
	}
}

void	ft_sort100(t_int **topa, t_int **topb, int *tab, int size)
{
	int	pivot;
	int	low;
	int	i;

	pivot = size / 5;
	i = 0;
	low = 0;
	while (i < 4)
	{
		while (ft_min(*topa) < tab[pivot])
		{
			while ((*topa)->digit < tab[pivot])
				ft_pushb(topb, topa);
			if (ft_min(*topa) < tab[pivot])
			{
				ft_act_rotatea(topa, ft_shortcut(tab, low, pivot, *topa));
				ft_pushb(topb, topa);
			}
		}
		i++;
		low = pivot;
		pivot += size / 5;
	}
	ft_selectiona(topa, topb);
	ft_selectionb(topa, topb);
}
