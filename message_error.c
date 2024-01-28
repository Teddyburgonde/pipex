/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:06:10 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/28 15:07:49 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	message_wrong_number_of_arguments(void)
{
	ft_printf("Error\npipex : ./pipex file1 cmd1 cmd2 file2\n");
    exit(1);
}

void	message_not_permissions(void)
{
	ft_printf("Error\nYou don't have permission to open the file\n");
}