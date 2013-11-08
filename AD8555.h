#ifndef AD8555_h
#define AD8555_h

#include "Arduino.h" 

#define FUNC_CHANGE_SENSE_CURRENT 0b00
#define FUNC_SIMULATE	0b01
#define FUNC_PROGRAM	0b10
#define FUNC_READ		0b11

#define	PAR_SSG_CODE	0b00
#define PAR_FSG_CODE	0b01
#define PAR_OFS_CODE	0b10
#define PAR_OTHER_FUNC	0b11

#define DELAY_US_HIGH   65
#define DELAY_US_PAUSE  10

class AD8555
{
	public:
		AD8555(uint8_t outputPin);
		bool setSecondStageGain(uint8_t value);
		bool setFirstStageGain(uint8_t value);
		bool setOffset(uint8_t value);
		void simulate();
		void program();
		void sendData(uint8_t mode, uint8_t func, uint8_t value);
		
	private:
		void blowSSGFuse(uint8_t Value);
		void blowFSGFuse(uint8_t Value);
		void blowOFSFuse(uint8_t Value);
		void blowMSF();
		void sendStart();
		void sendMode(uint8_t value);
		void sendFunc(uint8_t value);
		void sendDummy();
		void sendValue(uint8_t value);
		void sendStop();
		void sendBit(bool value);
		void send0();
		void send1();
		int outPin;
		int SSG;
		int FSG;
		int OFS;
};

#endif
