/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:33:02 by raubert           #+#    #+#             */
/*   Updated: 2019/08/14 15:25:16 by raubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_sort_params(int argc, char **argv)
{
	char	*tmp;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			tmp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	char	*first;

	i = 0;
	first = argv[0];
	if (argc <= 0)
		return (0);
	ft_sort_params(argc, argv);
	while (argv[i] != '\0')
	{
		if (argv[i] != first)
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
