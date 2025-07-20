/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:44:31 by osancak           #+#    #+#             */
/*   Updated: 2025/07/20 09:41:07 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_fd	fd;
	pid_t	cmd1;
	pid_t	cmd2;

	if (argc != 5)
		error_exit("Usage : ./pipex infile cmd1 cmd2 outfile", 0);
	init_fd(&fd, argv[1], argv[4]);
	cmd1 = ft_cmd(fd, argv[2], 0);
	cmd2 = ft_cmd(fd, argv[3], 1);
	close_fd(fd);
	waitpid(cmd1, NULL, 0);
	waitpid(cmd2, NULL, 0);
	return (0);
}
