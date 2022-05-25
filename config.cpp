#include "config.h"

ConfigBox::ConfigBox() : Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 5),
                         first_obj(),
                         second_obj(),
                         third_obj()
{
    pack_start(first_obj, Gtk::PACK_EXPAND_WIDGET);
    pack_start(second_obj, Gtk::PACK_EXPAND_WIDGET);
    pack_start(third_obj, Gtk::PACK_EXPAND_WIDGET);
};
ConfigBox::~ConfigBox(){};