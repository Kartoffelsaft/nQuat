#include <ncurses.h>

#include "window.h"

Window::Window()
{
    initscr();
    cbreak();
    keypad(stdscr, true);
}

Window::~Window()
{
    endwin();
}

void Window::drawChar(int const x, int const y, char const c)
{mvaddch(x, y, c);}

void Window::refresh()
{refresh();}

void Window::waitForInput()
{getch();}
