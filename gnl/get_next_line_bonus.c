/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <pintodav75@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:38:14 by dpinto            #+#    #+#             */
/*   Updated: 2024/04/27 01:45:44 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

// fonction qui est appele si on est a la fin du fichier.
// return NULL si str contient rien
// sinon return le contenu de str
// Ca free buf au passage
char	*handle_end_file(char **str, int fd, t_info **lst)
{
	char	*line;
	t_info	*ptr;
	t_info	*prev;

	line = NULL;
	if (ft_strlen(*str) > 0)
		line = ft_strndup(*str, ft_strlen(*str));
	ptr = *lst;
	prev = NULL;
	while (ptr != NULL && ptr->fd != fd)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (prev == NULL)
		*lst = ptr->next;
	else
		prev->next = ptr->next;
	if (*str != NULL || ft_strlen(*str) == 0)
	{
		free(*str);
		*str = NULL;
	}
	free(ptr);
	return (line);
}

// cette fonction concat le contenu de str avec celui de buf
// return la nouvelle chaine creer
// la fonction free le pointer str et buf apres utilisation
char	*concat(char **str, char **buf)
{
	char	*res;

	if (*str == NULL)
	{
		res = ft_strndup(*buf, ft_strlen(*buf));
		free(*buf);
		return (res);
	}
	res = ft_strjoin(*str, *buf);
	if (res == NULL)
		return (NULL);
	free(*str);
	free(*buf);
	return (res);
}

// function qui retourne le contenu de str jusqu'a '\n inclut
// puis met le reste de la chaine dans *str
// et free l'ancien contenu de str pour gerer les leaks;
char	*get_line(char **str)
{
	const int	index = ft_strchr(*str, '\n');
	char		*line;
	char		*tmp;

	tmp = *str;
	line = ft_strndup(tmp, index + 1);
	if (line == NULL)
		return (NULL);
	*str = ft_strndup(tmp + index + 1, ft_strlen(tmp + index + 1));
	if (*str == NULL)
		return (NULL);
	free(tmp);
	return (line);
}

t_info	*get_or_create(t_info **lst, int fd)
{
	t_info	*ptr;

	ptr = *lst;
	while (ptr != NULL)
	{
		if (fd == ptr->fd)
			return (ptr);
		if (ptr->next == NULL)
		{
			ptr->next = ft_create_info(fd);
			if (ptr->next == NULL)
				return (NULL);
			return (ptr->next);
		}
		ptr = ptr->next;
	}
	*lst = ft_create_info(fd);
	if ((*lst) == NULL)
		return (NULL);
	return (*lst);
}

char	*get_next_line(int fd)
{
	int				count;
	char			*buf;
	static t_info	*lst = NULL;
	t_info			*ptr;

	ptr = get_or_create(&lst, fd);
	if (ptr == NULL)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	count = read(fd, buf, BUFFER_SIZE);
	if (count == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[count] = '\0';
	ptr->str = concat(&(ptr->str), &buf);
	if (ft_strchr(ptr->str, '\n') != -1)
		return (get_line(&(ptr->str)));
	if (count == 0)
		return (handle_end_file(&(ptr->str), fd, &lst));
	return (get_next_line(fd));
}
