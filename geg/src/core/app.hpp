#pragma once

#include "window/window.hpp"
#include "layer-stack.hpp"
#include <memory>


namespace Geg {



	class App {
	public:
		App();
		virtual ~App();
		static inline App& get(){return *i_Ins;}

		inline Window& getWindow() {return *window;}
		void onEvent (Event& e);
		void start();

		void pushLayer(Layer* l);
		void pushOverlay(Layer* l);

		bool closeCallback (const WindowCloseEvent& e);

	private:
		static App* i_Ins;
		bool running = true;
		LayerStack layerStack{};
		std::unique_ptr<Window> window;
	};

	//client must implement
	App* createApp();
}
