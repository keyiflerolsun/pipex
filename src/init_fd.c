/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 09:38:01 by osancak           #+#    #+#             */
/*   Updated: 2025/07/20 09:39:49 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_fd(t_fd *fd, char *input_file, char *output_file)
{
	fd->in_f = open(input_file, O_RDONLY);
	if (fd->in_f < 0)
		error_exit("infile", 1);
	fd->out_f = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd->out_f < 0)
		error_exit("outfile", 1);
	if (pipe(fd->pipe) == -1)
		error_exit("pipe", 1);
}
