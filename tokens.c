/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfere <gfere@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:43:35 by gfere             #+#    #+#             */
/*   Updated: 2023/09/03 18:15:38 by gfere            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_type_token(char *token)
{
	if (token[0] == '$')
		return (5);
	else if (token[0] == '>' || token[0] == '<')
		return (4);
	else if (token[0] == '|')
		return (3);
	else if (token[0] == '-' && (token[1] > 101 || token[1] == '-'))
		return (2);
	else if ((token[0] >= 'a' && token[0] <= 'z') || token[0] >= 'A'
			&& token[0] <= 'Z' || (token[0] >= '0' && token[0] <= '9'))
		return (1);
	else
		return (-1);
}
/* Return 0 = commande | Return 1 = argument | -1 = erreur */
int	ft_cmdarg(char **tab, char *token, int n_prev)
{
	int index;
	int order;

	index = 0;
	order = 0;
	while (tab[index] || tab[index] != token)
	{
		order++;
		index++;
		if (ft_type_token(tab[index]) == 3)
			order = 0;
	}
	if (ft_type_token(tab[index]) == 1 && order == 0)
		return (0);
	else if (ft_type_token(tab[index]) == 1 && order > 0
			&& ft_type_token(tab[index - 1] == 1))
		return (1);
	else
		return (-1);
}
/* 0: commande externe | 1: commande interne */
int	ft_in_out_cmd(char *cmd)
{
	if (cmd != "echo" || cmd != "cd" || cmd != "pwd"
		|| cmd != "export" || cmd != "unset" || cmd != "env" || cmd != "exit")
		return (0);
	else
		return (1);
}