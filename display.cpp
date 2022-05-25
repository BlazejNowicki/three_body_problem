#include <ctime>
#include <cmath>
#include <cairomm/context.h>
#include <glibmm/main.h>
#include "display.h"
#include <iostream>

Display::Display()
    : m_radius(0.42), m_line_width(0.05), running(false), engine()
{
    toggle_loop();
}

void Display::toggle_loop()
{
    running = !running;
    if (running)
        Glib::signal_timeout().connect(sigc::mem_fun(*this, &Display::on_timeout), 16);
}

Display::~Display()
{
}

bool Display::on_draw(const Cairo::RefPtr<Cairo::Context> &cr)
{
    Vector position;
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    cr->translate(width/2, height/2);
    cr->set_line_width(m_line_width);

    cr->save();
    cr->set_source_rgba(0.129, 0.16, 0.187, 1);
    cr->paint();
    cr->restore();

    cr->set_source_rgba(1.0, 1.0, 1.0, 0.8);


    cr->save();
    position = engine.getCoordinates(0);
    cr->arc(position.x, -position.y, 15, 0, 2 * M_PI);
    cr->fill();

    cr->save();
    position = engine.getCoordinates(1);
    cr->arc(position.x, -position.y, 15, 0, 2 * M_PI);
    cr->fill();

    cr->save();
    position = engine.getCoordinates(2);
    cr->arc(position.x, -position.y, 15, 0, 2 * M_PI);
    cr->fill();

    return true;
}

bool Display::on_timeout()
{
    // force our program to redraw the entire Display.
    if (!running)
        return false;

    engine.updateCoordinates();

    auto win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(),
                         get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
    return true;
}
