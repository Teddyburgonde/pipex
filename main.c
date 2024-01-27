/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:49:13 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/27 16:52:48 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/includes/libftprintf.h"

int	main(int argc, char **argv)
{
	if (argc != 5)
	{    //creer une fonction pour message error
        ft_printf("pipex : ./pipex file1 cmd1 cmd2 file2");
        exit(1);
    }
	if (access(argv[1], F_OK) == -1)
	{
		ft_printf("You don't have permission to open the file\n");
        exit(1);
	}
}















































int main(int argc, char **argv) 
{
    t_vars *vars;



    vars = malloc(sizeof(t_vars));
    if (vars == NULL) 
	{
        ft_printf("Memory allocation failed\n");
        exit(-1);
    }

    vars->file1 = argv[1]; // Mettez le nom du fichier en tant que premier argument
    vars->file2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666); // Ouvrez ou créez le deuxième fichier
    vars->args = argv + 2; // Passez les arguments de la commande à partir de la troisième position

    can_be_opened(file1);

    // Fermez le fichier2 si nécessaire, n'oubliez pas de fermer les fichiers ouverts
    close(vars->file2);

    free(vars); // N'oubliez pas de libérer la mémoire allouée

    return 0;
}