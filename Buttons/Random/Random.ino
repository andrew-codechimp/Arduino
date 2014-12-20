const byte NUMBER_OF_PRINCIPLES = 20;
char* principles[NUMBER_OF_PRINCIPLES] = {"Common use solutions","Flexible Architecture","Reuse before Buy before Build","Solutions are business driven","Single Sign-On (SSO)","Solid Scalable Solutions","Open standards used in application development","Migration is always possible","Reliable solution deployment and configuration","Designed for testing","Single Source of Truth (SSOT)","Timely data delivery","Atomic level data storage","Data Security","Data has an owner","Data is a valuable asset","Data Remediation","Data Lineage","Cost effective infrastructure","Standard Technology"};

const byte NUMBER_OF_RESPONSES = 3;
char* responses[NUMBER_OF_RESPONSES] = {"Indeed","OK","Sure"};


void setup(){
	Serial.begin(9600);
	randomSeed(analogRead(0));
	pinMode(0, INPUT_PULLUP);
	pinMode(1, INPUT_PULLUP);
	delay(5000);
}

void loop() {
	if (digitalRead(0) == LOW)  // Black
	{
		Keyboard.println(responses[random(0, NUMBER_OF_RESPONSES)]);
		delay(500);
	}

  	if (digitalRead(1) == LOW)  // Red
	{
		Keyboard.println(principles[random(0, NUMBER_OF_PRINCIPLES)]);
		delay(500);
	}
//        if (digitalRead(1) == LOW)
//	{
//		Keyboard.press(MODIFIERKEY_GUI);
//		Keyboard.set_key1(KEY_L);
//                Keyboard.send_now();
//		delay(500);
//	}
}
