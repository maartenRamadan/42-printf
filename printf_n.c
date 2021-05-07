/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_n.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 10:10:10 by mramadan       #+#    #+#                */
/*   Updated: 2019/12/20 10:10:46 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	handle_n(va_list args, t_struct *f)
{
	int *ptr;

	ptr = va_arg(args, int *);
	ptr[0] = f->ret;
}
