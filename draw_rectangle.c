/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:16:36 by bjeana            #+#    #+#             */
/*   Updated: 2021/06/26 20:39:19 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	k;
	int	n;

	k = 1;
	n = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			k = k * (-1);
		str++;
	}
	while (*str == 48)
		str++;
	while (*str > 47 && *str < 58)
	{
		n = n * 10 + k * (*str - 48);
		str++;
	}
	return (n);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rush_str(int x1, int y1, int x)
{
	int	i;

	i = 1;
	if (x == 1)
	{
		ft_putchar (x1);
		ft_putchar ('\n');
	}
	else
	{
		ft_putchar (x1);
		while (i < x - 1)
		{
			ft_putchar (y1);
			i++;
		}
		ft_putchar (x1);
		ft_putchar ('\n');
	}
}

void	rush(int x, int y)
{
	int	j;

	j = 1;	
	if (x == 1 && y == 1)
	{
		ft_putchar(65);
		ft_putchar('\n');
	}
	else
	{
		if (y == 1)
			rush_str (65, 66, x);
		else
		{
			rush_str (65, 66, x);
			while (j++ < y - 1)
			{
				rush_str (66, 32, x);
			}
			rush_str (67, 66, x);
		}
	}	
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;
	
	if (argc != 3)
		return (0);
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if (x <= 0 || y <= 0)
		return (0);
	rush(x, y);
	return (0);
}
