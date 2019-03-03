/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:38:51 by rgaia             #+#    #+#             */
/*   Updated: 2019/03/03 12:55:29 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
 * How do we test a graphics project besides running it and seeing if rendering
 * "looks" as expected?
 *
 * Create a way to share run-time statuses onto a log file. How?
 * -	after each "important" function is called - get return value and write 
 *  	to a file something like "map was rendered to window" "point was placed"
 *  	(create separate log for memory allocations [INITS])
 *  	(create separate log for logs related to freeing memory)
 *  	(create separate log for pixel, line functions)
 *
 *		Use [LIBFT] ft_putstr_fd to write to separate Log files throughout pro-
 *		gram
 *
 *
 *  	Why?
 *  	At each error or unexpected behavior, just read log files for what was
 *  	expected and see where it crashed. The alternative to NOT writing these
 *  	tests FIRST is: struggle more, run debugger line by line, load files 
 *  	with printf functions.
 */
void		init_tests(char *arg1)
{


}

/*
 * @purpose: init all tests from this.main 
 */
int			main(int argc, char *argv[])
{
	if (argc == 2) //take in One (1) map at a time
		init_tests(argv[1]);
	else
		ft_puterror("USAGE: ./main_test [map_file .fdf format]\n");
	return (0);
}

