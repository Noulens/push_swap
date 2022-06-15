/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:23:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/15 20:24:37 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_int
{
	int				digit;
	struct s_int	*next;
}	t_int;

char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *nptr);
void	ft_lstadd_back(t_int *lst, t_int *new);
void	ft_lstadd_front(t_int *lst, t_int *new);
t_int	*ft_lstlast(t_int *lst);
t_int	*ft_lstnew(char *content);
void	ft_lstclear(t_int *lst);

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

#endif