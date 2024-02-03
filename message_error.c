/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:06:10 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/03 03:09:04 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	message_wrong_number_of_arguments(void)
{
	perror("Error\npipex : ./pipex file1 cmd1 cmd2 file2\n");
	exit(1);
}

void	message_not_permissions(void)
{
	perror("Error\n");
	exit(1);
}

void	message_pipe_error(void)
{
	perror("Error\n");
	exit(1);
}
