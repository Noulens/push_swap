/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:05:08 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/26 09:52:41 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define DECIMAL "0123456789"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif 

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_int
{
	long			digit;
	struct s_int	*next;
	struct s_int	*bnext;
}	t_int;

/* Part 1 */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
/* Part 2 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/* Bonus */
t_int	*ft_lstnew(char *content);
void	ft_lstadd_front(t_int *lst, t_int *new);
int		ft_lstsize(t_int *lst);
t_int	*ft_lstlast(t_int *lst);
void	ft_lstadd_back(t_int *lst, t_int *new);
void	ft_lstclear(t_int *lst);
/* ft_printf */
int		ft_c(int c);
int		ft_s(char *p);
int		ft_p(void *p);
int		ft_di(int nbr);
int		ft_xupx(unsigned int nbr, char c);
char	*ft_uitoa(unsigned int nbr);
int		ft_printf(const char *format, ...);
/* get_next_line */
char	*get_next_line(int fd);
size_t	ft_strlenb(const char *s);
char	*ft_strchrb(const char *s, int c);
void	*ft_callocb(size_t nmemb, size_t size);
void	ft_cpy(char *suf, char *p);
/* Other */
long	ft_atol(const char *nptr);
t_int	*ft_lstnewint(int content);
int		ft_lstsizem(t_int *lst, int n);

#endif