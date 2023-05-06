/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:12:29 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/05 21:03:38 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# include "cub3d.h"

void	parsing_scene(t_scene *scene, char *path);
void	parse_resolution(t_scene *scene, char **splited_line);
void	parse_textures(t_scene *scene, char **splited_line);
void	parse_colors(t_scene *scene, char **splited_line);
int		is_textures(char *type_identifier);
int		is_color(char *type_identifier);
int		is_map(char *line);

//Parsing map functions
t_map	parse_map(char *path);
void	check_map(t_map map);
#endif
