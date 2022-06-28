/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:43:16 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/27 10:14:55 by waxxy            ###   ########.fr       */
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
	blast = ft_blast(*a);
	tmpa = *a;
	*a = blast->next;
	(*a)->next = tmpa;
	blast->next = NULL;
	(*a)->bnext = NULL;
	tmpa->bnext = *a;
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
	blast = ft_blast(*b);
	tmpb = *b;
	*b = blast->next;
	(*b)->next = tmpb;
	blast->next = NULL;
	(*b)->bnext = NULL;
	tmpb->bnext = *b;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_int **a, t_int **b)
{
	t_int	*tmp;
	t_int	*blast;

	if ((!*a || !a || (*a)->next == NULL) && (!*b || !b || (*b)->next == NULL))
		return (write(1, "rrr\n", 4), (void)0);
	if (*a && a && (*a)->next != NULL)
	{
		blast = ft_blast(*a);
		tmp = *a;
		*a = blast->next;
		(*a)->next = tmp;
		blast->next = NULL;
		(*a)->bnext = NULL;
		tmp->bnext = *a;
	}
	if (*b && b && (*b)->next != NULL)
	{
		blast = ft_blast(*b);
		tmp = *b;
		*b = blast->next;
		(*b)->next = tmp;
		blast->next = NULL;
		(*b)->bnext = NULL;
		tmp->bnext = *b;
	}
	write(1, "rrr\n", 4);
}

void	ft_rev_rotate_ntimes(t_int **top, int n)
{
	while (n-- > 0)
		ft_rra(top);
}
