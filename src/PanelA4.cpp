#include "Plugin.hpp"

struct PanelA4 : Module
{
};

struct PanelA4Widget : ModuleWidget {
	PanelA4Widget(PanelA4* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/panel A4.svg")));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
	}
};


Model* modelPanelA4 = createModel<PanelA4, PanelA4Widget>("PanelA4");
