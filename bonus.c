/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:44:31 by osancak           #+#    #+#             */
/*   Updated: 2025/07/21 17:15:21 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	run_prog(t_fd *fd, int cmd_count, char **cmds, char **envp)
{
	int	i;

	i = -1;
	while (++i <= cmd_count)
	{
		if (i == 0)
			fd->cmds[i] = ft_cmd(*fd, cmds[i], envp, 1);
		else if (i == cmd_count)
			fd->cmds[i] = ft_cmd(*fd, cmds[i], envp, -1);
		else
			fd->cmds[i] = ft_cmd(*fd, cmds[i], envp, 0);
	}
	close_fd(*fd);
	free_path(fd->path);
	i = -1;
	while (++i <= cmd_count)
		waitpid(fd->cmds[i], NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd;

	if (argc != 5)
		error_exit("Usage : ./pipex infile cmd1 cmd2 outfile", 0);
	init_fd(&fd, argv[1], argv[argc - 1]);
	set_path(&fd, envp);
	if (!fd.path)
		error_exit("PATH environment variable not found or invalid", 0);
	run_prog(&fd, argc - 4, argv + 2, envp);
	return (EXIT_SUCCESS);
}
