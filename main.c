/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:49:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/28 15:06:58 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	return (envp[i] + 5);
}

#include <stdio.h>
int	main(int argc, char **argv, char *envp[])
{
	(void)argc;
	(void)argv;
	char *tab;
	//stocker le chemin 
	tab = find_path(envp);
	if (argc != 5)
		message_wrong_number_of_arguments();
	if ((access(argv[1], F_OK) == -1) || (access(argv[4], F_OK) == -1))
		message_not_permissions();
	
	//ft_printf("%s", tab);
}








































