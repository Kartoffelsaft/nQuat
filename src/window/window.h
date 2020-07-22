#pragma once

struct Window
{
    Window();
    ~Window();

    void drawChar(int const x, int const y, char const c);
    void refresh();
    void waitForInput();
};
