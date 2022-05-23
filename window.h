#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
    ExampleWindow();
    virtual ~ExampleWindow();

protected:
    Gtk::Box m_VBox;
    Gtk::Label m_Label;
    Gtk::Label m_Label2;
    //   //Child widgets:
    //   Gtk::Box m_HBox;
    //   Gtk::Box m_VBox, m_VBox2;
    //   Gtk::Frame m_Frame_Normal, m_Frame_Multi, m_Frame_Left, m_Frame_Right,
    //     m_Frame_LineWrapped, m_Frame_FilledWrapped, m_Frame_Underlined;
    //   Gtk::Label m_Label_Normal, m_Label_Multi, m_Label_Left, m_Label_Right,
    //     m_Label_LineWrapped, m_Label_FilledWrapped, m_Label_Underlined;
};

#endif // GTKMM_EXAMPLEWINDOW_H