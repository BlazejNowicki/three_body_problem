#ifndef GTKMM_EXAMPLE_CLOCK_H
#define GTKMM_EXAMPLE_CLOCK_H

#include <gtkmm/drawingarea.h>
#include "engine.h"

class Display : public Gtk::DrawingArea
{
public:
    Display();
    virtual ~Display();
    void toggle_loop();

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;

    bool on_timeout();

    Engine engine;

    double m_radius;
    double m_line_width;
    bool running;
};


#endif // GTKMM_EXAMPLE_CLOCK_H
