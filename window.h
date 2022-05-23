#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
#include "display.h"

class MainWindow : public Gtk::Window
{
public:
    MainWindow();
    virtual ~MainWindow();

protected:
    Gtk::Box m_VBox;
    Gtk::Label m_Label;
    Gtk::Label m_Label2;
    Display display;
    Gtk::Button toggle_button;

    void handle_toggle();
};

#endif // GTKMM_EXAMPLEWINDOW_H