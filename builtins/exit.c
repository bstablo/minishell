/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:09:33 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/12 06:50:38 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(t_global *global, char **str)
{
	int	j;
	int	i;

	i = 0;
	printf("exit\n");
	if (str[0])
	{
		if (!ft_num(str[0]))
		{
			ft_perror(global, "exit: ", str[0], 255);
			ft_perror(global, ": ", "numeric argument required\n", 255);
		}
		else
		{
			j = ft_atoi(str[0]);
			i = j % 256;
			exit(i);
		}
	}
	exit(global->status);
}
