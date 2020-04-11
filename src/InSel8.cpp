#include "Plugin.hpp"

struct InSel8 : Module
{
	enum ParamIds
	{
		SEL_PARAM,
		NUM_PARAMS
	};
	enum InputIds
	{
		IN1_INPUT,
		IN2_INPUT,
		IN3_INPUT,
		IN4_INPUT,
		IN5_INPUT,
		IN6_INPUT,
		IN7_INPUT,
		IN8_INPUT,
		INCV_INPUT,
		NUM_INPUTS
	};
	enum OutputIds
	{
		OUT_OUTPUT,
		NUM_OUTPUTS
	};

	enum LightIds
	{
		OUT1_LIGHT,
		OUT2_LIGHT,
		OUT3_LIGHT,
		OUT4_LIGHT,
		OUT5_LIGHT,
		OUT6_LIGHT,
		OUT7_LIGHT,
		OUT8_LIGHT,
	NUM_LIGHTS
	};

	InSel8() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS,NUM_LIGHTS);
		configParam(InSel8::SEL_PARAM, 0, 7.0, 0.0, "");
	}

	void process(const ProcessArgs& args) override {
		unsigned int selection = params[SEL_PARAM].getValue();
		if(inputs[INCV_INPUT].isConnected()){
			double cv = inputs[INCV_INPUT].getVoltage();
					 if (cv >= 0 && cv < 1.25) 	  selection += 0;
			else if (cv >= 1.25 && cv < 2.5)	selection += 1;
			else if (cv >= 2.5  && cv < 3.75) selection += 2;
			else if (cv >= 3.75 && cv < 5)	  selection += 3;
			else if (cv >= 5    && cv < 6.25)	selection += 4;
			else if (cv >= 6.25 && cv < 7.5)	selection += 5;
			else if (cv >= 7.5  && cv < 8.75)	selection += 6;
			else if (cv >= 8.75)  					  selection += 7;
		}
		selection = clamp(selection,0,7);
		switch (selection) {
			case 0:
				lights[OUT1_LIGHT].setBrightness(10);
				lights[OUT2_LIGHT].setBrightness(0);
				lights[OUT3_LIGHT].setBrightness(0);
				lights[OUT4_LIGHT].setBrightness(0);
				lights[OUT5_LIGHT].setBrightness(0);
				lights[OUT6_LIGHT].setBrightness(0);
				lights[OUT7_LIGHT].setBrightness(0);
				lights[OUT8_LIGHT].setBrightness(0);
				outputs[OUT_OUTPUT].setVoltage(inputs[IN1_INPUT].getVoltage());
				break;
			case 1:
				lights[OUT1_LIGHT].setBrightness(0);
				lights[OUT2_LIGHT].setBrightness(10);
				lights[OUT3_LIGHT].setBrightness(0);
				lights[OUT4_LIGHT].setBrightness(0);
				lights[OUT5_LIGHT].setBrightness(0);
				lights[OUT6_LIGHT].setBrightness(0);
				lights[OUT7_LIGHT].setBrightness(0);
				lights[OUT8_LIGHT].setBrightness(0);
				outputs[OUT_OUTPUT].setVoltage(inputs[IN2_INPUT].getVoltage());
				break;
			case 2:
				lights[OUT1_LIGHT].setBrightness(0);
				lights[OUT2_LIGHT].setBrightness(0);
				lights[OUT3_LIGHT].setBrightness(10);
				lights[OUT4_LIGHT].setBrightness(0);
				lights[OUT5_LIGHT].setBrightness(0);
				lights[OUT6_LIGHT].setBrightness(0);
				lights[OUT7_LIGHT].setBrightness(0);
				lights[OUT8_LIGHT].setBrightness(0);
				outputs[OUT_OUTPUT].setVoltage(inputs[IN3_INPUT].getVoltage());
				break;
			case 3:
				lights[OUT1_LIGHT].setBrightness(0);
				lights[OUT2_LIGHT].setBrightness(0);
				lights[OUT3_LIGHT].setBrightness(0);
				lights[OUT4_LIGHT].setBrightness(10);
				lights[OUT5_LIGHT].setBrightness(0);
				lights[OUT6_LIGHT].setBrightness(0);
				lights[OUT7_LIGHT].setBrightness(0);
				lights[OUT8_LIGHT].setBrightness(0);
				outputs[OUT_OUTPUT].setVoltage(inputs[IN4_INPUT].getVoltage());
				break;
			case 4:
				lights[OUT1_LIGHT].setBrightness(0);
				lights[OUT2_LIGHT].setBrightness(0);
				lights[OUT3_LIGHT].setBrightness(0);
				lights[OUT4_LIGHT].setBrightness(0);
				lights[OUT5_LIGHT].setBrightness(10);
				lights[OUT6_LIGHT].setBrightness(0);
				lights[OUT7_LIGHT].setBrightness(0);
				lights[OUT8_LIGHT].setBrightness(0);
				outputs[OUT_OUTPUT].setVoltage(inputs[IN5_INPUT].getVoltage());
				break;
			case 5:
				lights[OUT1_LIGHT].setBrightness(0);
				lights[OUT2_LIGHT].setBrightness(0);
				lights[OUT3_LIGHT].setBrightness(0);
				lights[OUT4_LIGHT].setBrightness(0);
				lights[OUT5_LIGHT].setBrightness(0);
				lights[OUT6_LIGHT].setBrightness(10);
				lights[OUT7_LIGHT].setBrightness(0);
				lights[OUT8_LIGHT].setBrightness(0);
				outputs[OUT_OUTPUT].setVoltage(inputs[IN6_INPUT].getVoltage());
				break;
			case 6:
				lights[OUT1_LIGHT].setBrightness(0);
				lights[OUT2_LIGHT].setBrightness(0);
				lights[OUT3_LIGHT].setBrightness(0);
				lights[OUT4_LIGHT].setBrightness(0);
				lights[OUT5_LIGHT].setBrightness(0);
				lights[OUT6_LIGHT].setBrightness(0);
				lights[OUT7_LIGHT].setBrightness(10);
				lights[OUT8_LIGHT].setBrightness(0);
				outputs[OUT_OUTPUT].setVoltage(inputs[IN7_INPUT].getVoltage());
				break;
			case 7:
				lights[OUT1_LIGHT].setBrightness(0);
				lights[OUT2_LIGHT].setBrightness(0);
				lights[OUT3_LIGHT].setBrightness(0);
				lights[OUT4_LIGHT].setBrightness(0);
				lights[OUT5_LIGHT].setBrightness(0);
				lights[OUT6_LIGHT].setBrightness(0);
				lights[OUT7_LIGHT].setBrightness(0);
				lights[OUT8_LIGHT].setBrightness(10);
				outputs[OUT_OUTPUT].setVoltage(inputs[IN8_INPUT].getVoltage());
				break;
		}
	}
};

struct InSel8Widget : ModuleWidget {
	InSel8Widget(InSel8* module) {
	setModule(module);
	setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/InSel8.svg")));

	addChild(createWidget<ScrewBlack>(Vec(15, 0)));
	addChild(createWidget<ScrewBlack>(Vec(15, 365)));

	addChild(createLight<SmallLight<RedLight>>(Vec(43, 36), module, InSel8::OUT1_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 64), module, InSel8::OUT2_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 92), module, InSel8::OUT3_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 120), module, InSel8::OUT4_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 148), module, InSel8::OUT5_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 176), module, InSel8::OUT6_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 204), module, InSel8::OUT7_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 232), module, InSel8::OUT8_LIGHT));

	addInput(createInput<PJ301MPort>(Vec(18, 36), module, InSel8::IN1_INPUT));
	addInput(createInput<PJ301MPort>(Vec(18, 64), module, InSel8::IN2_INPUT));
	addInput(createInput<PJ301MPort>(Vec(18, 92), module, InSel8::IN3_INPUT));
	addInput(createInput<PJ301MPort>(Vec(18, 120), module, InSel8::IN4_INPUT));
	addInput(createInput<PJ301MPort>(Vec(18, 148), module, InSel8::IN5_INPUT));
	addInput(createInput<PJ301MPort>(Vec(18, 176), module, InSel8::IN6_INPUT));
	addInput(createInput<PJ301MPort>(Vec(18, 204), module, InSel8::IN7_INPUT));
	addInput(createInput<PJ301MPort>(Vec(18, 232), module, InSel8::IN8_INPUT));

	addParam(createParam<RoundBlackSnapKnob>(Vec(16, 261), module, InSel8::SEL_PARAM));

	addInput(createInput<PJ301MPort>(Vec(18, 296), module, InSel8::INCV_INPUT));
	addOutput(createOutput<PJ301MPort>(Vec(18, 323), module, InSel8::OUT_OUTPUT));



	}
};


Model* modelInSel8 = createModel<InSel8, InSel8Widget>("InSel8");
