/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:52:25 by tlebouvi          #+#    #+#             */
/*   Updated: 2023/04/10 15:12:30 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	test( int **r, char *buf)
// {
// 	if (**r == -1)
// 		return (0);
// 	buf[**r] = 0;
// 	return (1);
// }

int	ft_atoi(const char *str)
{
	int	signe;
	int	i;
	int	num;

	i = 0;
	signe = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * signe);
}

// int	itoanega(long long *n, long long *negative)
// {
// 	if (*n < 0)
// 	{
// 		*n *= -1;
// 		*negative = 1;
// 		return (1);
// 	}
// 	return (0);
// }

// void	itoalen(long long *tmpn, long long *len)
// {
// 	while (*tmpn > 9)
// 	{
// 		(*len)++;
// 		*tmpn /= 10;
// 	}
// }

// char	*ft_itoa(long long n)
// {
// 	long long		tmpn;
// 	long long		len;
// 	char			*str;
// 	long long		negative;

// 	if (n == -2147483648)
// 		return ((char *)ft_strdup("2147483648"));
// 	negative = 0;
// 	tmpn = n;
// 	len = 2;
// 	itoalen(&tmpn, &len);
// 	len += itoanega(&n, &negative);
// 	str = malloc(sizeof(char) * len);
// 	if (str == NULL)
// 		return (NULL);
// 	str[--len] = '\0';
// 	while (len--)
// 	{
// 		str[len] = n % 10 + '0';
// 		n = n / 10;
// 	}
// 	if (negative)
// 		str[0] = '-';
// 	return (str);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*answer;
// 	size_t	i;

// 	i = 0;
// 	if (!s || len <= 0 || start >= (unsigned int)ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (!(answer = malloc(sizeof(char) * len + 1)))
// 		return (NULL);
// 	while (s[start] && i < len)
// 	{
// 		answer[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	answer[i] = '\0';
// 	return (answer);
// }

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}