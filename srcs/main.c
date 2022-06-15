/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:46:53 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/15 20:42:55 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static void	ft_free_splt(char **tofree)
{
	int	k;

	k = 0;
	while (tofree[k])
		free(tofree[k++]);
	free(tofree);
}

int	ft_v_args(char **v)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (v[++i])
	{
		j = 0;
		flag = 0;
		while (v[i][j])
		{
			if (ft_isdigit(v[i][j]) || (v[i][j] == '-' && flag != 1))
				flag = 1;
			else if (v[i][j] == ' ')
				flag = 0;
			else
				return (0);
			++j;
		}
	}
	return (1);
}

void	display(t_int *top)
{
	t_int	*p;

	p = top;
	while (p != NULL)
	{
		printf("%d\n", p->digit);
		p = p->next;
	}
}

static t_int	*ft_build_stack(int nbdigit, char **nb_arg)
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

int	main(int argc, char **argv)
{
	t_int	*top;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	if (argc >= 2)
	{
		if (ft_v_args(argv))
		{
			top = ft_build_stack(argc - 1, argv + 1);
		}
		else
			write(1, "Error\n", 6 * sizeof(char));
	}
	return (0);
}
