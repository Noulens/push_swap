/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:13:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/15 20:01:03 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_int *lst, t_int *new)
{
	t_int	*pl;

	if (lst)
	{
		pl = ft_lstlast(lst);
		pl->next = new;
	}
	else
		lst = new;
}
