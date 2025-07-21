/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:02:35 by osancak           #+#    #+#             */
/*   Updated: 2025/07/21 16:38:57 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_path(t_fd *fd, char **envp)
{
	char	*path;

	path = NULL;
	while (*envp)
	{
		if (ft_strstr(*envp, "PATH=") && ft_strstr(*envp, "/bin:"))
		{
			path = *envp;
			break ;
		}
		envp++;
	}
	if (path)
		fd->path = ft_split(ft_strstr(path, "/"), ':');
	else
		fd->path = NULL;
}

char	*get_path(char **path, char *command)
{
	char	*ex_path;
	char	*____tmp;

	if (access(command, X_OK) == 0)
		return (command);
	while (*path)
	{
		____tmp = ft_strjoin(*path, "/");
		ex_path = ft_strjoin(____tmp, command);
		free(____tmp);
		if (access(ex_path, X_OK) == 0)
			return (ex_path);
		free(ex_path);
		path++;
	}
	return (NULL);
}

void	free_path(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}
