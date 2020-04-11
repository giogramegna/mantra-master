#include "Plugin.hpp"

struct StereoMult8 : Module
{
	enum ParamIds
	{
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
		OUT14_OUTPUT,
		OUT15_OUTPUT,
		OUT16_OUTPUT,
		OUT17_OUTPUT,
		OUT18_OUTPUT,

		OUT21_OUTPUT,
		OUT22_OUTPUT,
		OUT23_OUTPUT,
		OUT24_OUTPUT,
		OUT25_OUTPUT,
		OUT26_OUTPUT,
		OUT27_OUTPUT,
		OUT28_OUTPUT,
		NUM_OUTPUTS
	};

	StereoMult8() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS);
	}

	void process(const ProcessArgs& args) override {

			outputs[OUT11_OUTPUT].setVoltage(inputs[IN1_INPUT].getVoltage());
			outputs[OUT12_OUTPUT].setVoltage(inputs[IN1_INPUT].getVoltage());
			outputs[OUT13_OUTPUT].setVoltage(inputs[IN1_INPUT].getVoltage());
			outputs[OUT14_OUTPUT].setVoltage(inputs[IN1_INPUT].getVoltage());
			outputs[OUT15_OUTPUT].setVoltage(inputs[IN1_INPUT].getVoltage());
			outputs[OUT16_OUTPUT].setVoltage(inputs[IN1_INPUT].getVoltage());
			outputs[OUT17_OUTPUT].setVoltage(inputs[IN1_INPUT].getVoltage());
			outputs[OUT18_OUTPUT].setVoltage(inputs[IN1_INPUT].getVoltage());

			outputs[OUT21_OUTPUT].setVoltage(inputs[IN2_INPUT].getVoltage());
			outputs[OUT22_OUTPUT].setVoltage(inputs[IN2_INPUT].getVoltage());
			outputs[OUT23_OUTPUT].setVoltage(inputs[IN2_INPUT].getVoltage());
			outputs[OUT24_OUTPUT].setVoltage(inputs[IN2_INPUT].getVoltage());
			outputs[OUT25_OUTPUT].setVoltage(inputs[IN2_INPUT].getVoltage());
			outputs[OUT26_OUTPUT].setVoltage(inputs[IN2_INPUT].getVoltage());
			outputs[OUT27_OUTPUT].setVoltage(inputs[IN2_INPUT].getVoltage());
			outputs[OUT28_OUTPUT].setVoltage(inputs[IN2_INPUT].getVoltage());

	}
};

struct StereoMult8Widget : ModuleWidget {
	StereoMult8Widget(StereoMult8* module) {
	setModule(module);
	setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/StereoMult8.svg")));

	addChild(createWidget<ScrewBlack>(Vec(15, 0)));
	addChild(createWidget<ScrewBlack>(Vec(box.size.x - 30, 0)));
	addChild(createWidget<ScrewBlack>(Vec(15, 365)));
	addChild(createWidget<ScrewBlack>(Vec(box.size.x - 30, 365)));

	addInput(createInput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.8, 55), module, StereoMult8::IN1_INPUT));
	addInput(createInput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 55), module, StereoMult8::IN2_INPUT));

	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.85, 100), module, StereoMult8::OUT11_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.85, 131), module, StereoMult8::OUT12_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.85, 162), module, StereoMult8::OUT13_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.85, 193), module, StereoMult8::OUT14_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.85, 224), module, StereoMult8::OUT15_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.85, 255), module, StereoMult8::OUT16_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.85, 286), module, StereoMult8::OUT17_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*0.85, 317), module, StereoMult8::OUT18_OUTPUT));

	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 100), module, StereoMult8::OUT21_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 131), module, StereoMult8::OUT22_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 162), module, StereoMult8::OUT23_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 193), module, StereoMult8::OUT24_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 224), module, StereoMult8::OUT25_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 255), module, StereoMult8::OUT26_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 286), module, StereoMult8::OUT27_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH*3.5, 317), module, StereoMult8::OUT28_OUTPUT));

	}
};


Model* modelStereoMult8 = createModel<StereoMult8, StereoMult8Widget>("StereoMult8");
