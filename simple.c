/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:44:31 by osancak           #+#    #+#             */
/*   Updated: 2025/07/22 09:24:33 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	pid_t	cmd1;
	pid_t	cmd2;

	if (argc != 5)
		error_exit("Usage : ./pipex infile cmd1 cmd2 outfile", 0);
	init_vars(&vars, argv[1], argv[4]);
	set_path(&vars, envp);
	if (!vars.path)
		error_exit("PATH environment variable not found or invalid", 0);
	cmd1 = ft_cmd(vars, argv[2], envp, 1);
	cmd2 = ft_cmd(vars, argv[3], envp, -1);
	close_fd(vars);
	free_path(vars.path);
	waitpid(cmd1, NULL, 0);
	waitpid(cmd2, NULL, 0);
	return (EXIT_SUCCESS);
}
