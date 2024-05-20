/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <pintodav75@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:13:08 by dpinto            #+#    #+#             */
/*   Updated: 2024/04/19 04:02:44 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_tab_len(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] != c)
		{
			words++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		if (str[i] == '\0')
			return (words);
		i++;
	}
	return (words);
}

static char	*ft_strndup(const char *str, int word_len)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (word_len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	fill_tab(const char *str, char c, char **tab)
{
	int	i;
	int	word_len;
	int	k;

	i = 0;
	k = 0;
	word_len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word_len = 0;
			while (str[i] != c && str[i] != '\0')
			{
				word_len++;
				i++;
			}
			tab[k] = ft_strndup(str + i - word_len, word_len);
			k++;
		}
		else
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		tab_len;

	tab_len = get_tab_len(s, c) + 1;
	tab = (char **)malloc(sizeof(char *) * (tab_len));
	if (tab == NULL)
		return (NULL);
	tab[tab_len - 1] = NULL;
	if (!s)
		return (tab);
	fill_tab(s, c, tab);
	return (tab);
}
