// have to do this in openocd/gdb
// set arm abi APCS

#include "stm32f05xxx.h"

void delay(int dly)
{
    while( dly--);
}
void initWatchdog()
{
    // The watchdog clock frequency is approximately 40kHz.
    // Using a prescaler value of 3 which corresponds to a prescaling factor of 32
    // and a reload value of 0xfff (4095) then the watchod will timeout every
    // 32*4095/40000 = 3.276 seconds.  The program must 'pet' the watchdog at 
    // least every 3 seconds or so.
    int X;
    IWDG_KR = 0x0000cccc;  // Enable the watchdog
    IWDG_KR = 0x00005555;  // unlock the watchdog timer registers
    IWDG_PR = 3;           // Set a prescaler value (factor of 32)
    IWDG_RLR = 0x00000fff; // Set the maximum reload value (4095)
    while(IWDG_SR !=0);    // Wait for updates to registers to complete
    IWDG_KR = 0x0000aaaa;  // Reset the WDT counter to start with
}
void petWatchdog()
{
    IWDG_KR =0x0000aaaa;   // Reset the WDT counter
}
int main()
{
    int *BadPointer = (int *)0x60000000; // point to a know bad part of memory
    RCC_AHBENR |= 0x00080000;
    GPIOC_MODER = 0x00050000;
    GPIOC_ODR = 0x00000200;  // Turn on the Green LED to show reset has happened
    delay(50000);
    initWatchdog();
    while(1)
    {
        GPIOC_ODR = 0x00000100;
        delay(500000);
        GPIOC_ODR = 0x00000000;
        delay(500000);
        *BadPointer = 2; // Force a bus-fault by writing to non-existant memory (comment out for normal operation)
        petWatchdog();
        
    }
    return 0;
}
