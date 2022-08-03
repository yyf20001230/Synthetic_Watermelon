#pragma once

#include <ge211.hxx>
#include "fruit.hxx"
#include "fruit_sets.hxx"
#include "game_config.hxx"
#include <vector>

//
// TODO: Sketch the structure of your model and declare its operations.
//
struct Model{

public:
    explicit Model(Game_config const& config = Game_config());
    void reset_game();
    void pause_game();
    void on_frame(double);

//private:

    /// The configuration parameters of the model. See game_config.hxx for a
    /// description of what this determines. Models can be constructed with
    /// different configurations, but the configuration never changes on an
    /// existing model.
    Game_config const config;

    /// the fruit set that are stacked on the screen
    fruit_sets set_;

    /// the randomly generated fruit appears at the top of the screen
    fruit generated_fruit;

    /// whether the game is over
    bool is_game_over;

    /// whether the game is paused
    bool is_paused;
};


