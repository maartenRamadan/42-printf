/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 13:48:38 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:36:50 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_list
{
	int				minus;
	int				plus;
	int				zero;
	int				space;
	int				width;
	int				or_width;
	int				hasdot;
	int				dot;
	char			type;
	int				neg;
	int				nul;
	int				n;
	char			*hash;
	int				x;
	int				l;
	int				len;
	int				ret;
	int				or_len;
}					t_struct;

int					ft_printf(const char *str, ...);
size_t				pf_ft_strlen(const char *s);
int					pf_ft_atoi(const char **str);
char				*pf_ft_itoa(long long n, t_struct *f);
char				*pf_ft_strdup(const char *s1, t_struct *f);
void				handle_digit_flags(t_struct *f, va_list args);
void				handle_string_flags(t_struct *f, va_list args);
void				print_char(t_struct *f, va_list args);
void				find_flags(const char **str, t_struct *f, va_list args);
char				*pf_itohex(long n, t_struct *f);
char				*pf_ft_itou(unsigned long long n, t_struct *f);
void				digit_hex(char *s, t_struct *f);
char				*pf_ft_strjoin(char const *s1, char const *s2);
int					ft_write(t_struct *f, char *c, int len);
void				handle_ptr_flags(t_struct *f, va_list args);
void				handle_n(va_list args, t_struct *f);
void				print_digit(char *s, t_struct *f);

#endif
