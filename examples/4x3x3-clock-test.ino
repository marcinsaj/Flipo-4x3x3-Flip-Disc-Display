#include <FlipDisc.h>

// Pin declaration for Arduino Nano Every and PSPS module
#define EN_PIN    PIN_PB2  // Arduino pin 10. Start & End SPI transfer data
#define CH_PIN    PIN_PB0  // Arduino pin 8. Charging PSPS module - turn ON/OFF
#define PL_PIN    PIN_PB1  // Arduino pin 9. Release the current pulse - turn ON/OFF

// LDBG LED
// Used to indicate potential hardware issues during the boot process
#define LDBG_PIN  PIN_PC2  // Arduino pin A2



void setup()
{
  Flip.Pin(EN_PIN, CH_PIN, PL_PIN);
 
  /* Initialization function of the displays */
  Flip.Init(D4X3X3);

  pinMode(LDBG_PIN, OUTPUT);
  digitalWrite(LDBG_PIN, LOW);


  delay(1000);
  digitalWrite(LDBG_PIN, HIGH);
  delay(1000);
      
  Flip.Delay(0);
}

void loop()
{
  Flip.Clear();
  delay(100);
  digitalWrite(LDBG_PIN, LOW);

  Flip.All();
  delay(100);
  digitalWrite(LDBG_PIN, HIGH);

  Flip.Clear();
  delay(100);
  digitalWrite(LDBG_PIN, LOW);

  Flip.All();
  delay(100);
  digitalWrite(LDBG_PIN, HIGH);

  for(int i = 0; i <= 9; i++)
  {
    Flip.Display_4x3x3(1, 1, i, NUMB);
    Flip.Display_4x3x3(1, 2, i, NUMB);
    Flip.Display_4x3x3(1, 3, i, DICE);
    Flip.Display_4x3x3(1, 4, i, DICE);
    delay(1000);   
  }
}
