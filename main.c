/*
** Jo Sega Saturn Engine
** Copyright (c) 2012-2013, Johannes Fetz (johannesfetz@gmail.com)
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the Johannes Fetz nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL Johannes Fetz BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <jo/jo.h>
#define IMG_MAX 1
#define frustrum_x 160
//#define frustrum_xleft 160
#define frustrum_y 120
//#define frustrum_ydown 120
#define frustrum_z 100
int spriteIndex = 0;
int x = 0;
int y = 0;
float z = 1;
char * filenames[] = {"00.TGA", "01.TGA", "02.TGA", "03.TGA", "04.TGA", "05.TGA", "06.TGA", "07.TGA", "08.TGA", "09.TGA", "10.TGA", "11.TGA"};
// char filenames[12][8] ={"00.TGA", "01.TGA", "02.TGA", "03.TGA", "04.TGA", "05.TGA", "06.TGA", "07.TGA", "08.TGA", "09.TGA", "10.TGA", "11.TGA"};
jo_img      bg;

void            my_input()
{
    if (jo_is_pad1_key_down(JO_KEY_R) && spriteIndex < IMG_MAX)
        {
            spriteIndex++;
            my_background();
        }
    else if (jo_is_pad1_key_down(JO_KEY_R) && spriteIndex >= IMG_MAX)
        {
            spriteIndex = 0;
            my_background();
        }

    if (jo_is_pad1_key_down(JO_KEY_L) && spriteIndex > 0)
        {
            spriteIndex--;
            my_background();
        }
    else if (jo_is_pad1_key_down(JO_KEY_L) && spriteIndex <= 0)
        {
            spriteIndex = IMG_MAX;
            my_background();
        }

    if (jo_is_pad1_key_pressed(JO_KEY_UP) && y >= -frustrum_y)
        {
            y--;
        }
    else if (jo_is_pad1_key_pressed(JO_KEY_DOWN) && y <= frustrum_y)
        {
            y++;
        }

    if (jo_is_pad1_key_pressed(JO_KEY_LEFT) && x >= -frustrum_x)
        {
            x--;
        }
    else if (jo_is_pad1_key_pressed(JO_KEY_RIGHT) && x <= frustrum_x)
        {
            x++;
        }

    if (jo_is_pad1_key_pressed(JO_KEY_X /*|| JO_KEY_Y || JO_KEY_Z*/) && z <= frustrum_z)
        {
            z = +0.01;
        }
    else if (jo_is_pad1_key_pressed(JO_KEY_A /*|| JO_KEY_B || JO_KEY_C*/) && z >= -frustrum_z)
        {
            z = -0.01;
        }
    
    if (jo_is_pad1_key_down(JO_KEY_START))
        {
            spriteIndex = 0;
            x = 0;
            y = 0;
            z = 1;
        }
}

void            my_background()
{
    //char filename[6] = "'00.TGA', '01.TGA', '02.TGA', 03.TGA, 04";
    //jo_img      bg;
    bg.data = NULL;
    //jo_tga_loader(&bg, JO_ROOT_DIR, "01.TGA", JO_COLOR_Transparent);
    jo_tga_loader(&bg, JO_ROOT_DIR, filenames[spriteIndex], JO_COLOR_Transparent);
    jo_set_background_sprite(&bg, 0, 0);
    jo_free_img(&bg);
}

void           my_draw(void)
    {
        jo_move_background(x, y);
        jo_zoom_background(z);
        
        jo_printf(0, 0, "Sprite Index:");
        jo_clear_screen_line(1);
        jo_clear_screen_line(2);
        jo_clear_screen_line(3);
        jo_printf(0, 1, "%d", spriteIndex);
        jo_printf(0, 2, "Screen pos.: %d, %d", x, y);
        jo_printf(0, 3, "Zoom: %d", z);
    }

void			jo_main(void)
{
	jo_core_init(JO_COLOR_Black);
    my_background();
    jo_core_add_callback(my_input);
	jo_core_add_callback(my_draw);
	jo_core_run();
}

/*
** END OF FILE
*/
