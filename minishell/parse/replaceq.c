/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:26:25 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/06 12:36:14 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*quote_found(int *i, const char *res, char *str)
{
	int		size;
	char	*result;
	char	*tmp;

	size = count_symbol(str + *i, "\'");
	if (size == 0)
	{
		*i += 1;
		return ((char *)res);
	}
	tmp = ft_strdup2(str + *i, size);
	result = ft_strjoin_no_spc(res, tmp);
	*i += size + 1;
	return (result);
}

char	*dblquotes_found(int *i, const char *res, char *str, t_global *global)
{
	char	*result;
	int		t;

	t = 0;
	if (str[*i] == '\"')
		return (dblquotesdollar(i, res));
	while (str[*i] != '\"' && str[*i])
	{
		if (str[*i] == '$')
		{
			*i += 1;
			if (t == 0)
			{
				t++;
				result = dollar_found_after_dblq(i, res, str, global);
			}
			else
				result = dollar_found_after_dblq(i, result, str, global);
		}
		else
			result = else_dbl(i, res, str, &t);
	}
	*i += 1;
	return (result);
}

char	*dollar_found_after_dblq(
		int *i, const char *res, char *str, t_global *global)
{
	int		size;
	char	*result;
	char	*tmp;

	if (str[*i] == '?')
	{
		*i += 1;
		tmp = ft_strjoin_no_spc(res, ft_itoa(global->status));
		return (tmp);
	}
	if (str[*i] == '\"' || str[*i] == ' ')
	{
		*i += 1;
		tmp = ft_strjoin_no_spc(res, ft_strdup("$"));
		return (tmp);
	}
	size = count_symbol(str + *i, "\'\"$ ");
	if (size == 0)
		return ((char *)res);
	tmp = ft_strdup2(str + *i, size);
	result = ft_strdup(findexp(global->atc, tmp));
	result = ft_strjoin_no_spc(res, result);
	*i += size;
	free(tmp);
	return (result);
}

char	*dollar_found(int *i, const char *res, char *str, t_global *global)
{
	int		size;
	char	*result;
	char	*tmp;

	if (str[*i] == '?')
	{
		*i += 1;
		tmp = ft_strjoin_no_spc(res, ft_itoa(global->status));
		return (tmp);
	}
	if (str[*i] == '\0')
	{
		*i += 1;
		tmp = ft_strjoin_no_spc(res, ft_strdup("$"));
		return (tmp);
	}
	size = count_symbol(str + *i, "\'\"$ ");
	if (size == 0)
		return ((char *)res);
	tmp = ft_strdup2(str + *i, size);
	result = ft_strdup(findexp(global->atc, tmp));
	result = ft_strjoin_no_spc(res, result);
	*i += size;
	free(tmp);
	return (result);
}

char	*else_dbl(int *i, const char *res, char *str, int *t)
{
	int		size;
	char	*result;

	result = NULL;
	size = count_symbol(str + *i, "\"$");
	if (*t == 0)
		result = ft_strjoin_no_spc(res, ft_strdup2(str + *i, size));
	else
		result = ft_strjoin_no_spc(result, ft_strdup2(str + *i, size));
	*t += 1;
	*i += size;
	return (result);
}
