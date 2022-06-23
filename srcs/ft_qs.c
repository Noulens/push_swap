/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:26:56 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/23 20:06:27 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_int	*ft_partition(t_int *first, t_int *last)
{
	t_int	*pivot;
	t_int	*front;
	int		temp;

	pivot = first;
	front = first;
	temp = 0;
	while (front != NULL && front != last)
	{
		if (front->digit < last->digit)
		{
			pivot = first;
			temp = first->digit;
			first->digit = front->digit;
			front->digit = temp;
			first = first->next;
		}
		front = front->next;
	}
	temp = first->digit;
	first->digit = last->digit;
	last->digit = temp;
	return (pivot);
}

static void	ft_quicksort(t_int *first, t_int *last)
{
	t_int	*pivot;

	pivot = ft_partition(first, last);
	if (first == last)
		return ;
	if (pivot != NULL && pivot->next != NULL)
		ft_quicksort(pivot->next, last);
	if (pivot != NULL && first != pivot)
		ft_quicksort(first, pivot);
}

static t_int	*ft_copylst(t_int *topa)
{
	t_int	*copy;
	t_int	*tmp;

	tmp = topa;
	copy = ft_lstnewint(tmp->digit);
	tmp = tmp->next;
	while (tmp)
	{
		ft_lstadd_back(copy, ft_lstnewint(tmp->digit));
		tmp = tmp->next;
	}
	ft_quicksort(copy, ft_lstlast(copy));
	return (copy);
}

static void	ft_solve(t_int **topa, t_int **topb, int size)
{
	int	top_half;
	int	median;

	if (size == 1)
		return ;
	top_half = 0;
	median = ft_median()
}

t_int	*ft_qs(t_int *topa, t_int **topb, int size)
{
	t_int	*copy;
	t_int	*tmp;

	copy = ft_copylst(topa);
}
