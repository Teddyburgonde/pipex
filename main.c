/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:49:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/03 04:56:39 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "pipex.h"

static void	ft_parsing(int argc, char **argv, t_vars *vars)
{
	if (argc != 5)
		message_wrong_number_of_arguments();
	if (access(argv[1], F_OK) == -1)
		message_not_permissions();
	if (pipe(vars->pipe) == -1)
		message_pipe_error();
}

int	main(int argc, char **argv, char *envp[])
{
	t_vars	vars;

	ft_parsing(argc, argv, &vars);
	find_path(envp, &vars);
	init_arg_cmd1(&vars, argv);
	init_arg_cmd2(&vars, argv);
	accessible_path(argv[2], &vars, 1);
	accessible_path(argv[3], &vars, 2);
	//ft_printf("%s\n", vars.arg_cmd1[0]);
	vars.file1 = argv[1];
	vars.file2 = argv[4];
	vars.fd_child = open(vars.file1, O_RDONLY);
	if (vars.fd_child == -1)
		exit(1);
	ft_free(vars.paths);
	// test
	//vars.arg_cmd1 = ft_split(argv[2], ' ');
	//vars.arg_cmd2 = ft_split(argv[3], ' ');
	vars.pid = fork();
	if (vars.pid == -1)
		perror("Error\n");
	if (vars.pid == 0)
		child_process(&vars, envp);
	else
		parent_process(&vars, envp);
}
