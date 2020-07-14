/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 03:35:00 by limartin          #+#    #+#             */
/*   Updated: 2020/01/11 17:57:58 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int		get_next_line(int fd, char **line);
int		ft_fill_remainder(char *remainder, int fd, int *nl);
int		ft_handle_remainder(char **line, char *rmn, int *i, int *nl);
void	ft_clear_remainder(char *remainder, int j);
int		ft_error(char *remainder, char **line);

int		ft_malloc_expander(char **str, int size, int grow);
size_t	ft_linelen(const char *s, char n);

#endif
