#ifndef FASTLED_CLASS
#define FASTLED_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"
#include "FastLED.h"

class FastLED;

namespace nanpy {
    class FastLEDClass: public ObjectsManager<CRGB> {
        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();
    };
}

#endif
