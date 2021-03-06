#pragma once

#include "options/options.hpp"
using namespace options;
#include "spline/spline.hpp"

struct settings_accela : opts
{
    struct gains
    {
        double x, y;
    };

    static constexpr gains rot_gains[16] =
    {
        { 11, 500 },
        { 9, 300 },
        { 6, 150 },
        { 2.66, 35 },
        { 1.66, 8 },
        { 1, 1.5 },
        { .5, .4 },
    };

    static constexpr gains pos_gains[16] =
    {
        { 9, 200 },
        { 8, 150 },
        { 7, 110 },
        { 5, 60 },
        { 3, 24 },
        { 2, 7.5 },
        { 1.66, 4.5 },
        { 1.33, 2.25 },
        { .66, .75 },
        { .33, .375 },
        { 0, 0 },
    };

    static void make_splines(spline& rot, spline& pos);

    value<slider_value> rot_sensitivity, pos_sensitivity;
    value<slider_value> rot_deadzone, pos_deadzone;
    value<slider_value> ewma;
    value<slider_value> rot_nonlinearity;
    settings_accela() :
        opts("accela-sliders"),
        rot_sensitivity(b, "rotation-sensitivity", slider_value(1.5, .05, 2.5)),
        pos_sensitivity(b, "translation-sensitivity", slider_value(1., .05, 1.5)),
        rot_deadzone(b, "rotation-deadzone", slider_value(.03, 0, .1)),
        pos_deadzone(b, "translation-deadzone", slider_value(.1, 0, 1)),
        ewma(b, "ewma", slider_value(0, 0, 200)),
        rot_nonlinearity(b, "rotation-nonlinearity", slider_value(1, 1, 1.25))
    {}
};
