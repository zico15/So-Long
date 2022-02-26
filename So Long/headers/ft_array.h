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
	char				*value;
	struct s_element	*next;
}	t_element;

typedef struct s_array
{
	t_element			*begin;
	t_element			*end;
	int					size;
	struct s_element	*(*add)(struct s_array *a, char	*value);
	void				*(*get)(struct s_array *a, int	index);
	struct s_element	*(*remove)(struct s_array *a, t_element	*e);
	struct s_array		*(*destroy)(struct s_array **a);
}	t_array;

struct s_array	*new_array(void);

#endif
