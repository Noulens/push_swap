/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:26:56 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/03 18:02:48 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	ft_partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			ft_swap(&array[i], &array[j]);
		}
		j++;
	}
	ft_swap(&array[i + 1], &array[high]);
	return (i + 1);
}

static void	ft_quicksort(int array[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ft_partition(array, low, high);
		ft_quicksort(array, low, pi - 1);
		ft_quicksort(array, pi + 1, high);
	}
}

static int	*ft_copylst(t_int *topa, int size)
{
	int		*copy;
	int		*p;
	t_int	*tmp;

	tmp = topa;
	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	p = copy;
	while (tmp)
	{
		*p = tmp->digit;
		++p;
		tmp = tmp->next;
	}
	return (copy);
}

void	ft_sort(t_int **topa, t_int **topb, int size)
{
	int	*copy;

	copy = ft_copylst(*topa, size);
	if (copy == NULL)
		return ;
	ft_quicksort(copy, 0, size - 1);
	if (size <= 100)
		ft_sort100(topa, topb, copy, size);
	else
	{
		ft_scaling(copy, topa, size);
		ft_sort500(topa, topb, size);
	}
	free(copy);
}
