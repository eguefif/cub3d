/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:11:23 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/06 17:49:06 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_chunk
{
	char			chunk[BUFFER_SIZE + 1];
	struct s_chunk	*next;
}			t_chunk;

int		get_next_line(int fd, char *line);

//Util functions
size_t	get_size(char *st);
void	copy(char *str1, const char *str2);
int		is_return_line(char *str);
void	get_last_chunk(int ft, char *chunk);
void	get_chunk_before_rl(char *chunk, char *rest);
#endif
