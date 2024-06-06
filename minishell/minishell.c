/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:57:04 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/06 12:58:25 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rl_gets(void)
{
	static char	*line_read;
	char		*res;

	if (line_read)
	{
		free (line_read);
		line_read = (char *) NULL;
	}
	line_read = readline("minishell>> ");
	if (line_read && *line_read)
	{
		res = ft_strtrim(line_read, " \t\v\f\r");
		if (ft_strlen(res) > 0)
			add_history(res);
		free(res);
	}
	return (line_read);
}

char	*line_prompt(char *line, char **argv, int argc)
{
	(void)argc;
	(void)argv;
	if (!line)
		signal_exit();
	return (line);
}

void	init_global(t_global *global)
{
	global->indice = malloc(sizeof(int) * 1);
	global->indice[0] = 0;
	global->here = 0;
}

void	init(char **envp, t_exp *atc, t_list *alst, t_global *global)
{
	alst = NULL;
	atc = NULL;
	global->old_stdin = dup(STDIN_FILENO);
	global->old_stdout = dup(STDOUT_FILENO);
	insert_env(envp, &alst);
	insert_exp(envp, &atc);
	global->atc = atc;
}

int	main(int ac, char **av, char **envp)
{
	char		*line;
	t_exp		*atc;
	t_list		*alst;
	t_parse		*head;
	t_global	*global;

	init(&envp, &atc, &alst, &global);
	head = ft_new_parse(&global);
	while (1)
	{
		init_signals(&global);
		line = rl_gets();
		line = line_prompt(line, av, ac);
		init_global(&global);
		lexer(line, &head, &global);
		replacev(&head, &global);
		brain(alst, atc, &global);
		wronglastcmd(global->parse, alst);
		free_all();
	}
}
