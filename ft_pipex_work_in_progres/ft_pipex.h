/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 03:54:30 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/31 06:17:21 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

typedef struct		s_data
{
	char			**env;
	char			*cmd_path1;
	char			*cmd_path2;
}					t_data;


char	*ft_execcmd(char *cmd, char **path);
char	**ft_getpath(char **env);
void	ft_pipexson(int *fd, int *pfd, char *cmd, t_data d);
void	ft_pipexfather(int *fd, int *pfd, char *cmd, t_data d);
int		ft_pipex_error(char **argv, int argc, int *fd, int *pfd);
int		ft_pipex_error2(int argc, t_data d, char **argv);

#endif /* FT_PIPEX_H */
