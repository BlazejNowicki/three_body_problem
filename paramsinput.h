#ifndef PARAMS_INPUT
#define PARAMS_INPUT

#include <gtkmm.h>

class ParamsInput : public Gtk::Box
{
public:
    ParamsInput();
    virtual ~ParamsInput();

protected:
    Gtk::Label pos_x_label;
    Gtk::Label pos_y_label;
    Gtk::Label vel_x_label;
    Gtk::Label vel_y_label;
    Gtk::Label mass_label;
};

#endif // PARAMS_INPUT