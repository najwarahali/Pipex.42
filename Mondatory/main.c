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
	int	filein;
	int	fileout;

	filein = check_fd1(av[1]);
	fileout = check_fd2(av[4]);
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
	check_fork1(pfd, env, av, filein);
	check_fork2(pfd, env, av, fileout);
	close(pfd[0]);
	close(pfd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
