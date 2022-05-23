#include "window.h"
#include "display.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>

int main(int argc, char **argv)
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");


    MainWindow win;

    // Gtk::Window win;
    // win.set_title("Cairomm Clock");
    // Gtk::Box box;

    // Clock c;
    // win.add(c);
    // c.show();

    return app->run(win);
}
