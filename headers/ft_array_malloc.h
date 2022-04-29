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

#ifndef FT_ARRAY_MALLOC_H
# define FT_ARRAY_MALLOC_H

# include <stdio.h>
# include <stdlib.h>
# include "ft_so_long.h"
# include "ft_array.h"

t_array	*new_array_malloc(void);

t_array	*this(void);

#endif
//# -fsanitize=address -g
//valgrind --leak-check=full -s -v
