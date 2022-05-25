#ifndef CONFIG_BOX
#define CONFIG_BOX

#include <gtkmm.h>
#include "paramsinput.h"

class ConfigBox : public Gtk::Box
{
public:
    ConfigBox();
    virtual ~ConfigBox();

protected:
    ParamsInput first_obj;
    ParamsInput second_obj;
    ParamsInput third_obj;
};

#endif // CONFIG_BOX