#include "Plugin.hpp"

struct OutSel8 : Module
{
	enum ParamIds
	{
		SEL_PARAM,
		NUM_PARAMS
	};
	enum InputIds
	{
		IN_INPUT,

		INCV_INPUT,
		NUM_INPUTS
	};
	enum OutputIds
	{
		OUT1_OUTPUT,
		OUT2_OUTPUT,
		OUT3_OUTPUT,
		OUT4_OUTPUT,
		OUT5_OUTPUT,
		OUT6_OUTPUT,
		OUT7_OUTPUT,
		OUT8_OUTPUT,
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

	OutSel8() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS,NUM_LIGHTS);
		configParam(OutSel8::SEL_PARAM, 0, 7.0, 0.0, "");
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
				outputs[OUT1_OUTPUT].setVoltage(inputs[IN_INPUT].getVoltage());
				outputs[OUT2_OUTPUT].setVoltage(0);
				outputs[OUT3_OUTPUT].setVoltage(0);
				outputs[OUT4_OUTPUT].setVoltage(0);
				outputs[OUT5_OUTPUT].setVoltage(0);
				outputs[OUT6_OUTPUT].setVoltage(0);
				outputs[OUT7_OUTPUT].setVoltage(0);
				outputs[OUT8_OUTPUT].setVoltage(0);
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
				outputs[OUT2_OUTPUT].setVoltage(inputs[IN_INPUT].getVoltage());
				outputs[OUT1_OUTPUT].setVoltage(0);
				outputs[OUT3_OUTPUT].setVoltage(0);
				outputs[OUT4_OUTPUT].setVoltage(0);
				outputs[OUT5_OUTPUT].setVoltage(0);
				outputs[OUT6_OUTPUT].setVoltage(0);
				outputs[OUT7_OUTPUT].setVoltage(0);
				outputs[OUT8_OUTPUT].setVoltage(0);
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
				outputs[OUT3_OUTPUT].setVoltage(inputs[IN_INPUT].getVoltage());
				outputs[OUT2_OUTPUT].setVoltage(0);
				outputs[OUT1_OUTPUT].setVoltage(0);
				outputs[OUT4_OUTPUT].setVoltage(0);
				outputs[OUT5_OUTPUT].setVoltage(0);
				outputs[OUT6_OUTPUT].setVoltage(0);
				outputs[OUT7_OUTPUT].setVoltage(0);
				outputs[OUT8_OUTPUT].setVoltage(0);
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
				outputs[OUT4_OUTPUT].setVoltage(inputs[IN_INPUT].getVoltage());
				outputs[OUT2_OUTPUT].setVoltage(0);
				outputs[OUT3_OUTPUT].setVoltage(0);
				outputs[OUT1_OUTPUT].setVoltage(0);
				outputs[OUT5_OUTPUT].setVoltage(0);
				outputs[OUT6_OUTPUT].setVoltage(0);
				outputs[OUT7_OUTPUT].setVoltage(0);
				outputs[OUT8_OUTPUT].setVoltage(0);
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
				outputs[OUT5_OUTPUT].setVoltage(inputs[IN_INPUT].getVoltage());
				outputs[OUT2_OUTPUT].setVoltage(0);
				outputs[OUT3_OUTPUT].setVoltage(0);
				outputs[OUT4_OUTPUT].setVoltage(0);
				outputs[OUT1_OUTPUT].setVoltage(0);
				outputs[OUT6_OUTPUT].setVoltage(0);
				outputs[OUT7_OUTPUT].setVoltage(0);
				outputs[OUT8_OUTPUT].setVoltage(0);
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
				outputs[OUT6_OUTPUT].setVoltage(inputs[IN_INPUT].getVoltage());
				outputs[OUT2_OUTPUT].setVoltage(0);
				outputs[OUT3_OUTPUT].setVoltage(0);
				outputs[OUT4_OUTPUT].setVoltage(0);
				outputs[OUT5_OUTPUT].setVoltage(0);
				outputs[OUT1_OUTPUT].setVoltage(0);
				outputs[OUT7_OUTPUT].setVoltage(0);
				outputs[OUT8_OUTPUT].setVoltage(0);
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
				outputs[OUT7_OUTPUT].setVoltage(inputs[IN_INPUT].getVoltage());
				outputs[OUT2_OUTPUT].setVoltage(0);
				outputs[OUT3_OUTPUT].setVoltage(0);
				outputs[OUT4_OUTPUT].setVoltage(0);
				outputs[OUT5_OUTPUT].setVoltage(0);
				outputs[OUT6_OUTPUT].setVoltage(0);
				outputs[OUT1_OUTPUT].setVoltage(0);
				outputs[OUT8_OUTPUT].setVoltage(0);
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
				outputs[OUT8_OUTPUT].setVoltage(inputs[IN_INPUT].getVoltage());
				outputs[OUT2_OUTPUT].setVoltage(0);
				outputs[OUT3_OUTPUT].setVoltage(0);
				outputs[OUT4_OUTPUT].setVoltage(0);
				outputs[OUT5_OUTPUT].setVoltage(0);
				outputs[OUT6_OUTPUT].setVoltage(0);
				outputs[OUT7_OUTPUT].setVoltage(0);
				outputs[OUT1_OUTPUT].setVoltage(0);
				break;
		}
	}
};

struct OutSel8Widget : ModuleWidget {
	OutSel8Widget(OutSel8* module) {
	setModule(module);
	setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/OutSel8.svg")));

	addChild(createWidget<ScrewBlack>(Vec(15, 0)));
	addChild(createWidget<ScrewBlack>(Vec(15, 365)));

	addChild(createLight<SmallLight<RedLight>>(Vec(43, 36), module, OutSel8::OUT1_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 64), module, OutSel8::OUT2_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 92), module, OutSel8::OUT3_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 120), module, OutSel8::OUT4_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 148), module, OutSel8::OUT5_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 176), module, OutSel8::OUT6_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 204), module, OutSel8::OUT7_LIGHT));
	addChild(createLight<SmallLight<RedLight>>(Vec(43, 232), module, OutSel8::OUT8_LIGHT));

	addOutput(createOutput<PJ301MPort>(Vec(18, 36), module, OutSel8::OUT1_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(18, 64), module, OutSel8::OUT2_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(18, 92), module, OutSel8::OUT3_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(18, 120), module, OutSel8::OUT4_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(18, 148), module, OutSel8::OUT5_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(18, 176), module, OutSel8::OUT6_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(18, 204), module, OutSel8::OUT7_OUTPUT));
	addOutput(createOutput<PJ301MPort>(Vec(18, 232), module, OutSel8::OUT8_OUTPUT));

	addParam(createParam<RoundBlackSnapKnob>(Vec(16, 261), module, OutSel8::SEL_PARAM));

	addInput(createInput<PJ301MPort>(Vec(18, 296), module, OutSel8::INCV_INPUT));
	addInput(createInput<PJ301MPort>(Vec(18, 323), module, OutSel8::IN_INPUT));



	}
};


Model* modelOutSel8 = createModel<OutSel8, OutSel8Widget>("OutSel8");
