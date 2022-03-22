/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:03:41 by clems             #+#    #+#             */
/*   Updated: 2021/09/21 17:23:00 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

//	return the initial number in a string as an int
int		ft_atoi(const char *str);
//	set a given amount of memory to the 0 value
void	ft_bzero(void *s, size_t n);
//	allocate and return a memoryblock with the bytes having the 0 value
void	*ft_calloc(size_t nb, size_t size);
//	tell if a given char is alphanumerical
int		ft_isalnum(int c);
//	tell if a given char is within the aphabet
int		ft_isalpha(int c);
//	tell if a given char is valued between 1 and 128
int		ft_isascii(int c);
//	tell if a given char is a number
int		ft_isdigit(int c);
//	tell if a given char is printable
int		ft_isprint(int c);
//	compare two memoryblocks and return the difference of the first wrong byte
int		ft_memcmp(const void *s1, const void *s2, size_t n);
//	copy from src to dest until char c occurs
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
//	return the first instance of c in s if found up to n
void	*ft_memchr(const void *s, int c, size_t n);
//	copy n bytes from src to dest
void	*ft_memcpy(void *dest, const void *src, size_t n);
//	copy n bytes from src to dest, taking care of memory overlap
void	*ft_memmove(void *dest, const void *src, size_t n);
//	set a memory block to a value c
void	*ft_memset(void *str, int c, size_t n);
//	return a pointer to the first instance of c in s
char	*ft_strchr(const char *str, int c);
//	allocate and copy s and return the copy
char	*ft_strdup(const char *s);
//	return the number of possibly concatenated bytes, inconcidering the actual action
size_t	ft_strlcat(char *dst, const char *src, size_t size);
//	return the number of possibly copied bytes, inconcidering the actual action
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
//	return the length of a string
size_t	ft_strlen(const char *str);
//	compare 2 strings and return the difference of the first diffrent char
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//	find the first instance of s2 in s1 and return it
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
//	return a pointer to the first instance of c in the s, checking only n bytes
char	*ft_strrchr(const char *str, int c);
//	convert UPPERCASE to lowercase
int		ft_tolower(int c);
//	convert lowercase to UPPERCASE
int		ft_toupper(int c);

/* ************************************************************************** */
/*	Split between Part one and Part two                                       */
/* ************************************************************************** */

//	trim the elements of set from start and end of s1
char	*ft_strtrim(char const *s1, char const *set);
//	create a copy of a given portion of a string
char	*ft_substr(char const *s, unsigned int start, size_t len);
//	concatenate two strings into a new one
char	*ft_strjoin(char const *s1, char const *s2);
//	put a char into a file
void	ft_putchar_fd(char c, int fd);
//	put a string and a newline into a file
void	ft_putendl_fd(char *s, int fd);
//	put a number into a file
void	ft_putnbr_fd(int n, int fd);
//	put a string into a file
void	ft_putstr_fd(char *s, int fd);
//	convert a number to its string representation
char	*ft_itoa(int n);
//	split a given string at a delimeter c into "words", removing c
char	**ft_split(const char *str, char c);
//	apply a function f to every byte of a string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* ************************************************************************** */
/*	Split between Part two and Bonus*/
/* ************************************************************************** */

//	add an element to the back of a list
void	ft_lstadd_back(t_list **lst, t_list *new);
//	add an element to the front of a list
void	ft_lstadd_front(t_list **lst, t_list *new);
//	remove every element of a list
void	ft_lstclear(t_list **lst, void (*del)(void*));
//	delete an element of a list
void	ft_lstdelone(t_list *lst, void (*del)(void *));
//	apply a function to every listelement, resulting in a new list
void	ft_lstiter(t_list *lst, void (*f)(void *));
//	go to the last element of a list
t_list	*ft_lstlast(t_list *lst);
//	apply a function to every listelement
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//	create a new listelement with given content
t_list	*ft_lstnew(void *content);
//	return the the lengthe of a list
int		ft_lstsize(t_list *lst);

/* ************************************************************************** */
/*	Split between Bonus and extra Functions	*/
/* ************************************************************************** */

//	return the log (base a) of b
size_t	ft_log(size_t b, int a);
//	return the factorial of a given number
size_t	ft_factorial(size_t n);
//	return the summ of all numbers from 0 ub to n
size_t	ft_sum_n(size_t n);
//	return the result of exponentioal calculation
size_t	ft_power_of(size_t base, size_t exponent);
//	return weather a c is part of set
int		ft_c_e_set_bonus(char c, char const *set);
//	copy from src to dest with actual usable return values
void	ft_strncpy_bonus(char *dest, char *src, unsigned int n);
//	return the previous element of a list
t_list	*ft_lstprev_bonus(t_list **lst, t_list *follow);
//	duplicate a list
void	ft_lstdup_bonus(t_list *src, t_list *dest);
//	check if there are any puplicate numbers (represented as string) in a given **c
int		ft_dupnbr(char **nums);
//	create a **char of (amount)"random" numbers of value 0 to (max)
char	**ft_randnbr(int max, int amount);
//	return the initial number in a string as a long
long	ft_atol(const char *str);

#endif
