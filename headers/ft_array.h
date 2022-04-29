/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:09:04 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/19 18:09:04 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_element
{
	void				*value;
	struct s_element	*next;
}	t_element;

typedef struct s_array
{
	t_element			*begin;
	t_element			*end;
	t_element			*next;
	int					size;
	struct s_element	*(*add)(void	*value);
	void				*(*get)(int	index);
	struct s_element	*(*remove)(t_element	*e);
	int					(*destroy)();
}	t_array;

t_array	*new_array(void);

t_array	**this_array(void);

#endif
//# -fsanitize=address -g
//valgrind --leak-check=full -s -v
