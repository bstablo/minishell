/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:03:00 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/12 06:14:31 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int g_sig;

void	init_signals(void)
{
	signal(SIGINT, ft_signal);
	signal(SIGQUIT, SIG_IGN);
}

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

void	init_global(t_global *global)
{
	global->parse = NULL;
	global->indice = malloc(sizeof(int) * 1);
	global->indice[0] = 0;
}

void	init(char **envp, t_exp *exp, t_lst *lst, t_global *global)
{
	lst = NULL;
	exp = NULL;
	global->old_stdin = dup(STDIN_FILENO);
	global->old_stdout = dup(STDOUT_FILENO);
	insert_env(envp, &lst);
	insert_exp(envp, &exp);
	global->exp = exp;
}

t_lst	*ft_lstlast2(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back2(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast2(*lst);
		tmp->next = new;
	}
}

t_lst	*ft_lstnew2(void *content, char *key)
{
	t_lst	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = content;
	element->name = key;
	element->next = NULL;
	return (element);
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_global	global;

	global.exp = NULL;
	global.lst = NULL;
	global.old_stdin = dup(STDIN_FILENO);
	global.old_stdout = dup(STDOUT_FILENO);
	insert_env(envp, &global.lst);
	insert_exp(envp, &global.exp);
	g_sig = 0;
	while (1)
	{
		init_signals();
		line = rl_gets();
		line = line_prompt(line, argv, argc);
		init_global(&global);
		global.parse = ft_new_parse(&global);
		lexer(line, &global);
		replacev(&global);
		brain(&global, global.lst);
		wronglastcmd(&global, global.parse, global.lst);
		free_all(&global);
	}
}
