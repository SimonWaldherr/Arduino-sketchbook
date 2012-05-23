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

int AnalogIn = 0;    // read from multiplexer using analog input 0
int NextBand = 4;    // strobe (next band) is attached to digital pin 4
int ResetPin = 5;    // reset is attached to digital pin 5
int Spectrum[7];     // array to store analog values


void setup()
  {

    // init IO
    delay(250);
    pinMode(AnalogIn, INPUT);
    pinMode(NextBand, OUTPUT);
    pinMode(ResetPin, OUTPUT);
    analogReference(DEFAULT);
    digitalWrite(ResetPin, LOW);
    digitalWrite(NextBand, HIGH);

    // init Serial
    delay(250);
    Serial.begin(115200);
    Serial.println("|______________________________|");
    Serial.println("|            MSGEQ7            |");
    Serial.println("|------------------------------|");
    Serial.println("| Seven Band Graphic Equalizer |");
    Serial.println("|------------------------------|");
    Serial.println("|     on an Arduino Shield     |");
    Serial.println("|------------------------------|");
    Serial.println("|      with Serial output      |");
    Serial.println("|------------------------------|");
    // wait
    delay(5000);
  }

void loop()
  {
    digitalWrite(ResetPin, HIGH);                          // reset band to 63 Hz
    digitalWrite(ResetPin, LOW);

    for (int i = 0; i < 7; i++)                            // for loop to save values to array
      {
        digitalWrite(NextBand, LOW);
        delayMicroseconds(22);                             // to allow the output to settle
        Spectrum[i] = doMath(analogRead(AnalogIn));        // read actual value to array
        digitalWrite(NextBand, HIGH);                      // select next band (160Hz, 400Hz, 1000Hz, 2500Hz, 6250Hz, 16kHz)
        delayMicroseconds(3);
      }

    for (int i = 0; i < 7; i++)                            // for loop to print array to Serial
      {
        if (Spectrum[i] < 10 )                             // ignore values lower than 100 (you also can use doMath())
          {
            Serial.print("\t");
            Serial.print("0");
          }
        else
          {
            Serial.print("\t");
            Serial.print(Spectrum[i]);
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