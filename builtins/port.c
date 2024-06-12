/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   port.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:03:39 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/06 14:37:55 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_port(t_global *global, t_exp *exp, t_lst *lst)
{
	t_parse	*temp;
	int		p;

	temp = global->parse;
	p = 0;
	if (temp->arg[0] == NULL)
		ft_export(global, exp);
	else
	{
		while (temp->arg[p])
		{
			ft_port2(lst, temp, p, exp);
			p++;
		}
	}
}

void	ft_port2(t_lst *lst, t_parse *parse, int p, t_exp *exp)
{
	int	i;

	i = check(parse->arg[p]);
	if (i == 0)
		printf("export: `%s': not a valid identifier\n", parse->arg[p]);
	else
	{
		if (i == 1)
		{
			add(exp, parse->arg[p]);
			add2(lst, parse->arg[p]);
		}
		else if (i == 2)
			add3(exp, parse->arg[p]);
		else if (i == 3)
		{
			add4(exp, parse->arg[p]);
			add5(lst, parse->arg[p]);
		}
		else
		{
			add6(exp, parse->arg[p]);
			add7(lst, parse->arg[p]);
		}
	}
}

int	check(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	return (check2(str, i, j));
}

int	check2(char *str, int i, int j)
{
	int		t;
	int		r;

	t = 0;
	r = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[0]))
			return (0);
		if (str[i] == '+' && j == 0)
			r++;
		if (str[i] == '-' || r > 1)
			return (0);
		if (str[i] == '=' && str[i - 1] == '+' && j == 0)
			t++;
		if (str[i] == '=')
		{
			j++;
			while (str[i] == '=')
				i++;
		}
		i++;
	}
	return (check3(j, t));
}

int	check3(int j, int t)
{
	if (t != 0)
		return (4);
	if (j == 0)
		return (2);
	if (j > 1)
		return (3);
	return (1);
}
