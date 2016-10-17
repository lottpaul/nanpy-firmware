#ifndef METHOD_DESCRIPTOR
#define METHOD_DESCRIPTOR

#include <Arduino.h>
#include <WString.h>
#include <stdint.h>

namespace nanpy {
    class MethodDescriptor {

        private:
            char name[50];
            int objid;
            char classname[50];
            int n_args;
            char **stack;
            static char **stack_pool;
            static int stack_pool_size;

        public:
            MethodDescriptor();
            int getNArgs();
            char* getClass();
            int getObjectId();
		
            bool getBool(int n);
            int getInt(int n);
            uint8_t getUINT8(int n);
	    uint16_t getUINT16(int n);
	    uint32_t getUINT32(int n);
	    int8_t getINT8(int n);
	    int16_t getINT16(int n);
	    int32_t getINT32(int n);
		
            byte getByte(int n);
            float getFloat(int n);
            double getDouble(int n);
            char* getString(int n);
            char* getName();
		
			void returns(String& val);
            void returns(const char* val);
            void returns(int val);
            void returns(unsigned int val);
            void returns(float val);
            void returns(double val);
            void returns(long val);
            void returns(unsigned long val);
		
			void returns(String val[], int n);
			void returns(const char* val[], int n);
			void returns(int val[], int n);
			void returns(unsigned int val[], int n);
			void returns(float val[], int n);
			void returns(double val[], int n);
			void returns(long val[], int n);
			void returns(unsigned long val[], int n);


    };
}
#endif
