/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 05:57:04 by gfere             #+#    #+#             */
/*   Updated: 2024/04/07 15:58:10 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cp_env(char **envp)
{
	int		n;
	char	**new_env;

	n = 0;
	while (envp[n])
		n++;
	new_env = malloc(sizeof(char *) * (n + 1));
	n = 0;
	while (envp[n])
	{
		new_env[n] = ft_strdup(envp[n]);
		n++;
	}
	new_env[n] = NULL;
	return (new_env);
}
