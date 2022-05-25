#include "window.h"
#include "display.h"
#include "paramsinput.h"
#include <iostream>

MainWindow::MainWindow()
    : m_VBox(Gtk::ORIENTATION_VERTICAL, 5),
      display(),
      config()
{
    set_title("Three body problem");
    set_border_width(5);
    set_default_size(500, 600);

    add(m_VBox);

    m_VBox.pack_start(display, Gtk::PACK_EXPAND_WIDGET);
    m_VBox.pack_start(config, Gtk::PACK_SHRINK);

    show_all_children();
}

void MainWindow::handle_toggle()
{
    display.toggle_loop();
}

MainWindow::~MainWindow()
{
}