/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 08:30:47 by osancak           #+#    #+#             */
/*   Updated: 2025/07/20 10:03:59 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_allocs(char **split, char *join)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	free(join);
}

static void	fd_apply(t_fd *fd, int infile)
{
	if (infile)
	{
		dup2(fd->in_f, STDIN_FILENO);
		dup2(fd->pipe[1], STDOUT_FILENO);
	}
	else
	{
		dup2(fd->pipe[0], STDIN_FILENO);
		dup2(fd->out_f, STDOUT_FILENO);
	}
}

pid_t	ft_cmd(t_fd fd, char *command, int infile)
{
	pid_t	pid;
	char	**cmd;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		fd_apply(&fd, infile);
		close_fd(fd);
		cmd = ft_split(command, ' ');
		path = ft_strjoin("/bin/", cmd[0]);
		execve(path, cmd, NULL);
		free_allocs(cmd, path);
		error_exit("execve", 1);
		exit(EXIT_SUCCESS);
	}
	if (pid < 0)
		error_exit("fork", 1);
	return (pid);
}
