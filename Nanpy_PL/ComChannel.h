#ifndef COM_CHANNEL
#define COM_CHANNEL

#include "cfg_all.h"
#include "consts.h"

#include <Arduino.h>

namespace nanpy {
    class ComChannel {
		

        public:
            static char read_buffer[MAX_READ_BUFFER_SIZE];
            static bool available();
            static void connect();
		
	    static void println(String& val);
	    static void println(const char* val);
            static void println(int val);
            static void println(unsigned int val);
            static void println(float val);
            static void println(double val);
            static void println(long val);
            static void println(unsigned long val);
		
	    static void println(String val[], int n);
	    static void println(const char* val[], int n);
	    static void println(int val[], int n);
	    static void println(unsigned int val[], int n);
	    static void println(float val[], int n);
	    static void println(double val[], int n);
	    static void println(long val[], int n);
	    static void println(unsigned long val[], int n);
		
            static void readLine(char* extbuff);
		
		
    };
}

#endif

