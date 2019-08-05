/*
  * Simple Xlib application drawing a box in a window.
  * gcc input.c -o output -lX11
  */
 
/* /1/ */
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void)
{
    Display *display;
    Window window;
    XEvent event;
    char *msg = "Hello, World!";
    int s;

    /* /2/ some basic X11 setup */
    /* open connection with the server */
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }
 
    s = DefaultScreen(display);
 
    /* create window */
    window = XCreateSimpleWindow(display, RootWindow(display, s), 10, 10, 200, 200, 1,
                           BlackPixel(display, s), WhitePixel(display, s));
 
    /* select kind of events we are interested in */
    XSelectInput(display, window, ExposureMask | KeyPressMask);
 
    /* map (show) the window */
    XMapWindow(display, window);
 
    /* /3/ event loop */
    for (;;)
    {
        XNextEvent(display, &event);
 
        /* /4/ draw or redraw the window */
        if (event.type == Expose)
        {
            XFillRectangle(display, window, DefaultGC(display, s), 20, 20, 10, 10);
            XDrawString(display, window, DefaultGC(display, s), 50, 50, msg, strlen(msg));
        }
        /* /5/ exit on key press */
        if (event.type == KeyPress)
            break;
    }
 
    /* /6/ close connection to server */
    XCloseDisplay(display);
 
    return 0;
 }
