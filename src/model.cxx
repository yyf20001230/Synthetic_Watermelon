#include "model.hxx"
#include "fruit.hxx"
#include "fruit_sets.hxx"



Model::Model(Game_config const& config)
        :  config(Game_config()),
           set_(fruit_sets()),
           generated_fruit(fruit({Game_config().scene_dims.width / 2,
                                  Game_config().top_margin},
                                 false,
                                 1)),
           is_game_over(false),
           is_paused(false)

{
}

void
Model::on_frame(double dt){


    for (fruit& subject : set_.fruits){

        /// if the next frame of the fruit touches any edge, make it stop
        /// (false), then reposition it so that it is tangent to the edge
        if (subject.next(dt).touch_edge()){
            subject.set_life(false);
            while (subject.touch_edge()){
                subject.move_center(0,-1);
            }
            while (!subject.touch_edge()){
                subject.move_center(0,1);
            }
        }

        /// if else, update each live member in the fruit st
        else{
            if (subject.get_live()){
                subject = subject.next(dt);
            }
        }
    }

    /// check for merge, overlap, and float
    set_.merge();
    set_.group_overlapped();
    set_.float_check();

}

void Model::reset_game(){
    set_.fruits.clear();
    is_game_over = false;
    generated_fruit = fruit({Game_config().scene_dims.width / 2,
                                   Game_config().top_margin},
                                  false,1);
    set_.score_ = 0;
}

void Model::pause_game(){
    is_paused = !is_paused;
}


