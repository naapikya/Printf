/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:51:44 by naapikya          #+#    #+#             */
/*   Updated: 2021/07/12 14:16:14 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_put_part_int(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot >= 0)
	{
		char_count += ft_treat_width(flags.dot, ft_strlen(str), 0);
		char_count += ft_putstrprec(str, flags.dot);
	}
	else
	{
		char_count += ft_putstrprec(str, ft_strlen(str));
	}
	return (char_count);
}

int	ft_treat_string(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_put_part_int(str, flags);
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.width, flags.dot, 0);
	else
	{
		if (flags.zero == 0)
			char_count += ft_treat_width(flags.width, ft_strlen(str), 0);
		else
			char_count += ft_treat_width(flags.width, ft_strlen(str), 1);
	}
	if (flags.minus == 0)
		char_count += ft_put_part_int(str, flags);
	return (char_count);
}
