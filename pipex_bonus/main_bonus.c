/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:56:13 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/22 01:56:16 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	here_doc_f(char **av, char **env)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe error");
		exit (1);
	}
	check_fork1_doc(fd, env, av[3], av);
	check_fork2_doc(fd, env, av[5], av[4]);
	close(fd[0]);
	close(fd[1]);
	wait(0);
	wait(0);
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
