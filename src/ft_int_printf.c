/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:34:58 by naapikya          #+#    #+#             */
/*   Updated: 2021/07/12 14:10:27 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_in_put_part_int(int i, char *d_i, int save_i, t_flags flags)
{
	int		char_count;
	char	*Narye;

	char_count = 0;
	if (save_i < 0 && flags.dot >= 0 && i != -2147483648)
		ft_putchar_pft('-');
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(d_i) - 1, 1);
	if (i == -2147483648)
	{
		Narye = "2147483648";
		if (flags.zelandakan != 1)
			char_count += ft_putchar_pft('-');
		char_count += ft_putstrprec(Narye, ft_strlen(Narye));
	}
	else
		char_count += ft_putstrprec(d_i, ft_strlen(d_i));
	return (char_count);
}

static int	ft_put_part_int(int i, char *d_i, int save_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_int(i, d_i, save_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
		if (i == -2147483648)
		{
			ft_putchar_pft(' ');
			char_count++;
		}
	}
	else
		char_count += ft_treat_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_int(i, d_i, save_i, flags);
	return (char_count);
}

t_flags	Nare2(t_flags flags, int i)
{
	if (flags.zero == 1 && flags.dot == -1 && i != -2147483648)
		ft_putstrprec("-", 1);
	if (flags.zero == 1 && flags.dot == -1 && i != -2147483648)
		flags.zelandakan = 1;
	flags.zero = 1;
	return (flags);
}

int	ft_treat_int(int i, t_flags flags)
{
	char	*d_i;
	int		save_i;
	int		char_count;

	save_i = i;
	char_count = 0;
	if (flags.dot == 0 && i == 0)
		char_count += ft_treat_width(flags.width, 0, 0);
	if (flags.dot == 0 && i == 0)
		return (char_count);
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		flags = Nare2(flags, i);
		i *= -1;
		flags.width--;
		if (i != -2147483648)
			char_count++;
	}
	d_i = ft_itoa(i);
	char_count += ft_put_part_int(i, d_i, save_i, flags);
	free(d_i);
	return (char_count);
}
