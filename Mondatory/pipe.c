/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipe.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nrahali <nrahali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/09 02:29:37 by nrahali		   #+#	#+#			 */
/*   Updated: 2022/03/10 23:33:40 by nrahali          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../pipex.h"

void	check_fork1(int pfd[2], char **env, char **av, int filein)
{
	char	**cmd;
	int		i;

	if (filein == -1)
		return ;
	cmd = access_path(env, av[2]);
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

void	check_fork2(int pfd[2], char **env, char **av, int fileout)
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
		close (pfd[1]);
		dup2(pfd[0], 0);
		dup2(fileout, 1);
		execve (cmd[0], cmd, env);
		perror("This is not a command.");
	}
	ft_free_it(cmd, i = 0);
}
