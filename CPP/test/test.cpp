/* Copyright 2016 - 2017 Marc Volker Dickmann
 * Project: LibBMP
 */
#include <stdio.h>
#include "../libbmp.h"
#include <iostream>


int
main ()
{
	BmpImg img;

	img.read ("test.bmp");

	// n - 1 because we use negative loops.
	const int width = img.get_width () - 1;
	const int height = img.get_height () - 1;
	int amnt_b = 0, amnt_w = 0;

	// Count the amount of black and white pixels:
	// Use negative loops to improve performance
	for (int y = height, x; y >= 0; y--)
	{
		for (x = width; x >= 0; x--)
		{
			if (img.red_at (x, y) < 128 &&
			    img.green_at (x, y) < 128 &&
			    img.blue_at (x, y) < 128)
			{
				amnt_b++;
			}
			else
			{
				amnt_w++;
			}
		}
	}

	std::cout << "Amount of black pixels:\t" << amnt_b << "\n";
	std::cout << "Amount of white pixels:\t" << amnt_w << "\n";
	return 0;
}