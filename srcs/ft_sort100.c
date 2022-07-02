/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:55:03 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/30 19:49:48 by tnoulens         ###   ########.fr       */
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
	ft_sort3(topa, ft_lstsize(*topa));
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

static int	ft_shortcut(int *tab, int low, int high, t_int *topa)
{
	int		i;
	int		j;
	t_int	*btm;

	i = 0;
	j = 0;
	btm = ft_lstlast(topa);
	while (!ft_is_in_tab(tab, low, high, topa->digit))
	{
		++i;
		topa = topa->next;
	}
	while (btm->digit != topa->digit
		&& !ft_is_in_tab(tab, low, high, btm->digit) && j < i)
	{
		j++;
		btm = btm->bnext;
	}
	if (i <= j)
		return (topa->digit);
	else
		return (btm->digit);
	return (-1);
}

void	ft_sort100(t_int **topa, t_int **topb, int *tab, int size)
{
	int	pivot;
	int	low;
	int	i;

	pivot = size / 5;
	i = -1;
	low = 0;
	while (++i < 4)
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
		low = pivot;
		pivot += size / 5;
	}
}
