/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:23:08 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/06 12:34:38 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*repelse(int *i, const char *res, char *str)
{
	int		size;
	char	*result;

	size = count_symbol(str + *i, "\'\"$");
	result = ft_strjoin_no_spc(res, ft_strdup2(str + *i, size));
	*i += size;
	return (result);
}

char	*inexpand(int *i, const char *res, char *str, t_global *global)
{
	char	*tmp;

	if (str[*i] == '\'')
	{
		*i += 1;
		tmp = quote_found(i, res, str);
	}
	else if (str[*i] == '\"')
	{
		*i += 1;
		tmp = dblquotes_found(i, res, str, global);
	}
	else
	{
		*i += 1;
		tmp = dollar_found(i, res, str, global);
	}
	return (tmp);
}

char	*ft_expand(char *str, t_global *global)
{
	char	*res;
	int		i;

	res = ft_strdup("");
	i = 0;
	while (str && str[i])
	{
		if (find(str[i], "\'\"$") == 1)
			res = inexpand(&i, res, str, global);
		else
			res = repelse(&i, res, str);
	}
	free(str);
	return (res);
}

void	replacev(t_parse *head, t_global *global)
{
	int		i;

	i = 0;
	head = global->parse;
	while (head)
	{
		if (head->cmd)
			head->cmd = ft_expand(head->cmd, global);
		if (head->flag && ft_strlen(head->flag) > 1)
			head->flag = ft_expand(head->flag, global);
		while (head->arg && head->arg[i])
		{
			head->arg[i] = ft_expand(head->arg[i], global);
			i++;
		}
		i = 0;
		head = head->next;
	}
}
