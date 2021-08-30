/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygil <ygil@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:52:57 by ygil              #+#    #+#             */
/*   Updated: 2021/08/30 21:33:33 by ygil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void*ft_calloc(size_t cnt, size_t size)
{
char*p;
unsigned inti;
size_tx;

i = 0;
x = cnt * size;
p = (char *)malloc(x);
if (p == NULL)
return (0);
while (i < x)
{
p[i] = 0;
i++;
}
return (p);
}

char*ft_update_nl(char**line, int position)
{
char*tmp;
intlen;

len = ft_strlen(*line) - position;
tmp = ft_strndup(*line + position, len);
ft_free(line);
*line = tmp;
return (*line);
}

char*ft_output(char **line, int position, int bytes)
{
char*tmp;

if (((bytes == 0 || bytes == -1) && !*line) || position == -5)
{
if (*line)
return (*line);
return (NULL);
}
tmp = NULL;
if (position == -1)
position = ft_strlen(*line);
else
position++;
tmp = ft_strndup(*line, position);
if (position == ft_strlen(*line))
ft_free(line);
else
*line = ft_update_nl(line, position);
return (tmp);
}

char*get_next_line(int fd)
{
static char*line;
char*buf;
intposition;
intbytes;

if (BUFFER_SIZE <= 0 || fd < 0 || fd > 10240)
return (NULL);
buf = NULL;
position = ft_strchr(line, '\n', 0);
while (position == -1 && position != -5)
{
buf = ft_calloc(BUFFER_SIZE + 1, 1);
if (buf == NULL)
return (NULL);
bytes = read(fd, buf, BUFFER_SIZE);
if (bytes == 0 || bytes == -1)
break ;
line = ft_strnjoin(line, buf, bytes);
position = ft_strchr(line, '\n', 1);
ft_free(&buf);
}
ft_free(&buf);
return (ft_output(&line, position, bytes));
}
