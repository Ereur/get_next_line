/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:20:54 by aamoussa          #+#    #+#             */
/*   Updated: 2021/11/22 22:54:58 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size))
		{
			dst[i] = src[i];
			i++;
		}
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(s1_len + s2_len + 1);
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, s1, s1_len);
	ft_strcpy(ptr + s1_len, s2, s2_len);
	ptr[s1_len + s2_len] = 0;
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*ptr;

	i = 0;
	size = ft_strlen(src);
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == 0)
		return (0);
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
