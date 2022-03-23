/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   check_files.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nrahali <nrahali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/09 02:09:15 by nrahali		   #+#	#+#			 */
/*   Updated: 2022/03/09 02:39:18 by nrahali		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../pipex.h"

int	check_fd1(char *av)
{
	int		fd;

	fd = open(av, O_RDONLY, 0644);
	if (fd == -1)
		perror("File Not Exist");
	return (fd);
}

int	check_fd2(char *av)
{
	int	fileout;

	fileout = open(av, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fileout == -1)
	{
		perror("fileout error");
		exit(1);
	}
	return (fileout);
}
