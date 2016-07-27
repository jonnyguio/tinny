#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

int main(int argc, char **argv) {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_COLOR lineColor;


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
