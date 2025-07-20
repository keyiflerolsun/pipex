/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:44:31 by osancak           #+#    #+#             */
/*   Updated: 2025/07/20 11:50:20 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_fd	fd;
	pid_t	*commands;
	int		cmd_count;
	int		i;

	if (argc != 5)
		error_exit("Usage : ./pipex infile cmd1 cmd2 outfile", 0);
	init_fd(&fd, argv[1], argv[argc - 1]);
	cmd_count = argc - 3;
	commands = ft_calloc(cmd_count + 1, sizeof(pid_t));
	i = -1;
	while (++i < cmd_count)
	{
		if (i == 0)
			commands[i] = ft_cmd(fd, argv[i + 2], 0);
		if (i == cmd_count - 1)
			commands[i] = ft_cmd(fd, argv[i + 2], 1);
	}
	close_fd(fd);
	i = -1;
	while (++i < cmd_count)
		waitpid(commands[i], NULL, 0);
	free(commands);
	return (0);
}
