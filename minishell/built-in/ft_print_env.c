/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:10:25 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/06 18:25:55 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_theres_equal(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_env(char **env, t_global *global)
{
	int	n;

	n = 0;
	while (env[n])
	{
		if (ft_theres_equal(env[n]) == 1)
			printf("%s\n", env[n]);
		n++;
	}
	global->status = 0;
}
