#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
#include "display.h"
#include "config.h"

class MainWindow : public Gtk::Window
{
public:
    MainWindow();
    virtual ~MainWindow();

protected:
    Gtk::Box m_VBox;
    Display display;
    ConfigBox config;

    void handle_toggle();
};

#endif // GTKMM_EXAMPLEWINDOW_H