/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wireframe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:42:35 by lharvey           #+#    #+#             */
/*   Updated: 2020/02/10 15:42:41 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	word_count(char *string)
{
	int ret_val;

	ret_val = 0;
	while (*string != '\0' || *string != '\n')
	{
		if (ft_isascii(*string) == 1)
		{
			++ret_val;
			while (ft_isascii(*(string + 1)) == 1)
				string++;
		}
		string++;
	}
	return (ret_val);
}

int	check_wireframe(int fd)
{
	int		wire_y;
	int		wire_x;
	char	*line;
	char	**line_array;
	int		width_check;

	*line = 0;
	while ((get_next_line(fd, &line)) != 0)
	{
		if ((wire_x = word_count(line)) == 0)
			return (-1);
		line_array[wire_y] = line;
		if (wire_y != 0)
			if (width_check != wire_x)
				return (0);
		++wire_y;
		width_check = wire_x;
	}
	

}
