/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nrahali <nrahali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/05 22:31:26 by nrahali		   #+#	#+#			 */
/*   Updated: 2022/03/10 23:31:40 by nrahali          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **env)
{
	int	pfd[2];

	if (ac != 5)
	{
		perror("Error of arguments.");
		exit(1);
	}
	if (pipe(pfd) == -1)
	{
		perror("pipe error");
		exit (1);
	}
	check_fork1(pfd, env, av[1], av[2]);
	check_fork2(pfd, env, av[4], av[3]);
	close(pfd[0]);
	close(pfd[1]);
	wait(0);
	wait(0);
	return (0);
}
