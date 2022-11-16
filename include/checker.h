/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:28:49 by ensebast          #+#    #+#             */
/*   Updated: 2022/09/24 22:23:10 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

// Line check
int		check_count_line(char *line, int *count);

// Util
int		next_segment(char *line);
int		find_char(char *line, char c);

// Checkers
// Checker functions
int		check_int_len(char *num);
int		check_float(char *segment);
int		check_int(char *segment);

// Scenario
int		check_light(char *line);
int		check_camera(char *line);
int		check_ambient_light(char *line);

// Format
int		check_plane(char *line);
int		check_sphere(char *line);
int		check_cylinder(char *line);

// Micro regex
int		match_exp(char *regexp, char *text);

// Move the pointer and call a checking function
int		check_and_move(char **line, int nelem,
						int (*check)(char *));

// Check extension
int		extension_check(char *file);

// General checker
int		check_segment(char *segment, int cycle, int limit,
						int (*checker)(char *));
#endif
