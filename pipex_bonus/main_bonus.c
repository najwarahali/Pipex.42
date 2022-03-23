/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:56:13 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/24 00:40:11 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	here_doc_f(char **av, char **env)
{
	int	filein;
	int	fileout;
	int	fd[2];

	filein = here_doc(av);
	fileout = check_fd2(av[5]);
	if (pipe(fd) == -1)
	{
		perror("pipe error");
		exit (1);
	}
	check_fork1_doc(fd, env, filein, av);
	check_fork2_doc(fd, env, av, fileout);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
	{
		perror("Error of arguments.");
		exit(1);
	}
	if (!ft_strcmp(av[1], "here_doc"))
	{
		here_doc_f(av, env);
	}
	else
		bonus_fonction(ac, av, env);
	return (0);
}
