/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:08:07 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/11 11:26:28 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	echo_check_flag(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 1)
		return (0);
	while (str[i])
	{
		if (str[i] != '-' && str[i] != 'n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	helpecho(t_parse *parse, int *j)
{
	if (echo_check_flag(parse->flag) == 1 && *j > 0)
		return (0);
	if (echo_check_flag(parse->flag) == 1 && *j == 0)
	{
		printf("%s", parse->flag);
		*j += 1;
		return (0);
	}
	else if (ft_strlen(parse->flag) == 1)
		return (0);
	return (1);
}

void	ft_echo(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	helpecho(parse, &j);
	while (parse->arg && parse->arg[i])
	{
		if (j == 0 && parse->arg[i][0])
		{
			j = 1;
			printf("%s", parse->arg[i]);
		}
		else if (parse->arg[i][0])
			printf(" %s", parse->arg[i]);
		i++;
	}
	if (helpecho(parse, &j) == 0)
		printf("\n");
}
