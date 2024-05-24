#include <PS4Controller.h>
#include <Arduino.h>

// Right motor
#define ad 22
#define rd 23
// Left motor
#define ag 12
#define rg 14

//For esp32 PWM
#define freq 1000
#define ad_c 5
#define ag_c 4

#define rd_c 3
#define rg_c 6
#define resolution 8


#define speed 180
void forward(int sp) {
  ledcWrite(ad_c, sp); //ad
  ledcWrite(ag_c, sp); //ag
  ledcWrite(rd_c, 0);  //rd
  ledcWrite(rg_c, 0);  //rg

}

void backward(int sp) {
  ledcWrite(ad_c, 0); //ad
  ledcWrite(ag_c, 0); //ag
  ledcWrite(rd_c, sp);  //rd
  ledcWrite(rg_c, sp);  //rg

}
void right(int sp) {
  ledcWrite(ad_c, 0); //ad
  ledcWrite(ag_c, sp); //ag
  ledcWrite(rd_c, sp);  //rd
  ledcWrite(rg_c, 0);  //rg
}
void left(int sp) {
  ledcWrite(ad_c, sp); //ad
  ledcWrite(ag_c, 0); //ag
  ledcWrite(rd_c, 0);  //rd
  ledcWrite(rg_c, sp);  //rg
}

void forward_right(){
  ledcWrite(ad_c, 0);
  ledcWrite(ag_c, 200);
  ledcWrite(rd_c, 125);
  ledcWrite(rg_c, 0);
}
void forward_left(){
  ledcWrite(ad_c, 200);
  ledcWrite(ag_c, 0);
  ledcWrite(rd_c, 0);
  ledcWrite(rg_c, 125);   
}
void backward_right(){
  ledcWrite(ad_c, 125);
  ledcWrite(ag_c, 0);
  ledcWrite(rd_c, 0);
  ledcWrite(rg_c, 200); 
}
void backward_left(){
  ledcWrite(ad_c, 0);
  ledcWrite(ag_c, 125);
  ledcWrite(rd_c, 200);
  ledcWrite(rg_c, 0);  
}

void stop() {
  ledcWrite(ad_c, 0);
  ledcWrite(ag_c, 0);
  ledcWrite(rg_c, 0);
  ledcWrite(rd_c, 0);
}

void setup() {
  pinMode(ad, OUTPUT);
  pinMode(rd, OUTPUT);
  pinMode(ag, OUTPUT);
  pinMode(rg, OUTPUT);

  ledcSetup(rd_c, freq, resolution);
  ledcAttachPin(ad, rd_c);

  ledcSetup(ag_c, freq, resolution);
  ledcAttachPin(ag, ag_c);
  
  ledcSetup(ad_c, freq, resolution);
  ledcAttachPin(rd, ad_c);

  ledcSetup(rg_c, freq, resolution);
  ledcAttachPin(rg, rg_c);
  Serial.begin(115200);
  PS4.begin("1a:2b:3c:01:01:01");
  Serial.println("Ready.");
}

void loop() {
  // Below has all accessible outputs from the controller
  if (PS4.isConnected()) {
    if (PS4.Right()){
      right(sp);
    }
    if (PS4.Down()) Serial.println("Down Button");
    if (PS4.Up()) Serial.println("Up Button");
    if (PS4.Left()) Serial.println("Left Button");

    if (PS4.Square()) Serial.println("Square Button");
    if (PS4.Cross()) Serial.println("Cross Button");
    if (PS4.Circle()) Serial.println("Circle Button");
    if (PS4.Triangle()) Serial.println("Triangle Button");

    if (PS4.UpRight()) Serial.println("Up Right");
    if (PS4.DownRight()) Serial.println("Down Right");
    if (PS4.UpLeft()) Serial.println("Up Left");
    if (PS4.DownLeft()) Serial.println("Down Left");

    if (PS4.L1()) Serial.println("L1 Button");
    if (PS4.R1()) Serial.println("R1 Button");

    if (PS4.Share()) Serial.println("Share Button");
    if (PS4.Options()) Serial.println("Options Button");
    if (PS4.L3()) Serial.println("L3 Button");
    if (PS4.R3()) Serial.println("R3 Button");


    if (PS4.L2()) {
      Serial.printf("L2 button at %d\n", PS4.L2Value());
    }
    if (PS4.R2()) {
      Serial.printf("R2 button at %d\n", PS4.R2Value());
    }

    if (PS4.LStickX()) {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
    }
    if (PS4.LStickY()) {
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
    }
    if (PS4.RStickX()) {
      Serial.printf("Right Stick x at %d\n", PS4.RStickX());
    }
    if (PS4.RStickY()) {
      Serial.printf("Right Stick y at %d\n", PS4.RStickY());
    }
  }
}


//if (PS4.PSButton()) Serial.println("PS Button");
//if (PS4.Touchpad()) Serial.println("Touch Pad Button");
//if (PS4.Charging()) Serial.println("The controller is charging");
//if (PS4.Audio()) Serial.println("The controller has headphones attached");
//if (PS4.Mic()) Serial.println("The controller has a mic attached");
//Serial.printf("Battery Level : %d\n", PS4.Battery());
//Serial.println();
// This delay is to make the output more human readable
// Remove it when you're not trying to see the output
//delay(1000);