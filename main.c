/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:49:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/03 00:36:16 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "pipex.h"

void	check_Access(char *path, char **arg_cmd, int cmd)
{
	if (access(path, X_OK) == 0)
	{
		if (cmd == 1)
			arg_cmd[0] = path;
		else if (cmd == 2)
			arg_cmd[0] = path;
		return ;
	}
}

void	accessible_path(char *argv, t_vars *vars, int cmd)
{
	char	**tab;
	char	*tmp;
	int		i;
	char	*new_tab;
	char	*slash;

	tab = ft_split(argv, ' ');
	slash = "/";
	i = 0;
	if (!tab)
		return ;
	check_Access(tab[0], vars->arg_cmd1, cmd);
	while (vars->paths[i])
	{
		tmp = ft_strjoin(vars->paths[i], slash);
		new_tab = ft_strjoin(tmp, tab[0]);
		if (access(new_tab, X_OK) == 0)
		{
			if (cmd == 1)
				vars->arg_cmd1[0] = new_tab;
			if (cmd == 2)
				vars->arg_cmd2[0] = new_tab;
			free(tmp);
			break ;
		}
		free(tmp);
		free(new_tab);
		i++;
	}
	ft_free(tab);
}

void	ft_parsing(int argc, char **argv, t_vars *vars)
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
	vars.file1 = argv[1];
	vars.file2 = argv[4];
	vars.fd_child = open(vars.file1, O_RDONLY);
	if (vars.fd_child == -1)
		exit(1);
	ft_free(vars.paths);
	vars.pid = fork();
	if (vars.pid == -1)
		perror("Error\n");
	if (vars.pid == 0)
		child_process(&vars, envp);
	else
		parent_process(&vars, envp);
}
