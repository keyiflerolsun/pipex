/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:44:31 by osancak           #+#    #+#             */
/*   Updated: 2025/07/23 19:44:16 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc < 5 || !check_args(argv))
		error_exit("Usage : ./pipex infile cmd1 cmd2 outfile", 0);
	if (ft_strstr(argv[1], "here_doc"))
		waitpid(ft_heredot(argv[2]), NULL, 0);
	init_vars(&vars, argv[1], argv[argc - 1]);
	set_path(&vars, envp);
	if (!vars.path)
		error_exit("PATH environment variable not found or invalid", 0);
	return (exec_prog(&vars, argc, argv, envp));
}
