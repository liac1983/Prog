#include "Color.h"

Color::Color(unsigned char red, unsigned char green, unsigned char blue): red_(red), green_(green), blue_(blue) { }
Color::Color(const Color &b): red_(b.red_), green_(b.green_), blue_(b.blue_) { }

const Color Color::RED(255, 0, 0);
const Color Color::GREEN(0, 255, 0);
const Color Color::BLUE(0, 0, 255);
const Color Color::BLACK(0, 0, 0);
const Color Color::WHITE(255, 255, 255);

unsigned char Color::red() const {
    return red_;
}

unsigned char Color::green() const {
    return green_;
}

unsigned char Color::blue() const {
    return blue_;
}

bool Color::equal_to(const Color& other) const {
    return red_ == other.red_ &&
           green_ == other.green_ &&
           blue_ == other.blue_;
}

void Color::invert() {
    red_ = 255 - red_;
    green_ = 255 - green_;
    blue_ = 255 - blue_;
}