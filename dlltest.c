/*
 * clear.c
 *
 * Copyright (c) 2015 Matt Schneeberger <matt@unifyingsolution.com>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 *     1.  Redistributions of source code must retain the above copyright notice, this list of
 *         conditions and the following disclaimer.
 *     2.  Redistributions in binary form must reproduce the above copyright notice, this list
 *         of conditions and the following disclaimer in the documentation and/or other materials
 *         provided with the distribution.
 *     3.  Neither the name of the owner nor the names of its contributors may be used to endorse
 *         or promote products derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdio.h>
#include <unistd.h>
#include "ws2811.h"

#define ARRAY_SIZE(stuff)                        (sizeof(stuff) / sizeof(stuff[0]))

// TODO These are currently compiled in, but they should be in a config file or something
#define WIDTH                                   8
#define HEIGHT                                  8
#define LED_COUNT								HEIGHT * WIDTH

int matrix[LED_COUNT];

void set_matrix(int c)
{
	int i;
	for (i = 0; i < LED_COUNT; i++)
	{
		matrix[i] = c;
	}
}

int main(int argc, char *argv[])
{

	// init
	set_matrix(0);
	setleds(matrix, NUM_LEDS);

	int brightness = 0;
	int goingUp = 1;
	while (1)
	{
		int pixelValue = ((brightness & 0xFF) << 16) + ((brightness & 0xFF) << 8) + (brightness & 0xFF);
		set_matrix(pixelValue);
		setleds(WIDTH, HEIGHT, matrix);

		if (brightness == 0) goingUp = 1;
		if (brightness == 0xFF) goingUp = 0;

		if (goingUp) brightness++;
		else brightness--;
		usleep(5000);
	}

	return 0;
}
