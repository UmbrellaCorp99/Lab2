// Alexander Young
//Lab 2

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

//The two functions included, one for shape color and the other for drawing the shape
ALLEGRO_COLOR shapeColor();
void drawFilledCircle(ALLEGRO_COLOR color, const int W, const int H, int xadd, int yadd);

//main method
int main()
{
    //creates a pointer to a display in memory
    ALLEGRO_DISPLAY * display = NULL;

    //throws an error if Allegro fails to initiate
    if (!al_init()) {
        al_show_native_message_box(NULL, "Error", "Allegro has failed to initiate", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    //sets up an 800x600 display and throws an error if the display does not initiate
    int width = 800, height =600;
    display = al_create_display(width, height);
    if (display == NULL) {
        al_show_native_message_box(display, "Error", "Failed to initiate the display", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    //creates a pointer to an event queue in memory and creates an ALLEGRO_EVENT type called Event
    ALLEGRO_EVENT_QUEUE * EventQueue = NULL;
    ALLEGRO_EVENT Event;

    //sets up an event queue and throws an error if the queue fails to initiate
    EventQueue = al_create_event_queue();
    if (EventQueue == NULL) {
        al_show_native_message_box(display, "Error", "Failed to initiate the event queue", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    //throws an error if Allegro fails to install the keyboard functionality
    if (!al_install_keyboard()) {
        al_show_native_message_box(NULL, "Error", "Failed to install the keyboard", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    //ties the keyboard to the event queue
    al_register_event_source(EventQueue, al_get_keyboard_event_source());

    //initializes Allegro primitives addon
    al_init_primitives_addon();

    //ties the display to the event queue
    al_register_event_source(EventQueue, al_get_display_event_source(display));

    //exit variable used for exiting the program, the keyDown variable used for setting the initial state of the keyboard
    bool exit = false, keyDown = false;

    //variables used to modify the current position of the primitive as keys are pressed
    int xadd = 0, yadd = 0;

    //game loop
    while (exit == false) {
        //clears the white screen and redraws the filled circle primitive in the new/current position 
        al_clear_to_color(al_map_rgb(255, 255, 255));
        drawFilledCircle(shapeColor(), width, height, xadd, yadd);
        al_flip_display();

        al_wait_for_event(EventQueue, &Event);

        //if there is a key pressed down, check for the following keys
        if (Event.type == ALLEGRO_EVENT_KEY_DOWN) {
            //moves the primitive up if the up arrow key is pressed
            if (Event.keyboard.keycode == ALLEGRO_KEY_UP) {
                yadd += -5;
            }
            //moves the primitive down if the down arrow key is pressed
            if (Event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
                yadd += 5;
            }
            //moves the primitive left if the left arrow key is pressed
            if (Event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                xadd += -5;
            }
            //moves the primitive right if the right arrow key is pressed
            if (Event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                xadd += 5;
            }
            //moves the primitive up and left if the U key is pressed
            if (Event.keyboard.keycode == ALLEGRO_KEY_U) {
                xadd += -5;
                yadd += -5;
            }
            //moves the primitive down and right if the D key is pressed
            if (Event.keyboard.keycode == ALLEGRO_KEY_D) {
                xadd += 5;
                yadd += 5;
            }
            //moves the primitive up and right if the R key is pressed
            if (Event.keyboard.keycode == ALLEGRO_KEY_R) {
                xadd += 5;
                yadd += -5;
            }
            //moves the primitive down and left if the L key is pressed
            if (Event.keyboard.keycode == ALLEGRO_KEY_L) {
                xadd += -5;
                yadd += 5;
            }
        }
        //resets the KeyDown variable to false once a key is released
        else if (Event.type == ALLEGRO_EVENT_KEY_UP) {
            keyDown = false;
        }
        //closes the display if the X is pressed (on the window's tab, not the keyboard)
        else if(Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            exit = true;
        }
    }

    //releases the memory taken by the display and EventQueue
    al_destroy_display(display);
    al_destroy_event_queue(EventQueue);
}

//Function for defining the color black to be used for primitives
//Takes no parameters
//returns an Allegro color mapping for the color black
ALLEGRO_COLOR shapeColor() {
    return al_map_rgb(0, 0, 0);
}

//Function to define and draw a filled-in circle primitive
//Takes an ALLEGRO_COLOR, x and y starting position variables W and H, and x and y modifier variables xadd and yadd as parameters
//Void return type, calls the al_draw_filled_circle Allegro method to draw a filled circle
void drawFilledCircle(ALLEGRO_COLOR color, const int W, const int H, int xadd, int yadd) {
    int cx = W / 2 + xadd;
    int cy = H / 2 + yadd;
    int r = 50;
    al_draw_filled_circle(cx, cy, r, color);
}