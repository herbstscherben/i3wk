#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

const unsigned int NUM_WORKSPACES = 5;
const unsigned int WINDOW_WIDTH   = 50;
const unsigned int WINDOW_HEIGHT  = 50;

int main()
{
  Display* display;
  Window windows[NUM_WORKSPACES];
  int screen = 0;
  XEvent event;

  display = XOpenDisplay(NULL);
  if (display == NULL)
  {
    fprintf(stderr, "Failed to open display!");
    return EXIT_FAILURE;
  }

  screen = DefaultScreen(display);
  for (int i = 0; i < NUM_WORKSPACES; i++)
  {
    int x = i * WINDOW_WIDTH;
    int y = 0;

    windows[i] = XCreateSimpleWindow(
      display,
      RootWindow(display, screen),
      x,
      y,
      WINDOW_WIDTH,
      WINDOW_WIDTH,
      1,
      BlackPixel(display, screen),
      WhitePixel(display, screen)
    );
    XSetWindowAttributes windowAttributes;
    windowAttributes.override_redirect = true;
    XChangeWindowAttributes(display, windows[i], CWOverrideRedirect, &windowAttributes);
    XMapWindow(display, windows[i]);
  }

  while (true)
  {
    XNextEvent(display, &event);
  }

  XCloseDisplay(display);
  return EXIT_SUCCESS;
}
