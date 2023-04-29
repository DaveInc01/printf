/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuphex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:33:53 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/05/04 21:17:17 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuphex(unsigned int num)
{
	int				len;
	int				j;
	char			outbuf[100];

	if (num == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	j = 0;
	while (num != 0)
	{
		outbuf[j++] = "0123456789ABCDEF"[num % 16];
		num = num / 16;
	}
	len = j;
	while (--j >= 0)
		write(1, &outbuf[j], 1);
	return (len);
}
