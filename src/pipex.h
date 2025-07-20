/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:40:48 by osancak           #+#    #+#             */
/*   Updated: 2025/07/20 09:57:36 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_fd
{
	int	in_f;
	int	out_f;
	int	pipe[2];
}		t_fd;

void	error_exit(const char *msg, int errno);
void	init_fd(t_fd *fd, char *input_file, char *output_file);
void	close_fd(t_fd fd);
pid_t	ft_cmd(t_fd fd, char *command, int infile);

#endif
