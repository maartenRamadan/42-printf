/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 15:36:09 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/10 12:06:20 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	zero_flags(t_struct *f)
{
	f->minus = 0;
	f->plus = 0;
	f->zero = 0;
	f->space = 0;
	f->width = 0;
	f->hasdot = 0;
	f->dot = 0;
	f->type = 0;
	f->neg = 0;
	f->nul = 0;
	f->n = 0;
	f->hash = 0;
	f->x = 0;
	f->l = 0;
	f->len = 0;
	f->or_len = 0;
}

void	write_non_arg(const char **str, t_struct *f)
{
	while (**str != '%' && **str != '\0')
	{
		f->ret += write(1, *str, 1);
		(*str)++;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list			args;
	t_struct		*f;

	f = malloc(sizeof(t_struct));
	f->ret = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%' && *str != '\0')
			write_non_arg(&str, f);
		if (*str == '%')
		{
			str++;
			zero_flags(f);
			find_flags(&str, f, args);
		}
		if (*str == '\0')
			break ;
		str++;
	}
	va_end(args);
	free(f);
	return (f->ret);
}
