/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:23:17 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/06 19:20:09 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	ft_sign(int c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}

static void	ft_build(const char *str, int *res, int i)
{
	while (1)
	{
		if (!(ft_isdigit(str[i])))
			break ;
		*res = 10 * (*res) + (str[i] - '0');
		i += 1;
	}
}

//Input treatment: this function will verify if the string input is valid or not
static int	ft_treat_branch(const char *str, int *res, int *sign, int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (ft_isdigit(str[*i + 1]))
		{
			*sign = ft_sign(str[*i]);
			*i += 1;
		}
		else
			return (-1);
	}
	if (ft_isdigit(str[*i]))
	{
		ft_build(str, res, *i);
		return (-1);
	}
	if (!(ft_isdigit(str[*i]) || ft_isspace(str[*i])))
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i])
	{
		if (ft_treat_branch(str, &res, &sign, &i))
			break ;
		i += 1;
	}
	return (sign * res);
}
