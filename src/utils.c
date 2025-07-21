/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:40:41 by osancak           #+#    #+#             */
/*   Updated: 2025/07/21 11:03:22 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(const char *msg, int errno)
{
	write(STDERR_FILENO, RED, ft_strlen(RED));
	write(STDERR_FILENO, BOLD, ft_strlen(BOLD));
	write(STDERR_FILENO, "[!] ", 4);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (errno)
	{
		write(STDERR_FILENO, " : ", 3);
		write(STDERR_FILENO, YELLOW, ft_strlen(YELLOW));
		perror("");
	}
	else
		write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, RESET, ft_strlen(RESET));
	exit(EXIT_FAILURE);
}

void	close_fd(t_fd fd)
{
	close(fd.pipe[0]);
	close(fd.pipe[1]);
	close(fd.in_f);
	close(fd.out_f);
}
