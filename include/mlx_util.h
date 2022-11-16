/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:09:55 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/11 10:02:32 by ensebast         ###   ########.br       */
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

// Free everything
int		close_prog(void *param);

#endif
