/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:09:56 by bstablo           #+#    #+#             */
/*   Updated: 2023/09/03 17:49:07 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quotes(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		if (str[n] == 34)
		{
			while (str[++n] != 34)
				if (str[n] == '\0')
					return (-1);
		}
		else if (str[n] == 39)
		{
			while (str[++n] != 39)
				if (str[n] == '\0')
					return (-1);
		}
		n++;
	}
	return (0);
}
