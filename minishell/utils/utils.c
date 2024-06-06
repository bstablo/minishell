/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:11:58 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/06 12:41:33 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	len_envp(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (0);
	while (envp && envp[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	nb;
	int	signe;

	n = 0;
	nb = 0;
	signe = 1;
	while (str[n] == ' ' || str[n] == '\t' || str[n] == '\r'
		|| str[n] == '\n' || str[n] == '\v' || str[n] == '\f')
		n++;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			signe *= -1;
		n++;
	}
	while (str[n] >= '0' && str[n] <= '9')
	{
		nb = nb * 10 + (str[n] - 48);
		n++;
	}
	if (nb)
		return (nb * signe);
	return (0);
}

char	**list_to_array(t_parse *head)
{
	int		count;
	char	**env;
	t_parse	*current;

	count = 0;
	current = head;
	while (current)
	{
		count++;
		current = current->next;
	}
	env = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!env)
		exit(EXIT_FAILURE);
	current = head;
	env = make_env(env, current);
	return (env);
}
