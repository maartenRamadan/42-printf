/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_flags.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 16:13:49 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:34:33 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_type(const char **str, t_struct *f)
{
	char	*types;
	int		i;

	types = "cspdiuxX%f";
	i = 0;
	while (types[i] != '\0')
	{
		if (**str == types[i])
		{
			f->type = types[i];
			return (1);
		}
		i++;
	}
	return (0);
}

void	distribute_args(t_struct *f, va_list args)
{
	if (f->type == 'x' || f->type == 'X')
		f->x = 1;
	if (f->plus)
		f->space = 0;
	if (f->minus)
		f->zero = 0;
	if (f->type == 'c' || f->type == '%')
		print_char(f, args);
	else if (f->type == 's')
		handle_string_flags(f, args);
	else if (f->type == 'p')
		handle_ptr_flags(f, args);
	else
		handle_digit_flags(f, args);
}

void	check_precision(t_struct *f, const char **str, va_list args)
{
	f->hasdot = 1;
	if ((*str)[+1] >= '0' && (*str)[+1] <= '9')
	{
		(*str)++;
		f->dot = pf_ft_atoi(str);
	}
	else if ((*str)[+1] == '*')
	{
		(*str)++;
		f->dot = va_arg(args, int);
	}
	if (f->dot < 0)
	{
		f->dot = 0;
		f->hasdot = 0;
	}
}

void	check_width(t_struct *f, const char **str, va_list args)
{
	if (**str == '*')
		f->width = va_arg(args, int);
	else
		f->width = pf_ft_atoi(str);
	if (f->width < 0)
	{
		f->minus = 1;
		f->width *= -1;
	}
	f->or_width = f->width;
}

void	find_flags(const char **str, t_struct *f, va_list args)
{
	while (!check_type(str, f))
	{
		if (**str == '+')
			f->plus = 1;
		if (**str == '-')
			f->minus = 1;
		if (**str == ' ' && !f->plus)
			f->space = 1;
		if (**str == '0')
			f->zero = 1;
		if (**str == '#')
			f->hash = "0x";
		if (((**str > 47 && **str < 58) || **str == '*') && (*str)[-1] != '.')
			check_width(f, str, args);
		if (**str == '.')
			check_precision(f, str, args);
		if (**str == 'n')
			return (handle_n(args, f));
		if (**str == 'l')
			f->l = 1;
		(*str)++;
	}
	if (f->type == 'f')
		return ;
	distribute_args(f, args);
}
