/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:09:56 by bstablo           #+#    #+#             */
/*   Updated: 2023/09/03 17:18:35 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quotes(char *str)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	j = 0;
	while (str[n])
	{
		if (str[n] == 34)
			i++;
		else if (str[n] == 39)
			j++;
		n++;
	}
	if (i % 2 != 0 || j % 2 != 0)
		return (-1);
	return (0);
}