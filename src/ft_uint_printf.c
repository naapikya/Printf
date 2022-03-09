/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:25:45 by naapikya          #+#    #+#             */
/*   Updated: 2021/07/12 14:20:12 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_in_put_part_uint(char *unsi_int, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1);
	char_count += ft_putstrprec(unsi_int, ft_strlen(unsi_int));
	return (char_count);
}

static int	ft_put_part_uint(char *unsi_int, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_uint(unsi_int, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(unsi_int))
		flags.dot = ft_strlen(unsi_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width,
				ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_uint(unsi_int, flags);
	return (char_count);
}

int	ft_treat_uint(unsigned int unsi, t_flags flags)
{
	char	*unsi_int;
	int		char_count;

	char_count = 0;
	unsi = (unsigned int)(4294967295 + 1
			+ unsi);
	if (flags.dot == 0 && unsi == 0)
	{
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	unsi_int = ft_u_itoa(unsi);
	char_count += ft_put_part_uint(unsi_int, flags);
	free(unsi_int);
	return (char_count);
}
