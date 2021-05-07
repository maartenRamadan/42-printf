/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_digit_hex.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:28:27 by mramadan       #+#    #+#                */
/*   Updated: 2019/12/20 10:18:32 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_digit(char *s, t_struct *f)
{
	if (f->hash || *s)
		f->ret += write(1, s, f->len);
	while (f->width > f->len && f->minus)
		f->width -= ft_write(f, " ", 1);
	free(s);
}

void	hex_width(char *s, t_struct *f)
{
	if (f->hash && (f->or_width <= f->len || f->zero))
		f->ret += write(1, f->hash, 2);
	if (f->nul && f->hasdot && !f->dot && f->type == 'p' && f->width > f->len)
		f->width++;
	while (f->width > f->len && !f->minus)
		f->width -= ft_write(f, f->zero ? "0" : " ", 1);
	if (f->type == 'p')
		f->ret += write(1, "0x", 2);
	if (f->nul && f->hasdot && !f->dot)
		return (free(s));
	if (f->hash && f->or_width > f->len && !f->zero)
		f->ret += write(1, f->hash, 2);
	print_digit(s, f);
}

void	hex_precision(char *s, t_struct *f)
{
	if (f->type == 'p')
		f->ret += write(1, "0x", 2);
	if (f->hash)
		f->ret += write(1, f->hash, 2);
	while (f->dot > f->len)
		f->dot -= ft_write(f, "0", 1);
	print_digit(s, f);
}

void	hex_combi(char *s, t_struct *f)
{
	if (f->hasdot && f->dot < f->len)
	{
		f->hasdot = 0;
		f->zero = 0;
		return (hex_width(s, f));
	}
	if (f->width <= f->len)
		return (hex_precision(s, f));
	if (f->dot > f->width)
		f->width = f->dot;
	if (f->minus)
		f->width -= f->dot - f->len;
	while (!f->minus && f->width > f->dot)
		f->width -= ft_write(f, " ", 1);
	hex_precision(s, f);
}

void	digit_hex(char *s, t_struct *f)
{
	if (*s == '0')
		f->nul = 1;
	if (f->nul)
		f->hash = 0;
	if (f->hash && !f->nul)
		f->width -= 2;
	if (f->hash && f->type == 'X')
		f->hash = "0X";
	if (f->nul && f->hasdot && !f->dot && f->x)
		*s = ' ';
	if (*s == '0')
		f->hash = 0;
	if (f->width && !f->hasdot)
		hex_width(s, f);
	else if (f->hasdot && !f->width)
		hex_precision(s, f);
	else
		hex_combi(s, f);
}
