/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 09:32:57 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/13 16:56:56 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		compare(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] == s2[i])
		{
			return (1);
			break;
		}
		i++;
	}
	return (0);
}


/*char	*Get_path(char *str)
{
	int i = 1;
	char *tmp;

	while (Data[i])
	{
		tmp = ft_strjoin(str, "=");
		ft_putendl(tmp);
		if (compare(Data[i], tmp) == 1)
		{
			//ft_putendl("HERE NOW");
			return (ft_strchr(Data[i], '='));
		}
		i++;
//		ft_putendl(Data[x++]);
		i++;
	}
	return (NULL);
}*/
char	*Get_path(char *str)
{
	//ft_putstr(str);
	int i = 0;
	char *tmp;
	tmp = str;

	while (Data[i])
	{
		tmp = ft_strjoin(str, "=");
		if (compare(Data[i], tmp) == 1)
		{
			return (ft_strchr(Data[i], '=') + 1);
		}
		else
		{
			ft_putendl("NOT FOUND");
		}
		i++;
	}
	return (NULL);
}
static void paths(char *str)
{
	int i = 0;

	char *path;
	if (str[0] == '$')
	{
		path = Get_path(str + 1);
	}
	else
	{
		write(1, &str[i++], 1);
	}
}

int ft_echo(char **str)
{
	//char *path;
	int i;

	i = 1;
	if (!str[1])
	{
		write(1, "\n", 1);
		return (1);
	}
	while (str[i])
	{
		/*if (str[i][0] == '$')
		{
			path = Get_path(str[i++]);
			continue ;
		}
		ft_putstr(str[i++]);
		*/
		paths(str[i]);
		i++;
		ft_putchar(' ');
	}
	ft_putchar('\n');
	return (1);
}
