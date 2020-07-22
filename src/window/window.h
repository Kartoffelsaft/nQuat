#pragma once

#include <tuple>
#include <optional>

struct Window
{
    Window();
    ~Window();

    std::tuple<int, int> middle() const;
    std::tuple<int, int> size() const;

    void drawChar(int const x, int const y, char const c);
    void clean();
    void refreshScreen();
    std::optional<int> getInput();
};
