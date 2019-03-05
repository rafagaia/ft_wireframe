/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:17:07 by rgaia             #+#    #+#             */
/*   Updated: 2019/03/04 20:44:12 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "ft_libgfx/libgfx.h"

# define WIN_WIDTH (1280)
# define WIN_HEIGHT (720)

// WE NEED A 2D LIST TO HOLD THE POINTS WE PARSE FROM THE FILE
// THIS IS FIRST STEP!!! PARSE -> STORE IN DATA STRUCTURE.


/*	1.	RECEIVE INPUT:
 *		
 *	1.1		Read file: Get_next_line
 */




/*	2.	[RASTERISATION] PREPARE DATA:
 *	2.2.	Transform each line from GNL to a list of points: ft_split, getnbr
 *	2.3.	Return a list of list, each containing a row of points
 *	Obs:	Do Rendering to window row-by-row?
 */




/*	3.	OUTPUT PIXELS TO WINDOW:
 *
 */





/*	4.	KEYBOARD AND MOUSE 'EVENTS' HANDLERS:
 *
 */


#endif /* FDF_H */
