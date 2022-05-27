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
    Gtk::Label g_const_label;
    Gtk::SpinButton g_const_input;
    Gtk::Label delay_label;
    Gtk::SpinButton delay_input;
    Gtk::Button submit_button;

    void build_conf_ui();
};

#endif // WINDOW_H