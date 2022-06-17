/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:23:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/17 15:49:29 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* struct libft to delete */
typedef struct s_int
{
	int				digit;
	struct s_int	*next;
}	t_int;

/* libft to delete */
char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
void	ft_lstadd_back(t_int *lst, t_int *new);
void	ft_lstadd_front(t_int *lst, t_int *new);
t_int	*ft_lstlast(t_int *lst);
t_int	*ft_lstnew(char *content);
void	ft_lstclear(t_int *lst);
int		ft_isdigit(int c);
/* proto utils */
t_int	*ft_build_stack(int nbdigit, char **nb_arg);
void	ft_pusha(t_int **topa, t_int **topb);
void	ft_pushb(t_int **topb, t_int **topa);
void	ft_swapa(t_int **a);
void	ft_swapb(t_int **b);
void	ft_swapss(t_int **a, t_int **b);
void	ft_ra(t_int **a);
void	ft_rb(t_int **b);
void	ft_rr(t_int **a, t_int **b);
void	ft_rra(t_int **a);
void	ft_rrr(t_int **a, t_int **b);

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

#endif