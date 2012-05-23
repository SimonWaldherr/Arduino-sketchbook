/* 
  Test Sketch for the MSGEQ7
  from Mixed Signal Integration

  the IOs in this Sketch are 
  compatible with the Shield
  from Sparkfun:

  http://www.sparkfun.com/products/10306

  Author: Simon Waldherr
  License: MIT
*/

int analogPin = 0;    // read from multiplexer using analog input 0
int strobePin = 4;    // strobe is attached to digital pin 4
int resetPin = 5;     // reset is attached to digital pin 5
int spectrumValue[7]; // array to store analog values


void setup()
  {

    // init IO
    delay(100);
    pinMode(analogPin, INPUT);
    pinMode(strobePin, OUTPUT);
    pinMode(resetPin, OUTPUT);
    analogReference(DEFAULT);
    digitalWrite(resetPin, LOW);
    digitalWrite(strobePin, HIGH);

    // init Serial
    delay(100);
    Serial.begin(115200);
    Serial.println("_______________________");
    Serial.println("MSGEQ7 Frequenz Analyse");
    Serial.println("-----------------------");
    Serial.println("   powerd by Arduino   ");
    Serial.println("-----------------------");

    // wait
    delay(5000);
  }

void loop()
  {
    digitalWrite(resetPin, HIGH);                          // reset band to 63 Hz
    digitalWrite(resetPin, LOW);

    for (int i = 0; i < 7; i++)                            // for loop to save values to array
      {
        digitalWrite(strobePin, LOW);
        delayMicroseconds(25);                             // to allow the output to settle
        spectrumValue[i] = doMath(analogRead(analogPin));  // read actual value to array
        digitalWrite(strobePin, HIGH);                     // select next band (160Hz, 400Hz, 1000Hz, 2500Hz, 6250Hz, 16kHz)
      }

    for (int i = 0; i < 7; i++)                            // for loop to print array to Serial
      {
        if (spectrumValue[i] < 10 )                        // ignore values lower than 100 (you also can use doMath())
          {
            Serial.print("\t");
            Serial.print("0");
          }
        else
          {
            Serial.print("\t");
            Serial.print(spectrumValue[i]);
          }
      }
    Serial.println();                                      // Serial new line
    //delay(500);                                          // this sketch prints really much data, you can slow down if you have to.
  }

int doMath(int analogvalue)                                // you can filter the analog data and do your own math
  {
    int result;
    result = (analogvalue-32)/10;
    return result;
  }