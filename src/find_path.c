/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:49:26 by mkollar           #+#    #+#             */
/*   Updated: 2025/03/14 18:50:02 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ret_if_correct(char	***env_path, char *command)
{
	char	**path;
	char	*chk;
	char	*ret;
	int		j;

	path = *env_path;
	j = 0;
	while (path[j])
	{
		chk = ft_badstrjoin(path[j], command);
		if (access(chk, X_OK) == 0)
		{
			ret = ft_badstrjoin(path[j], command);
			free(chk);
			free_matrix(path);
			return (ret);
		}
		free(chk);
		j++;
	}
	return NULL;
}

char	*find_path(char **envp, char *command)
{
	char	**path;
	char	*ret;
	int		i;
	int		j;

	if (command == NULL)
		exit(69);
	ret = NULL;
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			ret = ret_if_correct(&path, command);
		}
		i++;
	}
	free(command);
	if (ret != NULL)
		return (ret);
	free_matrix(path);
	perror("\033[31mERROR: command not found");
	return (NULL);
}