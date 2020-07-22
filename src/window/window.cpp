#include <ncurses.h>
#include <optional>
#include <tuple>

#include "window.h"

Window::Window()
{
    initscr();
    cbreak();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    curs_set(0);
}

Window::~Window()
{
    endwin();
}

std::tuple<int, int> Window::middle() const
{
    return {getmaxx(stdscr)/2, getmaxy(stdscr)/2};
}

std::tuple<int, int> Window::size() const
{
    return {getmaxx(stdscr), getmaxy(stdscr)};
}

void Window::drawChar(int const x, int const y, char const c)
{mvaddch(y, x, c); move(999, 999);}

void Window::clean()
{erase();}

void Window::refreshScreen()
{refresh();}

std::optional<int> Window::getInput()
{
    auto c = getch();
    return c == ERR? std::nullopt : std::optional(c);
}
