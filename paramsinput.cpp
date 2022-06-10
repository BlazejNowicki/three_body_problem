#include "paramsinput.h"
#include "engine.h"
#include <string>

ParamsInput::ParamsInput() : Gtk::Box(Gtk::ORIENTATION_VERTICAL, 5),
                             pos_x_adjustment(Gtk::Adjustment::create(0.0, -300.0, 300.0, 10.0, 50.0, 0.0)),
                             pos_y_adjustment(Gtk::Adjustment::create(0.0, -300.0, 300.0, 10.0, 50.0, 0.0)),
                             vel_x_adjustment(Gtk::Adjustment::create(0.0, -10.0, 10.0, 0.01, 0.1, 0.0)),
                             vel_y_adjustment(Gtk::Adjustment::create(0.0, -10.0, 10.0, 0.01, 0.1, 0.0)),
                             mass_adjustment(Gtk::Adjustment::create(1.0, 0.0, 100.0, 1.0, 10.0, 0.0)),
                             pos_x_input(pos_x_adjustment),
                             pos_y_input(pos_y_adjustment),
                             vel_x_input(vel_x_adjustment, 1, 2),
                             vel_y_input(vel_y_adjustment, 1, 2),
                             mass_input(mass_adjustment),
                             pos_x_label("Initial x of position"),
                             pos_y_label("Initial y of position"),
                             vel_x_label("Initial x of velocity"),
                             vel_y_label("Initial y of velocity"),
                             mass_label("Initial mass") {
    pack_start(pos_x_label, Gtk::PACK_SHRINK);
    pack_start(pos_x_input, Gtk::PACK_SHRINK);

    pack_start(pos_y_label, Gtk::PACK_SHRINK);
    pack_start(pos_y_input, Gtk::PACK_SHRINK);

    pack_start(vel_x_label, Gtk::PACK_SHRINK);
    pack_start(vel_x_input, Gtk::PACK_SHRINK);

    pack_start(vel_y_label, Gtk::PACK_SHRINK);
    pack_start(vel_y_input, Gtk::PACK_SHRINK);

    pack_start(mass_label, Gtk::PACK_SHRINK);
    pack_start(mass_input, Gtk::PACK_SHRINK);
}

Vector ParamsInput::getPosition() {
    std::string str_x = pos_x_input.get_text();
    std::string str_y = pos_y_input.get_text();

    Vector position = {std::stof(str_x), std::stof(str_y)};
    return position;
}

Vector ParamsInput::getVelocity() {
    std::string str_x = vel_x_input.get_text();
    std::string str_y = vel_y_input.get_text();

    Vector velocity = {std::stof(str_x), std::stof(str_y)};
    return velocity;
}

float ParamsInput::getMass() {
    std::string str = mass_input.get_text();
    return std::stof(str);
}


ParamsInput::~ParamsInput() {};