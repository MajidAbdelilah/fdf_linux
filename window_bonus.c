/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajid <amajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:29:56 by amajid            #+#    #+#             */
/*   Updated: 2023/12/21 18:30:46 by amajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/usr/local/include/mlx.h"
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

void w_rotate(int keycode, t_loop_data *vars) {
  if (keycode == 111)
    rotate(vars, (t_point){1, 0, 0, 0}, 0);
  if (keycode == 108)
    rotate(vars, (t_point){1, 0, 0, 0}, 1);
  if (keycode == 105)
    rotate(vars, (t_point){0, 1, 0, 0}, 0);
  if (keycode == 107)
    rotate(vars, (t_point){0, 1, 0, 0}, 1);
  if (keycode == 117)
    rotate(vars, (t_point){0, 0, 1, 0}, 0);
  if (keycode == 106)
    rotate(vars, (t_point){0, 0, 1, 0}, 1);
}

void w_translate_scale(int keycode, t_loop_data *vars) {
  if (keycode == 97)
    translate(vars, (t_point){1, 0, 0, 0}, 0);
  if (keycode == 113)
    translate(vars, (t_point){1, 0, 0, 0}, 1);
  if (keycode == 122)
    translate(vars, (t_point){0, 1, 0, 0}, 0);
  if (keycode == 115)
    translate(vars, (t_point){0, 1, 0, 0}, 1);
  if (keycode == 65453)
    scale(vars, (t_point){1, 1, 1, 0}, 0);
  if (keycode == 65451)
    scale(vars, (t_point){1, 1, 1, 0}, 1);
  if (keycode == 120)
    vars->animate = !vars->animate;
  if (keycode == 119)
    multiview_orthographic_projection(vars);
}

#include <stdio.h>

int handle_keys(int keycode, t_loop_data *vars) {
  printf("keycode = %d\n", keycode);
  w_rotate(keycode, vars);
  w_translate_scale(keycode, vars);
  if (keycode != 65307)
    return (0);
  mlx_destroy_window(vars->mlx, vars->mlx_win);
  mlx_destroy_image(vars->mlx, vars->img.img);
  free(vars->result);
  exit(0);
  return (0);
}
