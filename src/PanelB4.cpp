#include "Plugin.hpp"

struct PanelB4 : Module
{
};

struct PanelB4Widget : ModuleWidget {
	PanelB4Widget(PanelB4* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/panel B4.svg")));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
	}
};


Model* modelPanelB4 = createModel<PanelB4, PanelB4Widget>("PanelB4");
