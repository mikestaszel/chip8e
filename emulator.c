#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "chipee.h"
#include "display.h"


int main(int argc, char** argv) {
    // load fonts
    load_fonts();

    srand((unsigned int)time(NULL));

    // load ROM
    // load_rom("roms/ibm.ch8");
    // load_rom("roms/logo.ch8");
    // load_rom("roms/sierpinski.ch8");
    // load_rom("roms/trip8.ch8");
    // load_rom("roms/maze.ch8");
    load_rom("roms/pong1p.ch8");

    // initialize display
    init_chipee_display();

    // game loop
    while (1) {
        emulate_cycle();
        sdl_keypress(keypad);

        if (draw_flag) {
            draw_screen(gfx);
        }

        // hack to limit fps
        usleep(1000);
    }

    stop_chipee_display();

    return 1;
}