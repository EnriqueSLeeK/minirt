/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_parse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:09:17 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 21:15:29 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	parse_float(void **buff, char *d_str)
{
	double	*d_arr;

	d_arr = (double *)*buff;
	*d_arr = 0;
	*d_arr = str_to_double(d_str);
	*buff += sizeof(double);
}

void	parse_color(void **buff, char *i_str)
{
	double	*d_arr;

	d_arr = (double *)*buff;
	*d_arr = 0;
	*d_arr = str_to_int(i_str) / 255.0;
	*buff += sizeof(double);
}

void	parse_int(void **buff, char *i_str)
{
	int	*i_arr;

	i_arr = (int *)*buff;
	*i_arr = 0;
	*i_arr = str_to_int(i_str);
	*buff += sizeof(int);
}

// 1- Success | 0- fail
int	parse_segment(char *segment, int cycle, void *buff,
					void (*parser)(void **, char *))
{
	int		ref;
	char	tmp_c;

	if (cycle == 0)
		return (1);
	if (cycle > 1)
		ref = find_char(segment, ',');
	else
		ref = find_char(segment, ' ');
	tmp_c = segment[ref];
	segment[ref] = 0;
	parser(&buff, segment);
	segment[ref] = tmp_c;
	return (parse_segment(segment + (ref + 1),
			cycle - 1, buff, parser));
}

/* -1 -> End of line
*   1 -> Success
*   0 -> Fail
*/
int	parse_and_move(char **line, int nelem, void *buff,
		void (*parser)(void **, char *))
{
	int	offset;

	offset = next_segment(*line);
	if (offset > -1)
	{
		*line += offset;
		if (**line == 0)
			return (-1);
		if (parse_segment(*line, nelem, buff, parser))
			return (1);
	}
	return (0);
}
