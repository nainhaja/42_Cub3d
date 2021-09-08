/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:46:13 by nainhaja          #+#    #+#             */
/*   Updated: 2019/11/06 23:53:30 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		get_next_line(int fds, char **line);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, unsigned int len);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);

#endif
