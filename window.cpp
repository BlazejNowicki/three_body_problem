#include "window.h"
#include "display.h"
#include <iostream>

MainWindow::MainWindow()
    : m_VBox(Gtk::ORIENTATION_VERTICAL, 5),
      m_Label("Normal label"),
      m_Label2("Another normal label"),
      display(),
      toggle_button("Toggle", true)
{
    set_title("Three body problem");
    set_border_width(5);
    set_default_size(500, 600);

    add(m_VBox);

    toggle_button.signal_clicked().connect( sigc::mem_fun(*this,
              &MainWindow::handle_toggle) );

    m_VBox.pack_start(display, Gtk::PACK_EXPAND_WIDGET);
    m_VBox.pack_start(m_Label, Gtk::PACK_SHRINK);
    m_VBox.pack_start(m_Label2, Gtk::PACK_SHRINK);
    m_VBox.pack_start(toggle_button, Gtk::PACK_SHRINK);

    show_all_children();
}

void MainWindow::handle_toggle()
{
    display.toggle_loop();
}

MainWindow::~MainWindow()
{
}