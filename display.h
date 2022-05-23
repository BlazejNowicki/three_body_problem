#ifndef GTKMM_EXAMPLE_CLOCK_H
#define GTKMM_EXAMPLE_CLOCK_H

#include <gtkmm/drawingarea.h>

class Display : public Gtk::DrawingArea
{
public:
  Display();
  virtual ~Display();
  void toggle_loop();

protected:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

  bool on_timeout();

  double m_radius;
  double m_line_width;
  bool running;
};

#endif // GTKMM_EXAMPLE_CLOCK_H
