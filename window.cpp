#include "window.h"
#include <iostream>

ExampleWindow::ExampleWindow()
:
  m_VBox(Gtk::ORIENTATION_VERTICAL, 5),
  m_Label("Normal label"),
  m_Label2("Another normal label")
{
  set_title("Labels");
  set_border_width(5);

  add(m_VBox);

  m_VBox.pack_start(m_Label, Gtk::PACK_SHRINK);
  m_VBox.pack_start(m_Label2, Gtk::PACK_SHRINK);

  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}