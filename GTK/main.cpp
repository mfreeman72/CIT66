#include <gtkmm.h>

int main(int argc, char **argv)
{
    auto app = Gtk::Application::create(argc,argv, "com.solarianprogrammer");

    Gtk::Window win;
    win.set_default_size(800,600);
    win.set_title("Gtkmm 3 demo");

    return app->run(win);
}
