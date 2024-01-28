/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:49:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/28 18:50:51 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "pipex.h"

#include <stdio.h>
int	main(int argc, char **argv, char *envp[])
{
	t_vars vars;

	if (argc != 5)
		message_wrong_number_of_arguments();
	if ((access(argv[1], F_OK) == -1) || (access(argv[4], F_OK) == -1))
		message_not_permissions();
	if (pipe(vars.tube) == -1)
		message_pipe_error();
	// stock le chemin 
	vars.paths = find_path(envp);
	vars.arg_cmd1 = ft_split(vars.paths, ':');
	vars.pid = fork();
	//ft_printf("%s", vars.arg_cmd1[5]);
}








































