#include "Plugin.hpp"

struct DualAmp : Module
{
	enum ParamIds
	{
		MULT1_PARAM,
		MULT2_PARAM,
		NUM_PARAMS
	};
	enum InputIds
	{
		IN1_INPUT,
		IN2_INPUT,
		NUM_INPUTS
	};
	enum OutputIds
	{
		OUT11_OUTPUT,
		OUT12_OUTPUT,
		OUT13_OUTPUT,
		OUT21_OUTPUT,
		OUT22_OUTPUT,
		OUT23_OUTPUT,
		NUM_OUTPUTS
	};

	DualAmp() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS);
		configParam(MULT1_PARAM, 1, 3, 0.0, "Ch 1 Factor", "", 0, 1);
		configParam(MULT2_PARAM, 1, 3, 0.0, "Ch 2 Factor", "", 0, 1);
	}

	void process(const ProcessArgs& args) override {
		float out1 = params[MULT1_PARAM].getValue()*inputs[IN1_INPUT].getVoltage();
		outputs[OUT11_OUTPUT].setVoltage(out1);
		outputs[OUT12_OUTPUT].setVoltage(out1);
		outputs[OUT13_OUTPUT].setVoltage(out1);

		float out2 = params[MULT2_PARAM].getValue()*inputs[IN2_INPUT].getVoltage();
		outputs[OUT21_OUTPUT].setVoltage(out2);
		outputs[OUT22_OUTPUT].setVoltage(out2);
		outputs[OUT23_OUTPUT].setVoltage(out2);
	}
};

struct DualAmpWidget : ModuleWidget {
	DualAmpWidget(DualAmp* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/DualAmp.svg")));

		addChild(createWidget<ScrewBlack>(Vec(15, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 30, 0)));
		addChild(createWidget<ScrewBlack>(Vec(15, 365)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 30, 365)));

		addParam(createParam<RoundLargeBlackKnob>(Vec(RACK_GRID_WIDTH*1.8, 50), module, DualAmp::MULT1_PARAM));
		addInput(createInput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.8, 100), module, DualAmp::IN1_INPUT));
		addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.8, 145), module, DualAmp::OUT11_OUTPUT));
		addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 100), module, DualAmp::OUT12_OUTPUT));
		addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 145), module, DualAmp::OUT13_OUTPUT));

		addParam(createParam<RoundLargeBlackKnob>(Vec(RACK_GRID_WIDTH*1.8, 204), module, DualAmp::MULT2_PARAM));
		addInput(createInput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.8, 255), module, DualAmp::IN2_INPUT));
		addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.8, 300), module, DualAmp::OUT21_OUTPUT));
		addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 255), module, DualAmp::OUT22_OUTPUT));
		addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 300), module, DualAmp::OUT23_OUTPUT));
	}
};


Model* modelDualAmp = createModel<DualAmp, DualAmpWidget>("DualAmp");
