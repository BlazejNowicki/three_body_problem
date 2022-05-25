#include "paramsinput.h"

ParamsInput::ParamsInput() : Gtk::Box(Gtk::ORIENTATION_VERTICAL, 5),
                             pos_x_label("Initial x of position"),
                             pos_y_label("Initial y of position"),
                             vel_x_label("Initial x of velocity"),
                             vel_y_label("Initial y of velocity"),
                             mass_label("Initial mass")
{
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
ParamsInput::~ParamsInput(){};