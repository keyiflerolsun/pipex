/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 08:30:47 by osancak           #+#    #+#             */
/*   Updated: 2025/07/21 16:35:37 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_allocs(char **split, char *ex_path, char **path)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	free(ex_path);
	free_path(path);
}

static void	fd_apply(t_fd *fd, int cmd_index)
{
	if (cmd_index == 1)
	{
		dup2(fd->in_f, STDIN_FILENO);
		dup2(fd->pipe[1], STDOUT_FILENO);
	}
	if (cmd_index == -1)
	{
		dup2(fd->pipe[0], STDIN_FILENO);
		dup2(fd->out_f, STDOUT_FILENO);
	}
	if (cmd_index == 0)
	{
		dup2(fd->pipe[0], STDIN_FILENO);
		dup2(fd->pipe[1], STDOUT_FILENO);
	}
}

pid_t	ft_cmd(t_fd fd, char *command, char **envp, int cmd_index)
{
	pid_t	pid;
	char	**cmd;
	char	*ex_path;
	int		exec;

	pid = fork();
	if (pid == 0)
	{
		fd_apply(&fd, cmd_index);
		close_fd(fd);
		cmd = ft_split(command, ' ');
		ex_path = get_path(fd.path, cmd[0]);
		if (ex_path)
			exec = execve(ex_path, cmd, envp);
		else
			exec = -1;
		free_allocs(cmd, ex_path, fd.path);
		if (exec == -1)
			error_exit("execve", 1);
		exit(EXIT_SUCCESS);
	}
	if (pid < 0)
		error_exit("fork", 1);
	return (pid);
}
