#include<PID_v1.h> 

double ch1, ch2, ch3, ch4, ch5, ch6; // store value
double Rp=2, Ri=5, Rd=1;
double Pp=2, Pi=5, Pd=1;
double Yp=2, Yi=5, Yd=1;
double Ap=2, Ai=5, Ad=1;
//double Kp=2, Ki=5, Kd=1;
//double Kp=2, Ki=5, Kd=1;
double SensRoll; 
double RollOut;
double SensPitch; 
double PitchOut;
double SensYaw; 
double YawOut;
double SensAlti; 
double AltiOut;
//double Setpoint, Input, Output;
//double Setpoint, Input, Output;
PID RollBal(&SensRoll, &RollOut, &ch1, Rp, Ri, Rd, DIRECT);
PID PitchBal(&SensPitch, &PitchOut, &ch2, Pp, Pi, Pd, DIRECT);
PID YawBal(&SensYaw, &YawOut, &ch3, Yp, Yi, Yd, DIRECT);
PID AltiBal(&SensAlti, &AltiOut, &ch4, Ap, Ai, Ad, DIRECT);
//PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
//PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{                
  Serial.begin(38400);
  pinMode(0, INPUT); // Set our input pins as such
  pinMode(1, INPUT); // Set our input pins as such
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT); 
  Serial.println("Starting serial");
  RollBal.SetMode(AUTOMATIC);
    PitchBal.SetMode(AUTOMATIC);
      YawBal.SetMode(AUTOMATIC);
        AltiBal.SetMode(AUTOMATIC);
  
}


void loop()                     
{
  ch1 = pulseIn(0, HIGH, 25000);
  ch2 = pulseIn(1, HIGH, 25000); // Read the pulse width of 
  ch3 = pulseIn(2, HIGH, 25000); // each channel
  ch4 = pulseIn(3, HIGH, 25000); // each channel
  ch5 = pulseIn(4, HIGH, 25000); // each channel
  ch6 = pulseIn(5, HIGH, 25000); // each channel  
  //PrintRCReadings(); 
   RollBal.Compute();
    PitchBal.Compute();
      YawBal.Compute();
        AltiBal.Compute();
        delay(10); 
        PrintPIDError(); 
}

void PrintRCReadings()
{
   Serial.print("ch1 ");
  Serial.print(ch1);
  Serial.print(" ch2 ");
  Serial.print(ch2);
  Serial.print(" ch3 ");
  Serial.print(ch3);
  Serial.print(" ch4 ");
  Serial.print(ch4);
  Serial.print(" ch5 ");
  Serial.print(ch5);
  Serial.print(" ch6 ");
  Serial.print(ch6);
  Serial.println("");
  delay(10);
} 

void PrintPIDError()
{
  Serial.print(" Roll Error "); 
 Serial.print(RollOut); 
   Serial.print(" Pitch Error "); 
 Serial.print(PitchOut);  
   Serial.print(" Yaw Error "); 
 Serial.print(YawOut);  
   Serial.print(" Altitude Error  "); 
 Serial.println(AltiOut); 
 delay(10);   
} 



