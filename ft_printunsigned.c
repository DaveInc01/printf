/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:33:51 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/05/06 18:52:11 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnumber(unsigned int num, int *count)
{
	if (num < 10)
	{
		ft_putchar_fd(num + '0', 1);
		(*count)++;
	}
	else
	{
		ft_printnumber(num / 10, count);
		ft_putchar_fd(num % 10 + '0', 1);
		(*count)++;
	}
}

int	ft_printunsigned(unsigned int num)
{
	int	count;

	count = 0;
	ft_printnumber(num, &count);
	return (count);
}
