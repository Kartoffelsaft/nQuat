#pragma once

#include <tuple>
#include <optional>

struct Window
{
    Window();
    ~Window();

    std::tuple<int, int> middle() const;
    std::tuple<int, int> size() const;

    void drawChar(int const, int const, char const);
    void drawLine(int const, int const, char const, int const);
    void clean();
    void refreshScreen();
    std::optional<int> getInput();
};
