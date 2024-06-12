/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:43:45 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/12 06:12:47 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*trflag(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = ft_calloc(sizeof(char), ft_strlen(str));
	while (str && str[i])
	{
		if (i != 1)
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);
	return (res);
}

int	check_quotes(char *str, int i)
{
	char	indic;

	if (str[i] == 34)
		indic = str[i];
	else if (str[i] == 39)
		indic = str[i];
	else
	{
		return (i + 1);
	}
	if (str[i + 1])
		i++;
	while (str[i] && str[i] != indic)
		i++;
	if (str[i] != indic)
		msg_error("unclosed quotes");
	i++;
	return (i);
}

int	handle_quotes(char *line, int i, t_parse *parse)
{
	int		j;
	char	*nextw;

	j = i;
	nextw = nextword(line + i, &j);
	if (nextw[1] == '-' && nextw[2] != '-')
	{
		nextw = trflag(nextw);
		parse->flag = ft_strjoin_no_spc(parse->flag, nextw);
	}
	else if (parse->first == 0)
	{
		parse->cmd = nextw;
		parse->first++;
	}
	else
	{
		i = len_envp(parse->arg);
		parse->arg = ft_realloc2char(parse->arg, len_envp(parse->arg) + 1, 0);
		parse->arg[i] = nextw;
	}
	return (j);
}
