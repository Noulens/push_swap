/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:43:16 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/21 18:32:04 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_int	*ft_blast(t_int *lst)
{
	while (lst)
	{
		if (!lst->next->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_rra(t_int **a)
{
	t_int	*tmpa;
	t_int	*blast;

	if (!*a || !a || (*a)->next == NULL)
	{
		write(1, "rra\n", 4);
		return ;
	}
	blast = ft_blast((*a)->next);
	tmpa = *a;
	*a = blast->next;
	(*a)->next = tmpa;
	blast->next = NULL;
	write(1, "rra\n", 4);	
}

void	ft_rrb(t_int **b)
{
	t_int	*tmpb;
	t_int	*blast;

	if (!*b || !b || (*b)->next == NULL)
	{
		write(1, "rrb\n", 4);
		return ;
	}
	blast = ft_blast((*b)->next);
	tmpb = *b;
	*b = blast->next;
	(*b)->next = tmpb;
	blast->next = NULL;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_int **a, t_int **b)
{
	t_int	*tmp;
	t_int	*blast;

	if ((!*a || !a || (*a)->next == NULL) && (!*b || !b || (*b)->next == NULL))
	{
		write(1, "rrr\n", 4);
		return ;
	}
	if (*a && a && (*a)->next != NULL)
	{
		blast = ft_blast((*a)->next);
		tmp = *a;
		*a = blast->next;
		(*a)->next = tmp;
		blast->next = NULL;
	}
	if (*b && b && (*b)->next != NULL)
	{
		blast = ft_blast((*b)->next);
		tmp = *b;
		*b = blast->next;
		(*b)->next = tmp;
		blast->next = NULL;
	}
	write(1, "rrr\n", 4);
}
