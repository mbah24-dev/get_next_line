/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:27:25 by mbah              #+#    #+#             */
/*   Updated: 2024/12/09 20:00:55 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	has_new_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*copy;

	i = 0;
	if (str == NULL)
		return (ft_strdup(""));
	while (str[i])
		i++;
	copy = ft_mcalloc((i + 1), sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i += 1;
	}
	return (copy);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		fst_len;
	int		snd_len;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	fst_len = 0;
	snd_len = 0;
	while (s1[fst_len])
		fst_len += 1;
	while (s2[snd_len])
		snd_len += 1;
	result = ft_mcalloc((fst_len + snd_len + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	fst_len = -1;
	snd_len = -1;
	while (s1[++fst_len])
		result[fst_len] = s1[fst_len];
	while (s2[++snd_len])
		result[snd_len + fst_len] = s2[snd_len];
	return (result);
}

void	free_all(char **s1, char **s2, char **s3)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = (NULL);
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = (NULL);
	}
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = (NULL);
	}
}

void	*ft_mcalloc(size_t count, size_t size)
{
	void			*arr;
	unsigned char	*ptr;
	int				len;

	len = count * size;
	arr = malloc(len);
	if (!arr)
		return (NULL);
	ptr = (unsigned char *)arr;
	while (len != 0)
	{
		*ptr = '\0';
		ptr++;
		len--;
	}
	return (arr);
}
