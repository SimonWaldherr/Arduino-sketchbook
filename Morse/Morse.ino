/* 
  Morse your debug informations via one digital IO port.
  This is a easy to understand Morsecode implementation.

  Author: Simon Waldherr
  License: MIT
*/

int morseout = 2;
int morsespeed = 25;

void setup()
  {
    Serial.begin(9600);
    pinMode(morseout, OUTPUT); 
  }

void loop()
  {
    morse("LOREM IPSUM DOLAR SIT AMET.");
    delay(500);
  }

void morse(char *str)
  {
    while (*str)
      {
        morse_char(*str++);
      }
  }

void morse_send(char *str)
  {
    while (*str)
      {
        if(*str++ == '-')
          {
            digitalWrite(morseout, HIGH);
            delay(3*morsespeed);
            digitalWrite(morseout, LOW);
            delay(morsespeed);
          }
        else
          {
            digitalWrite(morseout, HIGH);
            delay(morsespeed);
            digitalWrite(morseout, LOW);
            delay(morsespeed);
          }
        delay(3*morsespeed);
      }
  }

void morse_char(char c)
  {
    switch(c)
      {
        case 'A':
        morse_send(".-");
        break;
        case 'B':
        morse_send("-...");
        break;
        case 'C':
        morse_send("-.-.");
        break;
        case 'D':
        morse_send("-..");
        break;
        case 'E':
        morse_send(".");
        break;
        case 'F':
        morse_send("..-.");
        break;
        case 'G':
        morse_send("--.");
        break;
        case 'H':
        morse_send("....");
        break;
        case 'I':
        morse_send("..");
        break;
        case 'J':
        morse_send(".---");
        break;
        case 'K':
        morse_send("-.-");
        break;
        case 'L':
        morse_send(".-..");
        break;
        case 'M':
        morse_send("--");
        break;
        case 'N':
        morse_send("-.");
        break;
        case 'O':
        morse_send("---");
        break;
        case 'P':
        morse_send(".--.");
        break;
        case 'Q':
        morse_send("--.-");
        break;
        case 'R':
        morse_send(".-.");
        break;
        case 'S':
        morse_send("...");
        break;
        case 'T':
        morse_send("-");
        break;
        case 'U':
        morse_send("..-");
        break;
        case 'V':
        morse_send("...-");
        break;
        case 'W':
        morse_send(".--");
        break;
        case 'X':
        morse_send("-..-");
        break;
        case 'Y':
        morse_send("-.--");
        break;
        case 'Z':
        morse_send("--..");
        break;
        case '0':
        morse_send("-----");
        break;
        case '1':
        morse_send(".----");
        break;
        case '2':
        morse_send("..---");
        break;
        case '3':
        morse_send("...--");
        break;
        case '4':
        morse_send("....-");
        break;
        case '5':
        morse_send(".....");
        break;
        case '6':
        morse_send("-....");
        break;
        case '7':
        morse_send("--...");
        break;
        case '8':
        morse_send("---..");
        break;
        case '9':
        morse_send("----.");
        break;
        case '.':
        morse_send(".-.-.-");
        break;
        case ',':
        morse_send("--..--");
        break;
        case ':':
        morse_send("---...");
        break;
        case ';':
        morse_send("-.-.-.");
        break;
        default:
        delay(7*morsespeed);
      }
    delay(3*morsespeed);
  }