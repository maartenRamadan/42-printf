/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_cs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 15:52:21 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:33:41 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_string(char *s, t_struct *f)
{
	f->ret += write(1, s, f->len);
	while (f->width > f->len && f->minus)
		f->width -= ft_write(f, " ", 1);
	free(s);
}

void	print_char(t_struct *f, va_list args)
{
	char	s;

	if (f->type == '%')
		s = '%';
	else
		s = (char)va_arg(args, int);
	while ((f->width - 1) > 0 && !f->minus)
		f->width -= ft_write(f, f->zero ? "0" : " ", 1);
	f->ret += write(1, &s, 1);
	while ((f->width - 1) > 0 && f->minus)
		f->width -= ft_write(f, " ", 1);
}

void	handle_string_flags(t_struct *f, va_list args)
{
	char	*s;

	s = pf_ft_strdup(va_arg(args, char *), f);
	if (!s)
		return ;
	f->len = (int)pf_ft_strlen(s);
	if (f->hasdot && f->dot < f->len)
		f->len = f->dot;
	while (f->width > f->len && !f->minus)
		f->width -= ft_write(f, f->zero ? "0" : " ", 1);
	print_string(s, f);
}
