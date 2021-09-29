#include "Arduino.h"
#include "MorseBinNET2EM.h"
MorseBinNET2EM::MorseBinNET2EM(int pinTransmit){
	_pinTransmit = pinTransmit;
	_address = "00000000";
	pinMode(_pinTransmit,INPUT);
	timeMiddle = ((time0+time1)/2);
	timeForStart = ((time0+time1)-(time1/2));
}
MorseBinNET2EM::MorseBinNET2EM(int pinTransmit, int speed){
	_pinTransmit = pinTransmit;
	_address = "00000000";
	pinMode(_pinTransmit,INPUT);
	time1 = speed;
	time0 = time1*3;
	timeMiddle = ((time0+time1)/2);
	timeForStart = ((time0+time1)-(time1/2));
}
void MorseBinNET2EM::send(String address, String data1, String data2, String data3, String data4, String data5, String data6, String data7, String data8) {
	sendByte(address, _pinTransmit);
	sendByte(_address, _pinTransmit);
	sendByte("00000000",_pinTransmit);
	sendByte(data1, _pinTransmit);
	sendByte(data2, _pinTransmit);
	sendByte(data3, _pinTransmit);
	sendByte(data4, _pinTransmit);
	sendByte(data5, _pinTransmit);
	sendByte(data6, _pinTransmit);
	sendByte(data7, _pinTransmit);
	sendByte(data8, _pinTransmit);
}
void MorseBinNET2EM::send(String address,String busID, String data1, String data2, String data3, String data4, String data5, String data6, String data7, String data8){
	sendByte(address, _pinTransmit);
	sendByte(_address, _pinTransmit);
	sendByte(busID,_pinTransmit);
	sendByte(data1, _pinTransmit);
	sendByte(data2, _pinTransmit);
	sendByte(data3, _pinTransmit);
	sendByte(data4, _pinTransmit);
	sendByte(data5, _pinTransmit);
	sendByte(data6, _pinTransmit);
	sendByte(data7, _pinTransmit);
	sendByte(data8, _pinTransmit);
			}
void MorseBinNET2EM::receive(){
	String receiverAddress = receiveByte(_pinTransmit);
	if((receiverAddress == "errTimeout")){
		lastMessage[0] = "errTimeout";
		return;
	} else {
		if(receiverAddress == "errGrabledMessage"){
			lastMessage[0] = "errGrabledMessage";
			return;
		}
	}
	//Serial.println(lastMessage[0]);
	String senderAddress = receiveByte(_pinTransmit);
	if(senderAddress == "errTimeout"){
		lastMessage[0] = "errTimeout";
		return;
	} else {
		if(senderAddress == "errGrabledMessage"){
			lastMessage[0] = "errGrabledMessage";
			return;
		}
	}
	//Serial.println(lastMessage[0]);
	String senderBusID = receiveByte(_pinTransmit);
	if(senderBusID == "errTimeout"){
		lastMessage[0] = "errTimeout";
		return;
	} else {
		if(senderBusID == "errGrabledMessage"){
			lastMessage[0] = "errGrabledMessage";
			return;
		}
	}
	//Serial.println(lastMessage[0]);
	String data1 = receiveByte(_pinTransmit);
	if(data1 == "errTimeout"){
		lastMessage[0] = "errTimeout";
		return;
	} else {
		if(data1 == "errGrabledMessage"){
			lastMessage[0] = "errGrabledMessage";
			return;
		}
	}
	//Serial.println(lastMessage[0]);
	String data2 = receiveByte(_pinTransmit);
	if(data2 == "errTimeout"){
		lastMessage[0] = "errTimeout";
		return;
	} else {
		if(data2 == "errGrabledMessage"){
			lastMessage[0] = "errGrabledMessage";
			return;
		}
	}
	//Serial.println(lastMessage[0]);
	String data3 = receiveByte(_pinTransmit);
	if(data3 == "errTimeout"){
		lastMessage[0] = "errTimeout";
		return;
	} else {
		if(data3 == "errGrabledMessage"){
			lastMessage[0] = "errGrabledMessage";
			return;
		}
	}
	//Serial.println(lastMessage[0]);
	String data4 = receiveByte(_pinTransmit);
	if(data4 == "errTimeout"){
		lastMessage[0] = "errTimeout";
		return;
	} else {
		if(data4 == "errGrabledMessage"){
			lastMessage[0] = "errGrabledMessage";
			return;
		}
	}
	//Serial.println(lastMessage[0]);
	String data5 = receiveByte(_pinTransmit);
	if(data5 == "errTimeout"){
		lastMessage[0] = "errTimeout";
		return;
	} else {
		if(data5 == "errGrabledMessage"){
			lastMessage[0] = "errGrabledMessage";
			return;
		}
	}
	//Serial.println(lastMessage[0]);
	String data6 = receiveByte(_pinTransmit);
	if(data6 == "errTimeout"){
		lastMessage[0] = "errTimeout";
		return;
	} else {
		if(data6 == "errGrabledMessage"){
			lastMessage[0] = "errGrabledMessage";
			return;
		}
	}
	//Serial.println(lastMessage[0]);
	String data7 = receiveByte(_pinTransmit);
	if(data7 == "errTimeout"){
		lastMessage[0] = "errTimeout";
		return;
	} else {
		if(data7 == "errGrabledMessage"){
			lastMessage[0] = "errGrabledMessage";
			return;
		}
	}
	//Serial.println(lastMessage[0]);
	String data8 = receiveByte(_pinTransmit);
	if(data8 == "errTimeout"){
		lastMessage[0] = "errTimeout";
		return;
	} else {
		if(data8 == "errGrabledMessage"){
			lastMessage[0] = "errGrabledMessage";
			return;
		}
	}
	//Serial.println(lastMessage[0]);
	if(_address != receiverAddress){
		lastMessage[0] = "errWrongAddress";
		//Serial.println(_address + ":" + receiverAddress);
		return;
	}
	if(senderBusID == "00000000"){
		lastMessage[2] = "local";
	} else{
		lastMessage[2] = senderBusID;
	}
	lastMessage[1] = senderAddress;
	lastMessage[3] = data1;
	lastMessage[4] = data2;
	lastMessage[5] = data3;
	lastMessage[6] = data4;
	lastMessage[7] = data5;
	lastMessage[8] = data6;
	lastMessage[9] = data7;
	lastMessage[10] = data8;
	lastMessage[0] = "errSuccess";
}
String MorseBinNET2EM::placeRequest(String address, String data1, String data2) {
	return "errNotImplemented";
}
void MorseBinNET2EM::Send0(int sendpin) {
 	digitalWrite(sendpin,HIGH);
 	delayMicroseconds(time0);
 	digitalWrite(sendpin,LOW);
 	delayMicroseconds(time1);
  }
void MorseBinNET2EM::Send1(int sendpin) {
 	digitalWrite(sendpin,HIGH);
 	delayMicroseconds(time1);
 	digitalWrite(sendpin,LOW);
 	delayMicroseconds(time1);
  }
void MorseBinNET2EM::sendByte(String input,int sendpin){
	while(digitalRead(sendpin) == HIGH){
		delayMicroseconds(time1+5);
		//Serial.println("StuckInTraffic");
	}
	pinMode(sendpin,OUTPUT);
    	//Serial.println("gotit");
	digitalWrite(sendpin,HIGH);
	delayMicroseconds(time0+time1);
	digitalWrite(sendpin,LOW);
	delayMicroseconds(time1);
   	 for (int i=0;i<8;i++){
    		if (input.charAt(i)=='1'){
     		 Send1(sendpin);
      		//Serial.println("gotit1");
      	}
      if (input.charAt(i)=='0'){
      		Send0(sendpin);
      		//Serial.println("gotit0");
      }
    }
	pinMode(sendpin,INPUT);
	delayMicroseconds(16);
  }
  String MorseBinNET2EM::receiveByte(int respin){
	String buf;
  	unsigned long waitTimer = 0;
	int timeouttimer = 0;
	while(digitalRead(respin)==LOW){
		timeouttimer+=8;
    	delayMicroseconds(8);
    	if(timeouttimer>=30000){
      		return "errTimeout";
	  	}
	}
	unsigned long microTimer = micros();
	int highTimeoutTimer = 0;
	while(digitalRead(respin) == HIGH){
		if(highTimeoutTimer > 30000){
			return "errTimeout";
		}
		highTimeoutTimer += 8;
		delayMicroseconds(8);
	}
	waitTimer = micros() - microTimer;
 	if(waitTimer>timeForStart){
	} else {
		//Serial.println(waitTimer);
		//Serial.print("StartTime should be: ");
		//Serial.println(timeForStart);
		return "errGrabledMessage";
	}
 	for (int i=0;i<8;i++){
		int timer = 0;
		while (digitalRead(respin)==LOW){
			timer++;
			delayMicroseconds(8);
			if(timer>=10000){
				timer = 0;
				return "errTimeout";
			}
		}
		unsigned long microStart = micros();
		while(digitalRead(respin)==HIGH) {
			if(micros() - microStart > 10000){return "errTimeout";}
		}
		unsigned long t = micros() - microStart;
		if (t > timeMiddle && t < timeForStart) {
			buf += "0";
		}
		else {
			if(t < timeMiddle && t < timeForStart){
				buf += "1";
				} else {
					buf += "n";
				}      	
			}   
    }
    return buf;
  }
void MorseBinNET2EM::setAddress(String addressToSet){
	_address = addressToSet;
}
void MorseBinNET2EM::ackknowledge(){
	send(lastMessage[1], "00000000", "11111111", "11111111", "11111111", "11111111", "11111111", "11111111", "11111111");
}
void MorseBinNET2EM::getAddress(){
	Serial.println("Starting to get Address");
	setAddress("00000000");
	boolean secondRun = false;
	getAddressMarker:
	boolean gotResponse = false;
	unsigned long timeout = millis();
	send(_gateWay, "00000001", "11111111", "11111111", "11111111", "11111111", "11111111", "11111111", "11111111");
	while(gotResponse == false) {
		receive();
		if(lastMessage[0] == "errSuccess" && lastMessage[1] == _gateWay){
			Serial.println("GotAddress!");
			gotResponse = true;
			break;
		} // else {Serial.println("GotNoNewAddressForNow!");}
		if(millis() - timeout > 10000){break;}
	}
	if(gotResponse == false && secondRun == true){
		Serial.println("GotNoNewAddress");
		while(1);
	} else if(gotResponse == false && secondRun == false){
		goto getAddressMarker;
	}
	setAddress(lastMessage[3]);
	Serial.println(lastMessage[3]);
	timeStamp = millis();
	Serial.println("New Address: " + _address);
}
void MorseBinNET2EM::update(){
	if((millis() - timeStamp < 60000) && millis() - timeStamp > 50000){
		Serial.println("Updated Address!");
		Serial.println("CurrentAddress: " + _address);
		boolean gotResponse = false;
		unsigned long timeout = millis();
		send(_gateWay, "00000010", "11111111", "11111111", "11111111", "11111111", "11111111", "11111111", "11111111");
		while(gotResponse == false){
			receive();
			if(millis() - timeout > 10000){
				Serial.println("TimeOut!");
				update();
				break;
			}
			if(lastMessage[0] == "errSuccess" && lastMessage[1] == _gateWay && lastMessage[3] == "00000000"){
				timeStamp = millis();
				break;
			}
		}
	} else if((millis() - timeStamp > 60000)){
		getAddress();
	}
}
void MorseBinNET2EM::begin(){
	getAddress();
}