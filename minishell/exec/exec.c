/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:19:12 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/04 17:54:43 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	brain(t_global *global, t_list *lst, t_exp *exp)
{
	t_parse	*elem;

	init_signals(global);
	elem = global->parse;
	echo_control_seq(1);
	if (cmdin_parse(global, elem) == 1)
		return ;
	else if (elem->indice == len_parse(global))
	{
		if (elem->infile < 0)
		{
			perror(elem->sfile);
			return ;
		}
		dup2(elem->infile, STDIN_FILENO);
		dup2(elem->outfile, STDOUT_FILENO);
		exec_lab(global, elem, lst, exp);
	}
	else
		ft_fils(global, elem, lst, exp, elem->infile);
}

void	exec_lab(t_global *global, t_parse *elem, t_list *lst, t_exp *exp)
{
	char	**lab;

	lab = NULL;
	lab = check_elem(global, elem, lst, lab);
	if (len_parse(global) == 1)
		exec_cmd(global, elem, lst, exp, lab);
	else
	{
		exec_cmdmulti(global, elem, lst, exp, lab);
		free_tab(lab);
		exit(0);
	}
}

void	ft_fils(t_global *global, t_parse *elem, t_list *lst, t_exp *exp, int fdin)
{
	pid_t	pid;
	int		fd[2];
	int		t;

	if (!elem)
		return ;
	if (pipe(fd) == -1)
		msg_error("pipe error\n");
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dupfunction(global, elem, fd, fdin);
		exec_lab(global, elem, lst, exp);
	}
	else
	{
		close(fd[1]);
		ft_fils(global, elem->next, lst, exp, fd[0]);
		close(fd[0]);
		waitpid(pid, &elem->exit_code, 0);
		t = exitstatus(elem->exit_code);
		if (elem->indice == len_parse(global))
			global->status = t;
	}
}

void	exec_cmd(t_global *global, t_parse *parse, t_list *lst, t_exp *exp, char **lab)
{
/*	if (!ft_strcmp(parse->cmd, "exit"))
		ft_exit(parse->arg);
	else if (!ft_strcmp(tolower2(parse->cmd), "env"))
		print_list(lst);
	else if (!ft_strcmp(tolower2(parse->cmd), "echo"))
		ft_echo(parse);
	else if (!ft_strcmp(tolower2(parse->cmd), "pwd"))
		ft_pwd();
	else if (!ft_strcmp(parse->cmd, "cd", 2))
		ft_cd(parse, lst);
	else if (!ft_strcmp(parse->cmd, "unset"))
		ft_unset(&lst, &exp);
	else if (!ft_strcmp(parse->cmd, "export"))
		ft_export(exp, lst);
	else */
		ft_execve(global, parse, lst, lab);
}

void	exec_cmdmulti(t_global *global, t_parse *parse, t_list *lst, t_exp *exp, char **lab)
{
/*	if (!ft_strcmp(parse->cmd, "exit"))
		ft_exit(parse->arg);
	else if (!ft_strcmp(tolower2(parse->cmd), "env"))
		print_list(lst);
	else if (!ft_strcmp(tolower2(parse->cmd), "echo"))
		ft_echo(parse);
	else if (!ft_strcmp(tolower2(parse->cmd), "pwd"))
		ft_pwd();
	else if (!ft_strcmp(parse->cmd, "cd", 2))
		ft_cd(parse, lst);
	else if (!ft_strcmp(parse->cmd, "unset"))
		ft_unset(&lst, &exp);
	else if (!ft_strcmp(parse->cmd, "export"))
		ft_export(exp, lst);
	else
	{
		if (execve(lab[0], lab, enov(lst)) == -1) */
			ft_err_execve(global, parse);
//	}
}
