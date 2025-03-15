#include <FlipDisc.h>

// Pin declaration for Arduino Nano Every and PSPS module
#define EN_PIN  10      // Start & End SPI transfer data
#define CH_PIN  A0      // Charging PSPS module - turn ON/OFF
#define PL_PIN  A1      // Release the current pulse - turn ON/OFF

void setup()
{
  Flip.Pin(EN_PIN, CH_PIN, PL_PIN);
 
  /* Initialization function of the displays */
  Flip.Init(D1X7, D4X3X3);
  
  delay(1000);
  Flip.Delay(100);
}

void loop()
{
  Flip.Clear();
  delay(1000);

  Flip.All();
  delay(1000);

  Flip.Clear();
  delay(1000);

  Flip.All();
  delay(1000);
}
