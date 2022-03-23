/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:34:56 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/23 22:57:00 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	check_fd1(char *av)
{
	int		fd;

	fd = open(av, O_RDONLY, 0644);
	return (fd);
}

int	check_fd2(char *av)
{
	int	fileout;

	fileout = open(av, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fileout == -1)
	{
		perror("filout error");
		exit(1);
	}
	return (fileout);
}
