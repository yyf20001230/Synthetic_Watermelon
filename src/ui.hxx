#pragma once

#include "model.hxx"
#include <ge211.hxx>


struct UI
        : ge211::Abstract_game
{
    //
    // CONSTRUCTOR
    //
public:
    explicit UI(Model&);

    //
    // MEMBER FUNCTIONS (for the view)
    //

protected:
    ge211::Dims<int> initial_window_dimensions() const override;
    void draw(ge211::Sprite_set&) override;
    void on_mouse_up(ge211::Mouse_button, ge211::Posn<int>) override;
    void on_mouse_move(ge211::Posn<int>) override;
    void on_frame(double dt) override;

//private:
    //
    // MEMBER VARIABLE (model reference)
    //

    Model& model;

private:
    /// Color for the background of the game
    ge211::Rectangle_sprite const
            background_sprite{initial_window_dimensions(),
                              ge211::Color(237,229,128)};

    /// Color for the fruit when it's game over
    ge211::Circle_sprite const
            game_over_sprite_1{25,ge211::Color(0,40,40)};
    ge211::Circle_sprite const
            game_over_sprite_2{40,ge211::Color(40,40,40)};
    ge211::Circle_sprite const
            game_over_sprite_3{55,ge211::Color(80,40,40)};
    ge211::Circle_sprite const
            game_over_sprite_4{70,ge211::Color(120,40,40)};
    ge211::Circle_sprite const
            game_over_sprite_5{85,ge211::Color(160,40,40)};
    ge211::Circle_sprite const
            game_over_sprite_6{100,ge211::Color(200,40,40)};
    ge211::Circle_sprite const
            game_over_sprite_7{115,ge211::Color(240,40,40)};

    /// Color for the fruit when the game is in process
    ge211::Image_sprite const
            tier_1_sprite{"tier1.png"};
    ge211::Image_sprite const
            tier_2_sprite{"tier2.png"};
    ge211::Image_sprite const
            tier_3_sprite{"tier3.png"};
    ge211::Image_sprite const
            tier_4_sprite{"tier4.png"};
    ge211::Image_sprite const
            tier_5_sprite{"tier5.png"};
    ge211::Image_sprite const
            tier_6_sprite{"tier6.png"};
    ge211::Image_sprite const
            tier_7_sprite{"tier7.png"};
    ge211::Rectangle_sprite const
            white_line_sprite{{model.config.scene_dims.width,5},
                              ge211::Color(150,150,150)};

    /// sprite and texts for game over
    ge211::Text_sprite game_over_text
            {"GAME OVER!",{"sans.ttf",60}};
    ge211::Image_sprite const
            restart_sprite{"restart.png"};


    /// sprite and texts for game pause
    ge211::Text_sprite pause_text
            {"Paused",{"sans.ttf",60}};
    ge211::Image_sprite const
            pause_sprite{"pause.png"};

    /// sprite for a winning game
    ge211::Text_sprite winning_text
            {"You win!",{"sans.ttf",60}};

    ge211::Text_sprite score_text
            {"",{"sans.ttf",60}};


    ge211:: Font score_font = {"sans.ttf",60};
    ge211:: Text_sprite:: Builder builder;

};