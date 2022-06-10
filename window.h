#ifndef WINDOW_H
#define WINDOW_H

#include <gtkmm.h>
#include "display.h"
#include "paramsinput.h"

class MainWindow : public Gtk::Window
{
public:
    MainWindow();
    virtual ~MainWindow();

protected:
    Gtk::Box m_VBox;
    Gtk::Box m_HBox;
    Display display;

    ParamsInput first_obj;
    ParamsInput second_obj;
    ParamsInput third_obj;

    Gtk::Box globals;
    Glib::RefPtr<Gtk::Adjustment> g_adjustment;
    Glib::RefPtr<Gtk::Adjustment> delta_adjustment;
    Glib::RefPtr<Gtk::Adjustment> steps_adjustment;
    Gtk::Label g_const_label;
    Gtk::SpinButton g_const_input;
    Gtk::Label delta_label;
    Gtk::SpinButton delta_input;
    Gtk::Label steps_label;
    Gtk::SpinButton steps_input;
    Gtk::Button submit_button;
    Gtk::Label instruction;
    Gtk::Separator separator;
    Gtk::Separator separator2;

    void build_conf_ui();

    void handleClick();
};

#endif // WINDOW_H