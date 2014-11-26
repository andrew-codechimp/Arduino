const byte NUMBER_OF_PRINCIPLES = 20;
char* principles[NUMBER_OF_PRINCIPLES] = {"Common use solutions","Flexible Architecture","Reuse before Buy before Build","Solutions are business driven","Single Sign-On (SSO)","Solid Scalable Solutions","Open standards used in application development","Migration is always possible","Reliable solution deployment and configuration","Designed for testing","Single Source of Truth (SSOT)","Timely data delivery","Atomic level data storage","Data Security","Data has an owner","Data is a valuable asset","Data Remediation","Data Lineage","Cost effective infrastructure","Standard Technology"};

void setup(){
	Serial.begin(9600);
	randomSeed(analogRead(0));
	pinMode(0, INPUT_PULLUP);
	delay(5000);
}

void loop() {
	if (digitalRead(0) == LOW)
	{
		Keyboard.print(principles[random(0, NUMBER_OF_PRINCIPLES)]);
		Keyboard.print(" ");
		delay(500);
	}
}
