/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:26:56 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/22 22:22:18 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_define_rotate(t_int *top, int digit)
{
	int		size;
	int		i;
	t_int	*tmp;

	if (top == NULL)
		return (0);
	tmp = top;
	size = ft_lstsize(tmp) / 2;
	i = 0;
	while (tmp && tmp->digit != digit)
	{
		tmp = tmp->next;
		i++;
		if (tmp == NULL)
			return (0);
	}
	if (i <= size)
		return (1);
	else
		return (2);
}

void	ft_act_rotate(t_int **top, int digit)
{
	int	r;

	r = ft_define_rotate(*top, digit);
	if (r == 1)
		while ((*top)->digit != digit)
			ft_ra(top);
	else if (r == 2)
		while ((*top)->digit != digit)
			ft_rra(top);
	else
		return ;
}

void	ft_define_sort(t_int **topa, t_int **topb)
{
	int	size;

	size = ft_lstsize(*topa);
	if (size <= 3)
		ft_sort3(topa, topb, size);
	else if (size <= 5)
		ft_sort5(topa, topb, size);
	else
		ft_sel(topa, topb);
	return ;
}

void	ft_sel(t_int **topa, t_int **topb)
{
	t_int	*tmp;
	t_int	*min;
	t_int	*r;

	tmp = *topa;
	while (tmp)
	{
		min = tmp;
		r = tmp->next;
		while (r)
		{
			if (min->digit > r->digit)
				min = r;
			r = r->next;
		}
		ft_act_rotate(topa, min->digit);
		ft_pushb(topb, topa);
		tmp = *topa;
	}
	while (*topb)
		ft_pusha(topa, topb);
}
