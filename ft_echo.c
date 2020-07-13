/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:32:57 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/13 13:27:35 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		compare(char *s1, char *s2)
{
	int i;

	i = 1;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*Get_path(char *str)
{
	int i = 0;

	char *tmp;

	while (Data[i])
	{
		tmp = ft_strjoin(str, "=");
		ft_putendl(tmp);
		if (compare(Data[i], tmp) == 0)
		{
			ft_putendl("HERE NOW");
			return (ft_strchr(Data[i], '=') + 1);
		}
		i++;
	}
	return (NULL);
}

static void path(char *str)
{
	char *path;
	path = Get_path(str);
	ft_putstr(path);
}

void ft_echo(char **str)
{
	int i;

	i = 0;

	if (!str[1])
	{
		write(1, "\n", 1);
	}
	while (str[1][i] == '$')
	{
		path(str[1]);
		i++;
	}
}
