/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:43:16 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/03 17:20:21 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_int	*ft_blast(t_int *lst)
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
		ft_printf("rra\n");
		return ;
	}
	blast = ft_blast(*a);
	tmpa = *a;
	*a = blast->next;
	(*a)->next = tmpa;
	blast->next = NULL;
	(*a)->bnext = NULL;
	tmpa->bnext = *a;
	ft_printf("rra\n");
}

void	ft_rrb(t_int **b)
{
	t_int	*tmpb;
	t_int	*blast;

	if (!*b || !b || (*b)->next == NULL)
	{
		ft_printf("rrb\n");
		return ;
	}
	blast = ft_blast(*b);
	tmpb = *b;
	*b = blast->next;
	(*b)->next = tmpb;
	blast->next = NULL;
	(*b)->bnext = NULL;
	tmpb->bnext = *b;
	ft_printf("rrb\n");
}

void	ft_rrr(t_int **a, t_int **b)
{
	if ((!*a || !a || (*a)->next == NULL) && (!*b || !b || (*b)->next == NULL))
		return (ft_printf("rrr\n"), (void)0);
	ft_srra(a);
	ft_srrb(b);
	ft_printf("rrr\n");
}

void	ft_rev_rotate_ntimes(t_int **top, int n)
{
	while (n-- > 0)
		ft_rrb(top);
}
