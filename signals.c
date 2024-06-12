/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:45:01 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/12 04:53:24 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

// void	echo_control_seq(int i)
// {
// 	struct termios	conf;

// 	ioctl(ttyslot(), TIOCGETA, &conf);
// 	if (i == 1)
// 		conf.c_lflag |= ECHOCTL;
// 	else if (i == 0)
// 		conf.c_lflag &= ~(ECHOCTL);
// 	ioctl(ttyslot(), TIOCSETA, &conf);
// }

extern int g_sig;

void	ft_signal(int signum)
{
	(void)signum;
	if (g_sig == 1)
	{
		printf("\r");
		write (1, "\n", 1);
		close(0);
	}
	else
	{
		rl_replace_line("", 0);
		printf("\n");
		if (rl_done)
			return ;
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_signalquit(int signum)
{
	(void)signum;
	if (rl_done)
	{
		printf("Quit: 3\n");
		return ;
	}
	printf("\e[2K");
	rl_on_new_line();
	rl_redisplay();
}

void	signal_exit(void)
{
	printf("\033[1A");
	printf("%s", rl_prompt);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}

int	exitstatus(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	else if (WIFSTOPPED(status))
		return (WTERMSIG(status) + 128);
	return (0);
}
