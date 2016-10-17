#include "cfg.h"

#if USE_FastLED

#include <Arduino.h>
#include <FastLED.h>
#include "FastLEDClass.h"
#include <stdlib.h>

#define DATA_PIN  2
#define CLOCK_PIN 3
#define COLOR_ORDER RGB

const char* nanpy::FastLEDClass::get_firmware_id()
{
    return "FastLED";
}

void nanpy::FastLEDClass::elaborate( MethodDescriptor* m ) {
    ObjectsManager<CRGB>::elaborate(m);

    if (strcmp(m->getName(),"new") == 0) {
		int nargs = m->getNArgs();
		int NUM_LEDS = m->getInt(1);
		v.insert(new CRGB[NUM_LEDS]);
                

		if (strcmp(m->getString(0), "APA104") == 0){
			FastLED.addLeds<APA104, DATA_PIN, RGB>(v[v.getLastIndex()], NUM_LEDS);
		}
		else if (strcmp(m->getString(0), "APA102") == 0){
			FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(v[v.getLastIndex()], NUM_LEDS);
		}
          m->returns(v.getLastIndex());
    }

	//Update all our controllers with the current led colors.
	if (strcmp(m->getName(), "show") == 0) {
		int nargs = m->getNArgs();
		if (nargs == 1){
			FastLED.show();
			m->returns(1);
		}
		else{
			FastLED.show(m->getInt(0));
			m->returns(1);
		}
    }

    //Set the given LED at given position to a given color
    if (strcmp(m->getName(), "set_item") == 0) {
          m->returns(v[m->getObjectId()][m->getInt(0)] = m->getInt(1));
    }

    if (strcmp(m->getName(), "set_color") == 0) {
       long color = atol(m->getString(1));
        v[m->getObjectId()][m->getInt(0)] = CRGB::Red;
    }
    
    
    if (strcmp(m->getName(), "set_rgb") == 0) {
        m->returns(v[m->getObjectId()][m->getInt(0)] = CRGB[(m->getInt(1), m->getInt(2), m->getInt(3)]));
    }
    
    if (strcmp(m->getName(), "setBrightness") == 0) {
          FastLED.setBrightness(m->getInt(0));
    }
    
    if (strcmp(m->getName(), "getBrightness") == 0) {
          FastLED.getBrightness();
    }

    if (strcmp(m->getName(), "showColor") == 0) {
          FastLED.showColor(CRGB(m->getUINT32(0)));
    }

    if (strcmp(m->getName(), "delay") == 0) {
        FastLED.delay(m->getInt(0));
    }

    if (strcmp(m->getName(), "setTemperature") == 0) {
        FastLED.setTemperature(CRGB(m->getInt(0)));
    }

    if (strcmp(m->getName(), "setCorrection") == 0) {
        FastLED.setCorrection(CRGB(m->getInt(0)));
    }

    if (strcmp(m->getName(), "setDither") == 0) {
        FastLED.setDither(m->getInt(0));
    }

    if (strcmp(m->getName(), "setMaxRefreshRate") == 0) {
        FastLED.setMaxRefreshRate(m->getInt(0),m->getBool(1));
    }

    
    if (strcmp(m->getName(), "countFPS") == 0) {
        FastLED.countFPS(m->getInt(0));
    }

    if (strcmp(m->getName(), "getFPS") == 0) {
        m->returns(FastLED.getFPS());
    }

    if (strcmp(m->getName(), "count") == 0) {
        m->returns(FastLED.count());
    }

	if (strcmp(m->getName(), "size") == 0) {
        m->returns(FastLED.size());
    }
	if (strcmp(m->getName(), "clear") == 0) {
        FastLED.clear(m->getBool(0));
    }
	if (strcmp(m->getName(), "clearData") == 0) {
        FastLED.clear();
    }
	if (strcmp(m->getName(), "fill_rainbow") == 0) {
        fill_rainbow(v[m->getObjectId()],m->getInt(0), m->getInt(1), m->getInt(2));
    }
	if (strcmp(m->getName(), "fill_solid") == 0) {
          long color = atol(m->getString(1));
        fill_solid(v[m->getObjectId()], m->getInt(0), CRGB(color));
    }
    
    if (strcmp(m->getName(), "fill_gradient_RGB") == 0) {
        fill_gradient(v[m->getObjectId()], m->getInt(0), m->getInt(1), m->getInt(2), m->getInt(3));
    }

    if (strcmp(m->getName(), "fadeLightBy") == 0) {
        fadeLightBy(v[m->getObjectId()], m->getInt(0), m->getInt(1));
    }

    if (strcmp(m->getName(), "fade_video") == 0) {
        fade_video(v[m->getObjectId()], m->getInt(0), m->getInt(1));
    }

    if (strcmp(m->getName(), "nscale8_video") == 0) {
        nscale8_video(v[m->getObjectId()], m->getInt(0), m->getInt(1));
    }

    if (strcmp(m->getName(), "fadeToBlackBy") == 0) {
        fadeToBlackBy(v[m->getObjectId()], m->getInt(0), m->getInt(1));
    }

    if (strcmp(m->getName(), "fade_raw") == 0) {
        fade_raw(v[m->getObjectId()], m->getInt(0), m->getInt(1));
    }

    if (strcmp(m->getName(), "nscale8") == 0) {
        nscale8(v[m->getObjectId()], m->getInt(0), m->getInt(1));
    }
    
    if (strcmp(m->getName(), "fadeUsingColor") == 0) {
        fadeUsingColor(v[m->getObjectId()],m->getInt(), CRGB(m->getInt()));
    }

    if (strcmp(m->getName(), "setMaxPowerInVoltsAndMilliamps") == 0) {
        FastLED.setMaxPowerInVoltsAndMilliamps(m->getInt(0), m->getInt(1));
    }

    if (strcmp(m->getName(), "setMaxPowerInMilliWatts") == 0) {
        m->returns(FastLED.setMaxPowerInMilliWatts(m->getInt(0)));
    }

    if (strcmp(m->getName(), "set_max_power_in_volts_and_milliamps") == 0) {
        m->returns(FastLED.set_max_power_in_volts_and_milliamps(m->getInt(0), m->getInt(1)));
    }

    if (strcmp(m->getName(), "set_max_power_in_milliwatts") == 0) {
        m->returns(FastLED.setMaxPowerInMilliWatts(m->getInt(0)));
    }

    if (strcmp(m->getName(), "set_max_power_indicator_LED") == 0) {
        m->returns(FastLED.set_max_power_indicator_LED(m->getInt(0)));
    }

    if (strcmp(m->getName(), "show_at_max_brightness_for_power") == 0) {
        m->returns(FastLED.show_at_max_brightness_for_power());
    }

    if (strcmp(m->getName(), "delay_at_max_brightness_for_power") == 0) {
        m->returns(FastLED.delay_at_max_brightness_for_power(m->getInt()));
    }

    if (strcmp(m->getName(), "calculate_unscaled_power_mW") == 0) {
        m->returns(FastLED.calculate_unscaled_power_mW(v[m->getObjectId()], m->getInt(0)));
    }
};

#endif
