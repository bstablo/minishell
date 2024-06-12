/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:51:18 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/10 14:23:16 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_flag(char *line, int i, t_parse *head)
{
	int		j;
	char	*nextw;
	char	*tmp;

	i++;
	j = i;
	nextw = nextword(line + i, &j);
	if (head->first == 0)
	{
		tmp = ft_strdup("-");
		head->cmd = ft_strjoin_no_spc(tmp, nextw);
		head->first++;
	}
	else
		head->flag = ft_strjoin_no_spc(head->flag, nextw);
	return (j);
}

t_parse	*ft_new_parse(t_global *global)
{
	t_parse	*newlist;

	global->indice[0] += 1;
	newlist = malloc(sizeof(t_parse));
	if (!newlist)
		return (NULL);
	newlist->first = 0;
	newlist->indice = global->indice[0];
	newlist->infile = 0;
	newlist->i = 0;
	newlist->outfile = 1;
	newlist->fd_kill = 0;
	newlist->next = NULL;
	newlist->flag = ft_strncpy("-", 1);
	newlist->arg = malloc(sizeof(char *));
	newlist->arg[0] = NULL;
	newlist->cmd = NULL;
	newlist->sfile = NULL;
	newlist->exit_code = 0;
	return (newlist);
}

void	lexer(char *line, t_global *global)
{
	int		i;
	t_parse	*head;

	i = 0;
	head = global->parse;
	while (line[i])
	{
		while ((line[i] && (line[i] == ' ' || line[i] == '\t')))
			i++;
		if (line[i] == 34 || line[i] == 39)
			i = handle_quotes(line, i, head);
		else if (line[i] == 62)
			i = redirect_opening(line, i, head, global);
		else if (line[i] == 60)
			i = redirect_closing(line, i, head, global);
		else if (line[i] == 45 && line[i + 1] != 45 && head->arg[0] == NULL)
			i = ft_flag(line, i, head);
		else if (line[i] == 124)
			head = ft_pipe(head, &i, global);
		else
			i = ft_cmd_arg(line, i, head);
	}
	if (head->sfile == NULL || !head->sfile)
		head->sfile = ft_strdup("NOinfile");
}
