/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:00 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/06 21:02:04 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	t_vars	vars;

	if (pipe(vars.pipe) == -1)
		return (-1);
	ft_parsing(argc, argv, &vars);
	vars.infile = argv[1];
	vars.outfile = argv[4];
	vars.fd_infile = open(vars.infile, O_RDONLY);
	vars.fd_outfile = open(vars.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	vars.paths = grep_path(envp);
	vars.final_path1 = find_the_accessible_path(vars.paths, argv[2]);
	vars.final_path2 = find_the_accessible_path(vars.paths, argv[3]);
	vars.pid1 = fork();
	if (vars.pid1 == -1)
		exit (1);
	if (vars.pid1 == 0)
		child_process(&vars, envp);
	else
		parent_process(&vars, envp);
}
