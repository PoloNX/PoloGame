#pragma once

struct Vector2f {
    Vector2f() :x(0.0f), y(0.0f) {}
    Vector2f(const float &_x, const float &_y) :x(_x), y(_y) {}

    float x, y;
};