/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:19:12 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/12 06:41:12 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	brain(t_global *global, t_lst *lst)
{
	t_parse	*parse;

	init_signals();
	parse = global->parse;
	// echo_control_seq(1);
	if (cmdin_parse(global, parse) == 1)
		return ;
	else if (parse->indice == len_parse(global))
	{
		if (parse->infile < 0)
		{
			perror(parse->sfile);
			return ;
		}
		dup2(parse->infile, STDIN_FILENO);
		dup2(parse->outfile, STDOUT_FILENO);
		exec_lab(global, parse, lst);
	}
	else
		ft_fils(global, parse, lst, parse->infile);
}

void	exec_lab(t_global *global, t_parse *parse, t_lst *lst)
{
	char	**lab;

	lab = NULL;
	lab = check_elem(global, parse, lst, lab);
	if (len_parse(global) == 1)
		exec_cmd(global, parse, lst, lab);
	else
	{
		exec_cmdmulti(global, parse, lst, lab);
		free_tab(lab);
		exit(0);
	}
	free_tab(lab);
}

void	ft_fils(t_global *global, t_parse *parse, t_lst *lst, int fdin)
{
	pid_t	pid;
	int		fd[2];
	int		t;

	if (!parse)
		return ;
	if (pipe(fd) == -1)
		msg_error("pipe error\n");
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dupfunction(global, parse, fd, fdin);
		exec_lab(global, parse, lst);
	}
	else
	{
		close(fd[1]);
		ft_fils(global, parse->next, lst, fd[0]);
		close(fd[0]);
		waitpid(pid, &parse->exit_code, 0);
		t = exitstatus(parse->exit_code);
		if (parse->indice == len_parse(global))
			global->status = t;
	}
}

void	exec_cmd(t_global *global, t_parse *parse, t_lst *lst, char **lab)
{
	if (!ft_strcmp(parse->cmd, "exit"))
		ft_exit(global, parse->arg);
	else if (!ft_strcmp(tolower2(parse->cmd), "env"))
		print_list(global, lst);
	else if (!ft_strcmp(tolower2(parse->cmd), "echo"))
		ft_echo(parse);
	else if (!ft_strcmp(tolower2(parse->cmd), "pwd"))
		ft_pwd();
	else if (!ft_strncmp(parse->cmd, "cd", 2))
		ft_cd(global, parse, lst);
	else if (!ft_strcmp(parse->cmd, "unset"))
		ft_unset(global, &lst, &(global->exp));
	else if (!ft_strcmp(parse->cmd, "export"))
		ft_port(global, global->exp, lst);
	else
	{
		if (!ft_strncmp(parse->cmd, "grep", 5)
			|| !ft_strncmp(parse->cmd, "cat", 4))
			signal(SIGQUIT, ft_signalquit);
		ft_execve(global, parse, lst, lab);
	}
}

void	exec_cmdmulti(t_global *global, t_parse *parse, t_lst *lst, char **lab)
{
	char	**tmp;

	if (!ft_strcmp(parse->cmd, "exit"))
		ft_exit(global, parse->arg);
	else if (!ft_strcmp(tolower2(parse->cmd), "env"))
		print_list(global, lst);
	else if (!ft_strcmp(tolower2(parse->cmd), "echo"))
		ft_echo(parse);
	else if (!ft_strcmp(tolower2(parse->cmd), "pwd"))
		ft_pwd();
	else if (!ft_strncmp(parse->cmd, "cd", 2))
		ft_cd(global, parse, lst);
	else if (!ft_strcmp(parse->cmd, "unset"))
		ft_unset(global, &lst, &(global->exp));
	else if (!ft_strcmp(parse->cmd, "export"))
		ft_port(global, global->exp, lst);
	else
	{
		if (!ft_strncmp(parse->cmd, "grep", 5)
			|| !ft_strncmp(parse->cmd, "cat", 4))
			signal(SIGQUIT, SIG_DFL);
		tmp = enov(lst);
		if (execve(lab[0], lab, tmp) == -1)
			ft_err_execve(global, parse);
		free_tab(tmp);
	}
}
