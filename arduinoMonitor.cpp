#include <stdlib.h>
String textForSMS;

char buff[10];
const unsigned long sampleTime = 10000UL;
const unsigned long numSamples = 250UL;
const unsigned long sampleInterval = sampleTime/numSamples;
const int adc_zero = 510; 


  const int PIN1 = 1;
float rms1;

 const int PIN2 = 2; 
float rms2;

 const int PIN3 = 3; 
float rms3;

String RMS1; 
String RMS2; 
String RMS3; 
    
void setup()
{

 Serial.begin(9600);
 pinMode(PIN1, INPUT);
 pinMode(PIN2, INPUT);
 pinMode(PIN3, INPUT);

}


void loop()
{

COLORS(); 
textForSMS = textForSMS + RMS1 + ", " + RMS2 + ", " + RMS3 +", ";
Serial.println(textForSMS); 
delay(1000); 
textForSMS = ""; 

}

void COLORS()
{
 unsigned long CURRENT1 = 0;
  unsigned int count = 0;
  
 unsigned long CURRENT2 = 0;
 unsigned long CURRENT3 = 0;
   

  unsigned long prevMicros = micros() - sampleInterval ;
  while (count < numSamples)
  {
    if (micros() - prevMicros >= sampleInterval)
    {
      int adc_raw = analogRead(PIN1) - adc_zero; 
      currentAcc += (unsigned long)(adc_raw * adc_raw); 
  
      
            int adc_raw2 = analogRead(PIN2) - adc_zero; 
      currentAcc2 += (unsigned long)(adc_raw2 * adc_raw2); 
  
                  int adc_raw3 = analogRead(PIN3) - adc_zero; 
      currentAcc3 += (unsigned long)(adc_raw3 * adc_raw3);

      ++count;
      prevMicros += sampleInterval;

    }
  }
  
   RMS1 = sqrt((float)CURRENT1/(float)numSamples) * (75.7576 / 1024.0);
   delay(100);
 RMS2 = sqrt((float)CURRENT2/(float)numSamples) * (75.7576 / 1024.0);
  delay(100);
 RMS3 = sqrt((float)CURRENT3/(float)numSamples) * (75.7576 / 1024.0);
 delay(100);

   stringrms = dtostrf(RMS1, 1, 4, buff);
   stringrms2 = dtostrf(RMS2, 1, 4, buff);
   stringrms3 = dtostrf(RMS3, 1, 4, buff);
   Serial.println("\n");
 
  
 delay(1000);
Serial.println(CURRENT1);
 delay(1000);  
}
