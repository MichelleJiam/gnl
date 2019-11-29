/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 18:29:24 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/29 14:23:07 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_FD 1024
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *s, char c);
char	*ft_strndup(char *s1, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		makeline(char **line, char **temp, char c);
int		maketemp(char **temp, char *readbuf);
void	*ft_memcpy(char *dst, char *src, size_t n);
int		havenewline(char *str);
int		checkbuffers(char *temp);

#endif
