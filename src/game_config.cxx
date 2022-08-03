

#include "game_config.hxx"

// This is the default (and only) constructor for `Game_config`. It
// determines all the default values of all the member variables.
Game_config::Game_config()
        : scene_dims{600,800},
          fruit_velocity{0,10},
          pause_button{15,15},
          restart_button{scene_dims.width - 100,25},
          top_margin(100),
          fruit_tier(7),
          radius_increment(15),
          initial_radius(10),
          warning_line(300),
          velocity_increment(14)
{ }

