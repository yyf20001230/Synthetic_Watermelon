#pragma once

#include <ge211.hxx>


struct Game_config
{
    // Constructs an instance with the default parameters.
    Game_config();

    // The dimensions of the whole window:
    ge211::Dims<int> scene_dims;

    // The fruit's initial velocity {width, height}:
    ge211::Dims<int> fruit_velocity;

    // The location of the pause button:
    ge211::Dims<int> pause_button;

    // The location of the restart button:
    ge211::Dims<int> restart_button;



    // The height of the stack of fruits that triggers game over:
    int top_margin;

    // Player clears the game if this fruit tier is made:
    int fruit_tier;

    // The difference in radius between each tier of fruit:
    int radius_increment;

    // The initial radius of a fruit with tier 1:
    int initial_radius;

    // The game shows a warning line whenever the fruit reach that height
    int warning_line;


    // The constant for the velocity increment to simulate gravity
    int velocity_increment;
};