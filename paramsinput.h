#ifndef PARAMS_INPUT
#define PARAMS_INPUT

#include <gtkmm.h>
#include "engine.h"

class ParamsInput : public Gtk::Box
{
public:
    ParamsInput();
    virtual ~ParamsInput();

    Vector getPosition();
    Vector getVelocity();
    float getMass();

protected:
    Glib::RefPtr<Gtk::Adjustment> pos_x_adjustment;
    Glib::RefPtr<Gtk::Adjustment> pos_y_adjustment;
    Glib::RefPtr<Gtk::Adjustment> vel_x_adjustment;
    Glib::RefPtr<Gtk::Adjustment> vel_y_adjustment;
    Glib::RefPtr<Gtk::Adjustment> mass_adjustment;
    Gtk::Label pos_x_label;
    Gtk::Label pos_y_label;
    Gtk::Label vel_x_label;
    Gtk::Label vel_y_label;
    Gtk::Label mass_label;
    Gtk::SpinButton pos_x_input;
    Gtk::SpinButton pos_y_input;
    Gtk::SpinButton vel_x_input;
    Gtk::SpinButton vel_y_input;
    Gtk::SpinButton mass_input;
};

#endif // PARAMS_INPUT