/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:38:27 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/16 10:45:46 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_red(unsigned int	rgba)
{
	return ((rgba >> 16) & 0xFF);
}

int	get_blue(unsigned int	rgba)
{
	return (rgba & 0xFF);
}

int	get_green(unsigned int rgba)
{
	return ((rgba >> 8) & 0xff);
}

int get_alpha(unsigned int rgba)
{
	return ((rgba >> 24) & 0xff);
}

unsigned int	get_rgb_code(int alpha, int red, int green, int blue)
{
	return ((alpha << 24) + (red << 16) + (green << 8) + blue);
}
