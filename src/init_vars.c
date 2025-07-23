/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 09:38:01 by osancak           #+#    #+#             */
/*   Updated: 2025/07/23 18:28:14 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_vars(t_vars *vars, char *input_file, char *output_file)
{
	vars->infile = open(input_file, O_RDONLY);
	if (vars->infile < 0)
	{
		vars->infile = open("/dev/null", O_CREAT | O_RDWR | O_TRUNC);
		error_exit(input_file, 42);
	}
	if (ft_strstr(input_file, "here_doc"))
		vars->outfile = open(output_file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		vars->outfile = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (vars->outfile < 0)
	{
		vars->infile = open("/dev/null", O_CREAT | O_RDWR | O_TRUNC);
		error_exit(output_file, 42);
	}
	vars->last_read = -1;
}
