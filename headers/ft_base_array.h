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

#ifndef FT_BASE_ARRAY_H
# define FT_BASE_ARRAY_H

# include <stdio.h>
# include <stdlib.h>
# include <ft_util.h>


typedef struct s_element	t_element;
typedef struct s_hasmap		t_hashmap;
typedef struct s_array		t_array;



struct s_element
{
	char				*key;
	void				*value;
	int					index;
	void				(*destroy)(t_element	*e);
	struct s_element	*next;
};

struct s_array
{
	t_element		*begin;
	t_element		*end;
	t_element		*next;
	int				size;
	int				is_value_destroy;
	t_element		*(*add)(void	*value);
	void			*(*get)(int	index);
	t_element		*(*set)(int index, void *value);
	void			(*remove)(t_element	*e);
	void			(*remove_index)(int index);
	int				(*destroy)();
	void			(*destroy_element)(t_element	*e);
	void			(*for_each)(void (*fun)(t_element *e, void *v), void *o);
	void			**(*to_str)(void);
	void			(*remove_value)(void *value);
	void			(*remove_all)(void);
};

struct s_hasmap
{
	t_array			*list;
	int				(*size)(void);
	t_element		*(*put)(char *key, void	*value);
	t_element		*(*get_index)(int	index);
	t_element		*(*get_key)(char *key);
	void			(*remove_index)(int	index);
	void			(*remove_key)(char *key);
	int				(*destroy)();
	void			(*for_each)(void (*fun)(t_element *e, void *v), void *o);
	void			**(*to_str)(void);
};


void					*new_array(void);
t_array					*array(t_array *this);
void					*new_hashmap(void);
t_hashmap				*hashmap(t_hashmap *this);

#endif
//# -fsanitize=address -g
//valgrind --leak-check=full -s -v
