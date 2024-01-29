/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:49:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/29 17:25:19 by tebandam         ###   ########.fr       */
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

int	main(int argc, char **argv, char *envp[])
{
	t_vars vars;
	char **tab;
	char *tmp;
	char *slash;
	char *new_tab;
	int	i;

	if (argc != 5)
		message_wrong_number_of_arguments();
	if ((access(argv[1], F_OK) == -1) || (access(argv[4], F_OK) == -1))
		message_not_permissions();
	if (pipe(vars.tube) == -1)
		message_pipe_error();
	find_path(envp, &vars);
	i = 0;
	tab = ft_split(argv[2], ' ');
	slash = "/";
	while (vars.paths[i])
	{
		tmp = ft_strjoin(vars.paths[i], slash);
		new_tab = ft_strjoin(tmp, tab[0]);
		ft_printf("%s\n", new_tab);// verif access et sauvegarder le path qui est bon
		free(tmp);
		free(new_tab);
		i++;
	}
	// // vars.pid = fork();
	
	// // if (vars.pid == 0)
	// // 	process_child();
}







































