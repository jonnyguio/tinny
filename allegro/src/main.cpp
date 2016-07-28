#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include "../headers/face.h"
#include "../headers/halfedge.h"
#include "../headers/interpreter.h"
#include "../headers/vertex.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_COLOR lineColor;

    Interpreter *interpreter = new Interpreter("./input/1.in");
    string line;

    if (interpreter->File()->is_open()) {
        cout << "File is open" << endl;
        while (getline (*(interpreter->File()),line)) {
          cout << line << endl;
        }
    }

    if(!al_init())
    {
        al_show_native_message_box(NULL, NULL, NULL, "failed to initialize allegro!", NULL, NULL);
        return -1;
    }

    if (!al_init_primitives_addon()) {
        al_show_native_message_box(NULL, NULL, NULL, "failed to initialize primiteves!", NULL, NULL);
    }

    display = al_create_display(640, 480);

    if(!display)
    {
        al_show_native_message_box(NULL, NULL, NULL,
            "failed to initialize display!", NULL, NULL);
        return -1;
    }
    al_clear_to_color(al_map_rgb(255,255,255));

    lineColor = al_map_rgb(0,0,0);
    al_draw_line(0, 0, 100, 100, lineColor, 1);

    al_flip_display();
    al_rest(5.0);
    al_destroy_display(display);

    return 0;

}
