/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 21:37:34 by limartin          #+#    #+#             */
/*   Updated: 2020/01/11 17:55:41 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_error(char *remainder, char **line)
{
	int i;

	i = 0;
	while (i < (BUFFER_SIZE + 1))
	{
		remainder[i] = '\0';
		i++;
	}
	if (!(*line == 0))
		free(*line);
	*line = NULL;
	return (-1);
}

void	ft_clear_remainder(char *remainder, int j)
{
	int	k;

	k = 0;
	while (remainder[j] != '\0')
	{
		j++;
		remainder[k] = remainder[j];
		k++;
	}
	while (k < j)
	{
		remainder[k] = '\0';
		k++;
	}
}

int		ft_handle_remainder(char **line, char *rmn, int *i, int *nl)
{
	int	j;

	j = 0;
	while (rmn[j] != '\n' && rmn[j] != '\0')
	{
		(*line)[*i] = rmn[j];
		*i = *i + 1;
		j++;
	}
	(*line)[*i] = '\0';
	if (rmn[j] == '\n')
		*nl = 0;
	ft_clear_remainder(rmn, j);
	return (1);
}

int		ft_fill_remainder(char *remainder, int fd, int *nl)
{
	int		red;

	red = read(fd, remainder, BUFFER_SIZE);
	if (red <= 0)
		*nl = 0;
	return (red);
}

int		get_next_line(int fd, char **line)
{
	static char	remainder[FD_MAX][BUFFER_SIZE + 1];
	int			i;
	int			nl;
	int			red;

	if (line == NULL || fd < 0 || fd >= FD_MAX
	|| (read(fd, 0, 0) == -1) || BUFFER_SIZE < 0)
		return (-1);
	*line = (char *)malloc(sizeof(char) * (1));
	if (*line == 0)
		return (ft_error(remainder[fd], line));
	i = 0;
	nl = 1;
	while (nl)
	{
		if (remainder[fd][0] == '\0')
			red = ft_fill_remainder(remainder[fd], fd, &nl);
		if (red == -1)
			return (ft_error(remainder[fd], line));
		if (!(ft_malloc_expander(line, i, ft_linelen(remainder[fd], '\n'))))
			return (ft_error(remainder[fd], line));
		if (remainder[fd][0] != '\0')
			red = ft_handle_remainder(line, remainder[fd], &i, &nl);
	}
	return (red);
}
