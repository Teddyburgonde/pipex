/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:49:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/31 11:36:55 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libftprintf.h"
#include "./libft/includes/libft.h"
#include "pipex.h"

// void process_child()
// {
// 	t_vars vars;
	
// 	dup2(vars.tube[1], 1);
// 	close(vars.tube[0]); 
	
// }
//./pipex file1 cmd1 cmd2 file2


void	accessible_path(char *argv, t_vars *vars, int cmd)
{
	char 	**tab;
	char	*tmp;
	int		i;
	char	*new_tab;
	char 	*slash;

	tab = ft_split(argv, ' ');
	slash = "/";
	i = 0;
	while (vars->paths[i])
	{
		tmp = ft_strjoin(vars->paths[i], slash);
		new_tab = ft_strjoin(tmp, tab[0]);
		//ft_printf("%s\n", new_tab);// verif access et sauvegarder le path qui est bon
		if (access(new_tab, X_OK) == 0)
		{
			// ce chemin est celui qui est executable 
			//ft_printf("tu peux entrer mon ami\n");
			if (cmd == 1)
				vars->arg_cmd1[0] = new_tab;
			if (cmd == 2)
				vars->arg_cmd2[0] = new_tab;
			break ;
		}
		//else
			//ft_printf("Error:\nThe command does not exist or is not accessible.\n");
		free(tmp);
		free(new_tab);
		i++;
	}
}


int	main(int argc, char **argv, char *envp[])
{
	t_vars vars;

	if (argc != 5)
		message_wrong_number_of_arguments();
	if ((access(argv[1], F_OK) == -1))
		message_not_permissions();
	if (pipe(vars.tube) == -1)
		message_pipe_error();
	find_path(envp, &vars);
	init_arg_cmd(&vars, argv);
	accessible_path(argv[2], &vars, 1);
	ft_printf("%s", vars.arg_cmd1[0]);
	accessible_path(argv[3], &vars, 2);
	//ft_find(vars.arg_cmd1[0]);
	//ft_find(vars.arg_cmd2[0]);


	
	// // vars.pid = fork();
	
	// // if (vars.pid == 0)
	// // 	process_child();
}







































