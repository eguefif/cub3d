/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_is_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:07:34 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/05 16:42:19 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	is_textures(char *type_identifier)
{
	if (!ft_strcmp(type_identifier, "NO"))
		return (1);
	else if (!ft_strcmp(type_identifier, "SO"))
		return (1);
	else if (!ft_strcmp(type_identifier, "WE"))
		return (1);
	else if (!ft_strcmp(type_identifier, "EA"))
		return (1);
	else if (!ft_strcmp(type_identifier, "S"))
		return (1);
	else if (!ft_strcmp(type_identifier, "SK"))
		return (1);
	else if (!ft_strcmp(type_identifier, "FL"))
		return (1);
	else if (!ft_strcmp(type_identifier, "AS"))
		return (1);
	else if (!ft_strcmp(type_identifier, "NPC"))
		return (1);
	return (0);
}

int	is_color(char *type_identifier)
{
	if (!ft_strcmp(type_identifier, "C"))
		return (1);
	else if (!ft_strcmp(type_identifier, "F"))
		return (1);
	return (0);
}

int	is_map(char *type_identifier)
{
	if (type_identifier[0] == '1')
		return (1);
	return (0);
}
