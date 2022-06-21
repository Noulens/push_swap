/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:57:32 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/21 17:35:31 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_free_splt(char **tofree)
{
	int	k;

	k = 0;
	while (tofree[k])
		free(tofree[k++]);
	free(tofree);
}

t_int	*ft_build_stack(int nbdigit, char **nb_arg)
{
	char	*p;
	char	**t;
	t_int	*top;
	int		i;

	p = ft_strjoin(nbdigit, nb_arg, " ");
	t = ft_split(p, ' ');
	if (!t || !*t)
		return (free(t), free(p), NULL);
	free(p);
	i = 0;
	top = ft_lstnew(t[i++]);
	while (t[i])
		ft_lstadd_back(top, ft_lstnew(t[i++]));
	ft_free_splt(t);
	return (top);
}
