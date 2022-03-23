/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_fonction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:12:56 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/23 22:54:47 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	my_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	create_pipe(t_ppb *pip)
{
	pip->i = -1;
	while (++(pip->i) < pip->num_fork - 1)
	{
		if (pipe(pip->p + (2 * pip->i)) == -1)
		{
			perror("pipe error");
			exit(0);
		}
	}
}

void	check_filein(t_ppb *pip)
{
	if (pip->filein == -1)
	{
		write(2, "filein error: No such file or directory \n", 42);
		exit (1);
	}
	else
		my_dup2(pip->filein, pip->p[1]);
}

void	ft_fork_bonus(int ac, char **av, char **env, t_ppb *pip)
{
	pip->fileout = check_fd2(av[ac - 1]);
	pip->filein = check_fd1(av[1]);
	pip->fid = fork();
	if (pip->fid == -1)
	{
		perror("fork error");
		exit(1);
	}
	if (pip->fid == 0)
	{
		if (pip->i == 0)
			check_filein(pip);
		else if (pip->i == pip->num_fork - 1)
			my_dup2(pip->p[2 * pip->i - 2], pip->fileout);
		else
			my_dup2(pip->p[2 * pip->i - 2], pip->p[2 * pip->i + 1]);
		pip->j = -1;
		while (++(pip->j) < pip->num_pipe)
			close(pip->p[pip->j]);
		pip->cmd = access_path(env, av[pip->i + 2]);
		execve(pip->cmd[0], pip->cmd, env);
		perror("This is not a command.");
	}
}

void	bonus_fonction(int ac, char **av, char **env)
{
	t_ppb	pip;

	pip.num_fork = ac - 3;
	pip.num_pipe = 2 * (pip.num_fork - 1);
	pip.p = malloc(sizeof(int) * pip.num_pipe);
	if (!pip.p)
		perror("Error malloc.");
	create_pipe(&pip);
	pip.i = -1;
	while (++(pip.i) < pip.num_fork)
		ft_fork_bonus(ac, av, env, &pip);
	free(pip.p);
	pip.j = -1;
	while (++(pip.j) < pip.num_pipe)
		close(pip.p[pip.j]);
	pip.i = -1;
	while (++(pip.i) < pip.num_fork)
		wait(NULL);
}
