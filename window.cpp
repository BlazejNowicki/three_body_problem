#include "window.h"
#include "display.h"
#include "paramsinput.h"
#include <iostream>

MainWindow::MainWindow() : m_VBox(Gtk::ORIENTATION_VERTICAL, 5),
                           m_HBox(Gtk::ORIENTATION_HORIZONTAL, 5),
                           display(),
                           globals(Gtk::ORIENTATION_VERTICAL, 5),
                           g_adjustment(Gtk::Adjustment::create(1.0, 1.0, 100.0, 1.0, 10.0, 0.0)),
                           delta_adjustment(Gtk::Adjustment::create(0.001, 0.0, 10.0, 0.1, 1, 0.0)),
                           steps_adjustment(Gtk::Adjustment::create(1000.0, 1.0, 10000.0, 10, 100, 0.0)),
                           g_const_input(g_adjustment),
                           delta_input(delta_adjustment, 1.0, 6),
                           steps_input(steps_adjustment),
                           g_const_label("G constant"),
                           submit_button("Run"),
                           delta_label("Delta"),
                           instruction("Enter simulation parameters and press Run"),
                           steps_label("Steps per frame") {
    set_title("Three body problem");
    set_border_width(5);
    set_default_size(500, 600);

    add(m_VBox);

    m_VBox.pack_start(display, Gtk::PACK_EXPAND_WIDGET);
    m_VBox.pack_start(separator, Gtk::PACK_SHRINK);
    m_VBox.pack_start(instruction, Gtk::PACK_SHRINK);
    m_VBox.pack_start(separator2, Gtk::PACK_SHRINK);


    build_conf_ui();

    show_all_children();
}

void MainWindow::build_conf_ui() {
    m_VBox.pack_start(m_HBox, Gtk::PACK_SHRINK);
    m_HBox.pack_start(first_obj, Gtk::PACK_SHRINK);
    m_HBox.pack_start(second_obj, Gtk::PACK_SHRINK);
    m_HBox.pack_start(third_obj, Gtk::PACK_SHRINK);

    globals.pack_start(g_const_label, Gtk::PACK_SHRINK);
    globals.pack_start(g_const_input, Gtk::PACK_SHRINK);
    globals.pack_start(delta_label, Gtk::PACK_SHRINK);
    globals.pack_start(delta_input, Gtk::PACK_SHRINK);
    globals.pack_start(steps_label, Gtk::PACK_SHRINK);
    globals.pack_start(steps_input, Gtk::PACK_SHRINK);
    globals.pack_start(submit_button, Gtk::PACK_EXPAND_WIDGET);

    submit_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::handleClick));

    m_HBox.pack_start(globals, Gtk::PACK_SHRINK);
}

void MainWindow::handleClick() {
    Vector pos = first_obj.getPosition();
    std::vector <Vector> positions = {first_obj.getPosition(), second_obj.getPosition(), third_obj.getPosition()};
    std::vector <Vector> velocities = {first_obj.getVelocity(), second_obj.getVelocity(), third_obj.getVelocity()};
    std::vector<float> masses = {first_obj.getMass(), second_obj.getMass(), third_obj.getMass()};
    float delta = delta_input.get_value();
    float G = g_const_input.get_value();
    int steps = steps_input.get_value();

    std::shared_ptr<Engine> engine = std::make_shared<Engine>(positions, velocities, masses, G, delta, steps);
    this->display.setEngine(engine);
}

MainWindow::~MainWindow() {
}