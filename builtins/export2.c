/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:54:45 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/11 11:44:12 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_find_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_prt(char *str)
{
	char	*prt;
	int		i;

	i = 0;
	while ((str[i] != '+' && str[i + 1] != '=') && str[i] != '=')
		i++;
	prt = malloc(sizeof(char *) * i + 1);
	i = -1;
	while (str[i] != '+' && str[i] != '=')
	{
		prt[i] = str[i];
		i++;
	}
	prt[i] = '\0';
	return (prt);
}

char	*ft_prt2(char *str)
{
	char	*prt2;
	int		i;
	int		j;
	int		r;

	i = 0;
	j = 0;
	while (str[i] != '=')
		i++;
	r = i;
	while (str[i++])
		j++;
	prt2 = malloc(sizeof(char *) * j);
	j = 0;
	r++;
	while (str[r])
	{
		prt2[j] = str[r];
		r++;
		j++;
	}
	return (prt2);
}

void	print_exp(t_exp *exp)
{
	t_exp	*temp;

	temp = exp;
	while (temp)
	{
		if (temp->content == NULL)
			printf("declare -x %s=\"\" \n", temp->name);
		else if (!ft_strcmp(temp->content, "(null)"))
			printf("declare -x %s \n", temp->name);
		else
			printf("declare -x %s=\"%s\" \n", temp->name, (char *)temp->content);
		temp = temp->next;
	}
}
