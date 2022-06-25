/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:26:56 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/24 18:43:43 by waxxy            ###   ########.fr       */
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

void	ft_act_rotatea(t_int **top, int digit)
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

void	ft_act_rotateb(t_int **top, int digit)
{
	int	r;

	r = ft_define_rotate(*top, digit);
	if (r == 1)
		while ((*top)->digit != digit)
			ft_rb(top);
	else if (r == 2)
		while ((*top)->digit != digit)
			ft_rrb(top);
	else
		return ;
}

void	ft_define_sort(t_int **topa, t_int **topb)
{
	int		size;

	if (ft_sorted(*topa))
		return ;
	size = ft_lstsize(*topa);
	if (size <= 3)
		ft_sort3(topa, size);
	else if (size <= 10)
		ft_sort10(topa, topb, size);
	else
		ft_qs(topa, topb, size);
	return ;
}

void	ft_sel(t_int **topa, t_int **topb)
{
	t_int	*tmp;
	t_int	*min;
	t_int	*r;

	tmp = *topa;
	while (ft_lstsize(*topa) > 3 && !ft_sorted(*topa))
	{
		min = tmp;
		r = tmp->next;
		while (r)
		{
			if (min->digit > r->digit)
				min = r;
			r = r->next;
		}
		ft_act_rotatea(topa, min->digit);
		ft_pushb(topb, topa);
		tmp = *topa;
	}
}
