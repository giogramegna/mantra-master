#include "Plugin.hpp"

struct PanelC4 : Module
{
};

struct PanelC4Widget : ModuleWidget {
	PanelC4Widget(PanelC4* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/panel C4.svg")));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
	}
};


Model* modelPanelC4 = createModel<PanelC4, PanelC4Widget>("PanelC4");
