/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_digit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 15:00:42 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:34:17 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		digit_width(char *s, t_struct *f)
{
	if (f->space && (f->minus || f->zero))
	{
		f->width -= ft_write(f, f->neg ? "-" : " ", 1);
		f->neg = 0;
	}
	if ((f->plus || f->neg) && !f->space)
		f->width--;
	if ((f->plus || f->neg) && f->zero)
		f->ret += write(1, f->plus ? "+" : "-", 1);
	if (f->space && f->neg)
		f->width--;
	while (!f->hasdot && f->width > f->len && !f->minus)
		f->width -= ft_write(f, f->zero ? "0" : " ", 1);
	if ((f->plus || f->neg) && !f->zero && !f->space)
		f->ret += write(1, (f->plus && !f->neg) ? "+" : "-", 1);
	if (f->space && f->neg)
		f->ret += write(1, "-", 1);
	print_digit(s, f);
}

void		digit_precision(char *s, t_struct *f)
{
	if (f->plus || f->neg)
		f->ret += write(1, (f->plus && !f->neg) ? "+" : "-", 1);
	if (f->space && !f->neg)
		f->ret += write(1, f->plus ? "+" : " ", 1);
	while (f->dot > f->len)
		f->dot -= ft_write(f, "0", 1);
	print_digit(s, f);
}

void		digit_combi(char *s, t_struct *f)
{
	if (f->hasdot && f->dot < f->len)
	{
		f->hasdot = 0;
		f->zero = 0;
		return (digit_width(s, f));
	}
	if (f->width <= f->len)
		return (digit_precision(s, f));
	if (f->minus)
		f->width -= f->dot - f->len;
	if (f->dot > f->or_width)
		f->width = 0;
	if (f->plus || f->neg || f->space)
		f->width--;
	while (!f->minus && f->width > f->dot)
		f->width -= ft_write(f, " ", 1);
	digit_precision(s, f);
}

long long	pull_argument(va_list args, t_struct *f)
{
	long long		nb1;
	int				nb2;
	unsigned int	nb3;

	if (f->l)
	{
		nb1 = va_arg(args, long long);
		return (nb1);
	}
	else if (f->x)
	{
		nb3 = va_arg(args, unsigned int);
		return (nb3);
	}
	else
	{
		nb2 = va_arg(args, int);
		return (nb2);
	}
	return (0);
}

void		handle_digit_flags(t_struct *f, va_list args)
{
	char	*s;

	if (f->type == 'u')
		s = pf_ft_itou(va_arg(args, unsigned int), f);
	else
		s = (f->x) ? pf_itohex(pull_argument(args, f), f)
		: pf_ft_itoa(pull_argument(args, f), f);
	f->len = (int)pf_ft_strlen(s);
	if (*s == '0' && f->space && f->hasdot && f->dot == 0)
		f->ret += write(1, " ", 1);
	if (f->width <= f->len)
		f->width = 0;
	if (*s == '0' && f->hasdot && !f->dot)
		*s = f->width ? ' ' : '\0';
	if (f->hash)
		digit_hex(s, f);
	else if (f->width && !f->hasdot)
		digit_width(s, f);
	else if (f->hasdot && !f->width)
		digit_precision(s, f);
	else
		digit_combi(s, f);
}
