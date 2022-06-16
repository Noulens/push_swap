/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:46:53 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/16 14:23:36 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	ft_error_dup(t_int *top)
{
	write(1, "Error\n", 6);
	ft_lstclear(top);
	exit(EXIT_FAILURE);
}

static int	ft_find_duplicate(t_int *top)
{
	int		count;
	t_int	*temp;
	t_int	*temp1;

	temp = top;
	while (temp != NULL)
	{
		temp1 = top;
		count = 0;
		while (temp1 != NULL)
		{
			if (temp->digit == temp1->digit)
				count++;
			temp1 = temp1->next;
		}
		if (count > 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	display(t_int *top)
{
	t_int	*p;

	p = top;
	if (!top)
		return ;
	while (p != NULL)
	{
		printf("%d\n", p->digit);
		p = p->next;
	}
}

int	main(int argc, char **argv)
{
	t_int	*topa;
	t_int	*topb;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	if (argc >= 2)
	{
		if (ft_v_args(argv))
		{
			topa = ft_build_stack(argc - 1, argv + 1);
			if (ft_find_duplicate(topa) == 0)
				ft_error_dup(topa);
			topb = NULL;
			display(topa);
			display(topb);
		}
		else
			write(1, "Error\n", 6 * sizeof(char));
	}
	return (0);
}
