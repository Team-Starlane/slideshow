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
#define IMG_MAX 11
int spriteIndex = 0;
char filenames[12][8] ={"00.tga\0", "01.tga\0", "\02.tga\0", "\03.tga\0", "\04.tga\0", "\05.tga\0", "\06.tga\0", "\07.tga\0", "\08.tga\0", "\09.tga\0", "\10.tga\0", "\11.tga\0"};
jo_img      bg;


void            my_input()
{
    if (jo_is_pad1_key_down(JO_KEY_R) && spriteIndex < IMG_MAX)
        {
            spriteIndex++;
        }
    else if (jo_is_pad1_key_down(JO_KEY_R) && spriteIndex >= IMG_MAX)
        {
            spriteIndex = 0;
        }

    if (jo_is_pad1_key_down(JO_KEY_L) && spriteIndex > 0)
        {
            spriteIndex--;
        }
    else if (jo_is_pad1_key_down(JO_KEY_L) && spriteIndex <= 0)
        {
            spriteIndex = IMG_MAX;
        }

    
}

void			my_draw(void)
{
	/* Very usefull for debuging purpose see also jo/tools.h
	jo_printf(0, 0, jo_get_last_error());*/

    //jo_tga_loader(&bg, JO_ROOT_DIR, filenames[spriteIndex], JO_COLOR_Transparent);

	//jo_clear_background();
    //jo_move_background(); 
    //jo_zoom_background();
}

void            my_background()
{

    //char filename[6] = "'00.tga', '01.tga', '02.tga', 03.tga, 04";
    
    bg.data = NULL;
    //jo_tga_loader(&bg, JO_ROOT_DIR, filenames[spriteIndex], JO_COLOR_Transparent);
    jo_tga_loader(&bg, JO_ROOT_DIR, filenames[spriteIndex], JO_COLOR_Transparent);
    jo_set_background_sprite(&bg, 0, 0);
    jo_free_img(&bg);
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
