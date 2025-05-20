// Alexander Young
//Lab 2

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

int main()
{
    ALLEGRO_DISPLAY* display = NULL;

    if (!al_init()) {
        al_show_native_message_box(NULL, "Error", "Allegro has failed to initiate", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    int width = 800, height =600;
    display = al_create_display(height, width);
    if (display == NULL) {
        al_show_native_message_box(display, "Error", "Failed to initiate the display", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    ALLEGRO_EVENT_QUEUE* EventQueue = NULL;
    ALLEGRO_EVENT Event;

    EventQueue = al_create_event_queue();
    if (EventQueue == NULL) {
        al_show_native_message_box(display, "Error", "Failed to initiate the event queue", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

}