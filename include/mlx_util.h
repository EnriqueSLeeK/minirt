/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:09:55 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/20 22:45:29 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTIL_H
# define MLX_UTIL_H

# include "struct.h"

void	mlx_draw(t_img *img, int x, int y, int color);

// Mlx preparation
int		mlx_prepare(t_mlx *);

// Key event hook
int		key_hook(int keycode, void *param);
int		mlx_key_event(int keycode, void *param);

// Free everything and exit
int		close_prog(void *param);

// Start the loop and set the image to the window
void	mlx_start(t_list_elem *elem_list);

// Put a pixel
void	put_pixel(t_img *img, int x, int y, int color);

#endif
