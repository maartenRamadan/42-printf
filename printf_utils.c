/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 08:34:25 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:35:53 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		pf_ft_bspace(void *s, size_t n)
{
	size_t		i;
	char		*tmp;

	tmp = (char*)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
}

void		*pf_ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size + 1);
	if (!ptr)
		return (0);
	pf_ft_bspace(ptr, (size * count));
	return (ptr);
}

char		*pf_ft_strdup(const char *s1, t_struct *f)
{
	int		i;
	char	*str2;
	char	*s2;

	s2 = NULL;
	i = 0;
	if (f->hasdot && f->dot == 0 && f->width > 0)
		s2 = pf_ft_calloc(1, (size_t)f->width);
	else if (!s1)
		s2 = pf_ft_strdup("(null)", f);
	if (s2 && (!s1 || (f->hasdot && f->dot == 0 && f->width > 0)))
		return (s2);
	str2 = malloc(sizeof(*str2) * (pf_ft_strlen(s1) + 1));
	if (!str2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str2[i] = s1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

long long	pf_count_len(long long n)
{
	int len;

	len = (n == 0);
	if (n > 0)
		n *= -1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*pf_ft_itoa(long long n, t_struct *f)
{
	char		*str;
	int			len;

	len = pf_count_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		f->neg = 1;
	if (n > 0)
		n *= -1;
	while (n)
	{
		len--;
		str[len] = -(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
