#ifndef MorseBinNET2EM_h
#define MorseBinNET2EM_h
#include "Arduino.h"
	class MorseBinNET2EM {
		public:
			MorseBinNET2EM(int pinTransmit);
			MorseBinNET2EM(int pinTransmit, int speed);
			void send(String address, String data1, String data2, String data3, String data4, String data5, String data6, String data7, String data8);
			void send(String address,String busID, String data1, String data2, String data3, String data4, String data5, String data6, String data7, String data8);
			void receive();
			String placeRequest(String address, String data1, String data2);
			String lastMessage[11];
			void begin();
			void update();
		private:
			String _address;
			String _gateWay = "00000001";
			void sendByte(String input , int sendpin);
			String receiveByte(int resPin);
			void setAddress(String addressToSet);
			void ackknowledge();
			void getAddress();
			int _pinTransmit;
			int _pinReceive;
			void Send0(int sendpin);
			void Send1(int sendpin);
			int time1 = 48;
			int time0 = 144;
			int timeMiddle = 0;
			int timeForStart = 0;
			unsigned long timeStamp = 0;
	};
#endif
