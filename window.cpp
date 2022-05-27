#include "window.h"
#include "display.h"
#include "paramsinput.h"
#include <iostream>

MainWindow::MainWindow() : m_VBox(Gtk::ORIENTATION_VERTICAL, 5),
                           m_HBox(Gtk::ORIENTATION_HORIZONTAL, 5),
                           display(),
                           globals(Gtk::ORIENTATION_VERTICAL, 5),
                           g_const_label("G constant"),
                           submit_button("Run"),
                           delay_label("Frame delay")
{
    set_title("Three body problem");
    set_border_width(5);
    set_default_size(500, 600);

    add(m_VBox);

    m_VBox.pack_start(display, Gtk::PACK_EXPAND_WIDGET);

    build_conf_ui();

    show_all_children();
}

void MainWindow::build_conf_ui()
{
    m_VBox.pack_start(m_HBox, Gtk::PACK_SHRINK);

    m_HBox.pack_start(first_obj, Gtk::PACK_SHRINK);
    m_HBox.pack_start(second_obj, Gtk::PACK_SHRINK);
    m_HBox.pack_start(third_obj, Gtk::PACK_SHRINK);

    globals.pack_start(g_const_label, Gtk::PACK_SHRINK);
    globals.pack_start(g_const_input, Gtk::PACK_SHRINK);
    globals.pack_start(delay_label, Gtk::PACK_SHRINK);
    globals.pack_start(delay_input, Gtk::PACK_SHRINK);
    globals.pack_start(submit_button, Gtk::PACK_EXPAND_WIDGET);

    m_HBox.pack_start(globals, Gtk::PACK_SHRINK);
}

MainWindow::~MainWindow()
{
}