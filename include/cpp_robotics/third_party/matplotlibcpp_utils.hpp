#pragma once

#include "matplotlib-cpp/matplotlibcpp.h"

namespace matplotlibcpp {

void draw_circle(double x, double y, double radius, bool is_fill = false, std::string color = "k") {
    const int N = 100;
    std::vector<double> x_circle, y_circle;
    for (int i = 0; i < N; i++) {
        double angle = 2 * M_PI / N * i;
        x_circle.push_back(x + radius * cos(angle));
        y_circle.push_back(y + radius * sin(angle));
    }
    if (is_fill) {
        fill(x_circle, y_circle, std::map<std::string, std::string>{{"c", color}});
    } else {
        plot(x_circle, y_circle, color);
    }
}

void draw_rectangle(double x, double y, double width, double height, std::string color = "k") {
    std::vector<double> x_rect = {x, x + width, x + width, x, x};
    std::vector<double> y_rect = {y, y, y + height, y + height, y};
    plot(x_rect, y_rect, color);
}

} // namespace matplotlibcpp