#ifndef GTKMM_EXAMPLE_CLOCK_H
#define GTKMM_EXAMPLE_CLOCK_H

#include <gtkmm/drawingarea.h>
#include "engine.h"

class Display : public Gtk::DrawingArea
{
public:
    Display();
    virtual ~Display();

    void start_loop();
    void setEngine(std::shared_ptr<Engine> engine);

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;

    bool on_timeout();

    std::shared_ptr<Engine> engine;
    

    bool running;
};


#endif // GTKMM_EXAMPLE_CLOCK_H
