/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:47:49 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/12 06:50:49 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	killhere(t_global *global)
{
	t_parse	*tete;

	tete = global->parse;
	while (tete)
	{
		if (tete->fd_kill > 0)
		{
			close(tete->fd_kill);
		}
		tete = tete->next;
	}
	unlink("/tmp/heredoc.tmp");
}

void	free_all(t_global *global)
{
	t_parse	*tete;
	t_parse	*tmp;

	tete = global->parse;
	killhere(global);
	while (tete)
	{
		tmp = tete->next;
		free_tab(tete->arg);
		free(tete->cmd);
		free(tete->flag);
		if (tete->infile != 0)
			close(tete->infile);
		if (tete->outfile != 1)
			close(tete->outfile);
		free(tete->sfile);
		free(tete);
		tete = tmp;
	}
	free(global->indice);
	dup2(global->old_stdin, STDIN_FILENO);
	dup2(global->old_stdout, STDOUT_FILENO);
}
