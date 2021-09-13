#ifndef GEG_WINDOW_HPP
#define GEG_WINDOW_HPP

#include <utility>
#include "GLFW/glfw3.h"

namespace Geg {

	struct WindowProps{
		unsigned int width, height;
		std::string name;

		WindowProps(unsigned int w = 640, unsigned int h = 480, std::string n = "Hello OpenGL") : width(w), height(h), name(n) {};
	};

	class Window {
	public:
		Window(WindowProps props);
		~Window();


		void close();
		void onUpdate();
		GLFWwindow* getRawWindow () const {return windowPtr;};
		unsigned int getWidth () const {return info.width;};
		unsigned int getHeight () const {return info.height;};
		void setVsync (bool state);
		bool getVSync() const {return info.VSync;}
		void setEventCallback (const std::function<void(Event&)>& cb) {info.eventCallback = cb;}

	private:
		GLFWwindow* windowPtr;

		struct WindowInfo {
			unsigned int width, height;
			bool VSync = true;
			std::string name;
			std::function<void(Event&)> eventCallback;
		};

		WindowInfo info;

	};
}

#endif //GEG_WINDOW_HPP
