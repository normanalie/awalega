#include "colors.h"

// JALBY & Kevin je vous aime <3

Color rgb_to_hex(ColorRGB rgb)
{
    rgb.r = (rgb.r < 0) ? 0 : ((rgb.r > 255) ? 255 : rgb.r);
    rgb.g = (rgb.g < 0) ? 0 : ((rgb.g > 255) ? 255 : rgb.g);
    rgb.b = (rgb.b < 0) ? 0 : ((rgb.b > 255) ? 255 : rgb.b);
    Color hex = ((uint32_t)rgb.r << 16) | ((uint32_t)rgb.g << 8) | (uint32_t)rgb.b;

    return hex;
}

ColorRGB hex_to_rgb(Color hex)
{
    ColorRGB rgb;
    rgb.r = (hex >> 16) & 0xFF;
    rgb.g = (hex >> 8) & 0xFF;
    rgb.b = hex & 0xFF;

    return rgb;
}