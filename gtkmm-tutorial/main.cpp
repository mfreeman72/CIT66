#include <gtkmm.h>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  Gtk::Window window;
  window.set_default_size(200, 200);

  Gtk::Box m_box;
  Gtk::Frame m_frame;
  Gtk::Button m_Button1;
  Gtk::Button m_Button2;

  m_frame.add(m_box);

  m_box.pack_start(m_Button1);
  m_box.pack_start(m_Button2);

  return app->run(window);
}
