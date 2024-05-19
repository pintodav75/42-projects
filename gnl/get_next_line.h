/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <pintodav75@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:02:31 by dpinto            #+#    #+#             */
/*   Updated: 2024/04/26 23:48:41 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_info
{
	char			*str;
	int				fd;
	struct s_info	*next;
}					t_info;

int					ft_strlen(const char *str);
char				*ft_strndup(char *str, int word_len);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strchr(char *str, char c);
char				*get_next_line(int fd);

#endif
