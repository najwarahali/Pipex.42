/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:55:50 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/24 00:42:15 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	check_fork1_doc(int pfd[2], char **env, int filein, char **av)
{
	char	**cmd;
	int		i;

	cmd = access_path(env, av[3]);
	i = fork();
	if (i == -1)
	{
		perror("fork error");
		exit(1);
	}
	if (i == 0)
	{
		close (pfd[0]);
		dup2(filein, 0);
		dup2(pfd[1], 1);
		execve (cmd[0], cmd, env);
		perror("This is not a command.");
	}
	ft_free_it(cmd, i = 0);
}

void	check_fork2_doc(int pfd[2], char **env, char **av, int fileout)
{
	char	**cmd;
	int		i;

	cmd = access_path(env, av[4]);
	i = fork();
	if (i == -1)
	{
		perror("fork error");
		exit(1);
	}
	if (i == 0)
	{
		close (pfd[1]);
		dup2(pfd[0], 0);
		dup2(fileout, 1);
		execve (cmd[0], cmd, env);
		perror("This is not a command.");
	}
	ft_free_it(cmd, i = 0);
}
