#include "Plugin.hpp"

struct PanelD4 : Module
{
};

struct PanelD4Widget : ModuleWidget {
	PanelD4Widget(PanelD4* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/panel D4.svg")));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
	}
};


Model* modelPanelD4 = createModel<PanelD4, PanelD4Widget>("PanelD4");
