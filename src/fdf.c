/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:29:33 by rgaia             #+#    #+#             */
/*   Updated: 2019/03/04 20:44:10 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
 *	ft_fdf:
 *		requires .fdf file containng XYZ coordinate formts from relief landscape
 *	
 *	Return Values (ft_fdf error codes to main)
 *		(1) : success //so that Loop in Main Keeps Running
 *		(0) : ???
 *		(-1): bad file name
 *		(-2): bad file format
 *		(-3): bad camera image
 *		(-4): bad List of Point
 *
 *		OBS: CONSECUTIVE FDF CALLS WILL NEED THE LIST OF POINTS THAT GOT READ
 *		ALREADY FROM THAT MAP. WE DON'T WANT TO PARSE THE FILE EVERY CALL.
 *		HOW TO SOLVE DOUBLE RETURN VALUE? A LOT NEEDS TO BE PASSED ON...
 *		Hmmmmmm.....
 *		Shove everything in a single struct. Ugly but works :S
*/
int			ft_fdf(t_fdf *fdf)
{
	//[LIB] ft_libgfx Function
	return ((ft_render_fdf(fdf)));
}

/*
 *
 *
*/ 
t_list		**init_raster_scan(int fd)
{

}

/*
 *
 *
 */
t_image		*init_camera(t_image *camera_view)
{


}

/*
 *
 *
*/ 
t_fdf		*init_fdf(int fd, t_fdf *fdf)
{
	//error checking and all that in here
	
	t_image	*camera_view;
	t_list	**list_raster;
	t_mlx	*mlx; //needs to be pointer?
	
	//test only with valid files - implement this handler later:
	/*if ((valid_file_format(fd)) == NULL)
		exit_failure("ERROR: INVALID FILE FORMAT.\n");*/

	list_raster = init_raster_scan(fd);
	close(fd);
	camera_image = init_camera(camera_view);
	mlx = mlx_init(); //something like this
	//need to SET do other stuff to MLX Struct here

	return (fdf);
}

void	handle_exit(char *str)
{
	ft_puterror(str);
	exit(EXIT_FAILURE);
}

/*
*	***			***			[@FDF EXECUTABLE ENTRY FUNC]	***		***		***
*
*	Do like ft_fillit design to run a new recursive "Render"
*	every time the user hits a key to move the map around and get a new
*	perspective.
*		WHY?
*	We're SIMULATING 3D by connecting the lines between the points to
*	make it work for THAT ONE SPECIFIC Camera_image
*	Rotations, translations and wobbles need to re-draw ALL LINES
*		OBS: 
*		0.	Points remain STATIC (DON'T FREE THEM TIl THE END)
*			0.0. ?Then how do we pass back to FDF a pointer the LIST of X,Y,Z
*				 coordinates? Ans: You pass in a NULL pointer the first time
*		1.	Doesn't need to re-draw all lines. You're misunderstanding what mi-
*		niLibX does and how to use it properly. You leave all your t_pixel obt-
*		ained from @in .fdf allocated in-between each new render whenever the 
*		user does anything (keyboard, mouse, touch-screen, etc...)
*		2.	Don't free your map values (**list) until the user presses ESC
*		3.	If the Program QUITS BY ERROR (unexpectedly): it's still your fualt,
*			but the equivalent of "try/catch" for our purposes here in C is to
*			"let it crash" if you didn't handle your mem allocations, freeing,or
*			index/iteration management properly. It'll crash (for now). Make yo
*			Main_tests READ LOG FILES to compare what IS HAPPENING IN REAL-	
*			TIME to what is EXPECTED TO BE HAPPENING.
*/
int		main(int argc, char *argv[])
{
	int		fd;
	int		_error;
	t_fdf	*fdf;

	if (argc != 2)
		handle_exit("USAGE: ./fdf map_file.\n");
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		handle_exit("ERROR: FILE DOESN'T OPEN PROPERLY.\n");
	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		handle_exit("ERROR: BAD FDF MALLOC\n");
	if (!(fdf = init_fdf(fdf)))
		handle_exit("ERROR: BAD INIT_FDF\n");
	do
	{
		_error = ft_fdf(fd, &fdf);
	} while (_error && /*key_hook_listener("esc") == 0*/)
	{
	/*
	 *	While Loop for ESC Key Hook: EDIT: I don't think we need do/whileAnymore
	 */
	}
	return (_error);
}
