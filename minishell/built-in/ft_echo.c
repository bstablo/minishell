/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:08:07 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/06 13:07:58 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo_option(char **cmd)
{
	int	x;

	x = 2;
	while (cmd[1][x])
	{
		while (cmd[1][x] == 'n')
			x++;
		if (cmd[1][x] == '\0')
		{
			ft_print_args(cmd, 2, 1);
			return ;
		}
		else if (cmd[1][x] != 'n' || cmd[1][x] != '\0')
		{
			ft_print_args(cmd, 1, 0);
			return ;
		}
	}
}

void	ft_echo(char **cmd, t_global *global)
{
	int	n;

	n = 1;
	if (cmd[n])
	{
		if (cmd[1][0] == '-' && cmd[1][1] == 'n')
		{
			if (cmd[1][2])
				ft_echo_option(cmd);
			else
			{
				n++;
				ft_print_args(cmd, n, 1);
			}
			else
				ft_print_args(cmd, n, 0);
		}
		global->status = 0;
	}
}
