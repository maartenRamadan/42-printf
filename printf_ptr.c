/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_ptr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 13:41:05 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:35:00 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_ptr(char *s, t_struct *f)
{
	if (!f->zero)
		f->width -= ft_write(f, "0x", 2);
	f->ret += write(1, s, f->or_len);
	while (f->width > f->len - 2 && f->minus)
		f->width -= ft_write(f, " ", 1);
	free(s);
}

void	handle_arg_zero(char *s, t_struct *f)
{
	f->len = (int)pf_ft_strlen(s);
	if (f->hasdot && !f->dot)
		f->width++;
	while (f->width > f->len + 2 && !f->minus)
		f->width -= ft_write(f, " ", 1);
	ft_write(f, "0x", 2);
	if (f->hasdot && !f->dot)
		return ;
	f->ret += write(1, s, f->len);
	while (f->dot > f->len && !f->minus)
		f->dot -= ft_write(f, "0", 1);
	free(s);
}

void	handle_ptr_flags(t_struct *f, va_list args)
{
	char	*s;

	s = pf_itohex(va_arg(args, unsigned long), f);
	if (!s)
		return ;
	f->len = (int)pf_ft_strlen(s) + 2;
	if ((*s == '0' && f->width <= f->len) ||
	(f->width > f->len && f->hasdot && !f->dot))
		return (handle_arg_zero(s, f));
	f->or_len = f->len - 2;
	if (f->dot > f->len)
	{
		f->zero = 1;
		ft_write(f, "0x", 2);
	}
	while (f->width > f->len && !f->minus)
		f->width -= ft_write(f, " ", 1);
	if (f->dot > f->len)
		f->width = f->dot + 2;
	while (f->width > f->len && !f->minus)
		f->width -= ft_write(f, "0", 1);
	print_ptr(s, f);
}
