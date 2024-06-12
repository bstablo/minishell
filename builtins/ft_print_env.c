/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:10:25 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/11 22:25:48 by dcarenou         ###   ########.fr       */
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

void	ft_print_env(t_global *global, char **env)
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
