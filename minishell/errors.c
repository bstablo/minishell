/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:44:04 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/04 17:18:01 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	ft_perror(t_global *global, char *s1, char *s2, int index)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	global->status = index;
}

void	ft_err_execve(t_global *global, t_parse *parse)
{
	if (parse->infile < 0)
	{
		perror(parse->infile);
		return ;
	}
	if (parse->cmd[0] == '/')
		ft_perror(global, parse->cmd, ": No such file or directory\n", 127);
	else
		ft_perror(global, parse->cmd, ": command not found\n", 127);
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}
