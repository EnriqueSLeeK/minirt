/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:28:49 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/24 15:22:22 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "struct.h"

// Line parse
int		parse_line(char *, t_list_elem *);

// Util
int		next_segment(char *line);
int		find_char(char *line, char c);

// Scenario
int		parse_light(char *line, t_light **elem);
int		parse_camera(char *line, t_camera *elem);
int		parse_ambient_light(char *line, t_ambient *elem);

// Format
int		parse_plane(char *line, t_elem **elem);
int		parse_sphere(char *line, t_elem **elem);
int		parse_cylinder(char *line, t_elem **elem);

// Micro regex
int		match_exp(char *regexp, char *text);

// Move the pointer and call a parse function
int		parse_and_move(char **line, int nelem, void *buff,
						void (*parse)(void **, char *));

// General checker
int		parse_segment(char *segment, int cycle, void *buff,
						void (*parse)(void **, char *));

// Value range check
int		range_double_check(double *val, int n,
			double lower, double upper);

int		range_int_check(int *val, int n,
			int lower, int upper);

// Convert char to int
int		str_to_int(char *);
double	str_to_double(char *);

// Parse numbers
void	parse_float(void **buff, char *d_str);
void	parse_color(void **buff, char *i_str);
void	parse_int(void **buff, char *i_str);
#endif
