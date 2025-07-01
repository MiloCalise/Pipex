/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:37:37 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/19 13:36:03 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_lstsize(t_list *lst);
int		ft_printf(const char *format, ...);
int		check_format(const char *format);
int		distrib(char type, va_list params);
int		print_str(const char *format, va_list params);
int		type_c(va_list params);
int		type_di(va_list params);
int		type_s(va_list params);
int		type_u(va_list params);
int		type_p(va_list params);
int		ft_putnbr_hex_adr(unsigned long nbr);
int		ft_putnbr_hex_low(unsigned int nbr);
int		ft_putnbr_hex_up(unsigned int nbr);
int		type_x(va_list params);
int		type_xx(va_list params);
int		type_percent(void);
int		size_calcu(long n);

void	fill_hex(char *dest, char *str);
void	ft_put_unsigned_nbr(unsigned int nbr);

char	*ft_strnstr(const char *str, const char *to_find, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*get_next_line(int fd);
char	*ft_strcat(char *dest, char const *src);
char	*check_stash(char *stash);

char	**ft_split(char const *s, char c);

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

void	*ft_memchr(const void *arr, int c, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *str, int ch, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
