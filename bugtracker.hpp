#ifdef debug
#define movement_call std::cout << "movement called" << std::endl;
#define mouse_event_getinfo_call std::cout << "mouse event get info called" << std::endl;
#define render_call std::cout << "renderer called" << std::endl;
#endif

#ifdef release
#endif