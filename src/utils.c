/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:40:41 by osancak           #+#    #+#             */
/*   Updated: 2025/07/23 19:04:00 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exit_with_code(int exit_code)
{
	if (errno == -42)
		exit_code = -42;
	write(STDERR_FILENO, " : ", 3);
	write(STDERR_FILENO, YELLOW, ft_strlen(YELLOW));
	if (exit_code == -42)
		write(STDERR_FILENO, "Command not found\n", 18);
	else
		perror("");
	write(STDERR_FILENO, RESET, ft_strlen(RESET));
	unlink("here_doc");
	if (exit_code == -42)
		exit(127);
	if (exit_code != 42)
		exit(errno);
}

void	error_exit(const char *msg, int exit_code)
{
	write(STDERR_FILENO, RED, ft_strlen(RED));
	write(STDERR_FILENO, BOLD, ft_strlen(BOLD));
	write(STDERR_FILENO, "[!] ", 4);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (!exit_code)
	{
		write(STDERR_FILENO, RESET, ft_strlen(RESET));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	exit_with_code(exit_code);
}

void	close_fd(t_vars vars)
{
	close(vars.curr_pipe[0]);
	close(vars.curr_pipe[1]);
	close(vars.last_read);
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
