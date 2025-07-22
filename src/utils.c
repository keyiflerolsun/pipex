/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:40:41 by osancak           #+#    #+#             */
/*   Updated: 2025/07/22 13:51:08 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(const char *msg, int exit_code)
{
	write(STDERR_FILENO, RED, ft_strlen(RED));
	write(STDERR_FILENO, BOLD, ft_strlen(BOLD));
	write(STDERR_FILENO, "[!] ", 4);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (exit_code)
	{
		write(STDERR_FILENO, " : ", 3);
		write(STDERR_FILENO, YELLOW, ft_strlen(YELLOW));
		perror("");
		write(STDERR_FILENO, RESET, ft_strlen(RESET));
		exit(errno);
	}
	else
	{
		write(STDERR_FILENO, RESET, ft_strlen(RESET));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	close_fd(t_vars vars)
{
	close(vars.curr_pipe[0]);
	close(vars.curr_pipe[1]);
	close(vars.infile);
	close(vars.outfile);
}

int	check_args(char **argv)
{
	while (*argv)
		if (!**argv++)
			return (0);
	return (1);
}
