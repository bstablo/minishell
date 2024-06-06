/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:45:01 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/04 17:36:42 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	init_signals(t_global *global)
{
	signal(SIGINT, ft_signal(global));
	signal(SIGQUIT, ft_signalquit(global));
	echo_control_seq(0);
}

void	echo_control_seq(int i)
{
	struct termios	conf;

	ioctl(ttyslot(), TIOCGETA, &conf);
	if (i == 1)
		conf.c_lflag |= ECHOCTL;
	else if (i == 0)
		conf.c_lflag &= ~(ECHOCTL);
	ioctl(ttyslot, TIOCSETA, &conf);
}

void	*ft_signal(t_global *global)
{
	if (global->here == 1)
	{
		printf("/r");
		write (1, "\n", 1);
		close(0);
	}
	else
	{
		printf("/r");
		printf("/n");
		if (rl_done)
			return ;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	global->status = 1;
}

void	*ft_signalquit(t_global *global)
{
	if (rl_done)
	{
		printf("Quit: 3\n");
		global->status = 131;
		return ;
	}
	printf("/e[2K");
	rl_on_new_line();
	rl_redisplay();
	global->status = 0;
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
