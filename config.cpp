#include "config.h"

ConfigBox::ConfigBox() : Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 5),
                         first_obj(),
                         second_obj(),
                         third_obj(),
                         globals(Gtk::ORIENTATION_VERTICAL, 5),
                         g_const_label("G constant"),
                         g_const_input(),
                         submit_button("Run")

{
    pack_start(first_obj, Gtk::PACK_SHRINK);
    pack_start(second_obj, Gtk::PACK_SHRINK);
    pack_start(third_obj, Gtk::PACK_SHRINK);

    globals.pack_start(g_const_label, Gtk::PACK_SHRINK);
    globals.pack_start(g_const_input, Gtk::PACK_SHRINK);
    globals.pack_start(submit_button, Gtk::PACK_EXPAND_WIDGET);

    pack_start(globals, Gtk::PACK_SHRINK);
};
ConfigBox::~ConfigBox(){};