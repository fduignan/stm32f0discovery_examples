// Use the Timer6 module
#include <stdint.h>
#include "stm32f05xxx.h"
#include "wavetable.h" // includes the global array "wavetable" : 1024 entries, 16 bit signed, single cycle
#include "envelope.h"  // includes the global array "envelope" : 1024 entries, 16 bit signed.  Range 0 to 1023
#define SAMPLE_RATE 22050
#define TABLE_LENGTH 1024
volatile uint16_t WaveformStepSize=1;
volatile uint16_t EnvelopeStepSize=1;
volatile int32_t EnvelopeFactor=0;
volatile uint32_t SysTickCounter = 0;
volatile uint16_t EnvelopeIndex = 0;
void delay(uint32_t dly)
{    
    SysTickCounter = 0;
    while (SysTickCounter < dly);
}
void initDAC()
{
    // DAC1 is on PA4
    // Enable GPIOA
    RCC_AHBENR |= BIT17;
    // Configure PA4 to be in analog mode 
    GPIOA_MODER |= BIT8 + BIT9;
    RCC_APB1ENR |= BIT29; // enable the DAC clock
    DAC_CR |= BIT0 + BIT1; // enable the DAC and the output buffer
    DAC_DHR12R1 = 0; // initialize the DAC with zero
}
void writeDAC(uint16_t Value)
{
    DAC_DHR12R1 = Value;
}
void initClock()
{
    // This is potentially a dangerous function as it could
    // result in a system with an invalid clock signal - result: a stuck system
    // Set the PLL up
    // First ensure PLL is disabled
    RCC_CR &= ~BIT24;
    while( (RCC_CR & BIT25)); // wait for PLL ready to be cleared
    
    // Warning here: if system clock is greater than 24MHz then wait-state(s) need to be
    // inserted into Flash memory interface
    FLASH_ACR |= BIT0;
    FLASH_ACR &=~(BIT2 | BIT1);
    
    // Turn on FLASH prefetch buffer
    FLASH_ACR |= BIT4;
    
    // set PLL multiplier to 12 (yielding 48MHz)
    RCC_CFGR &= ~(BIT21 | BIT20 | BIT19 | BIT18);
    RCC_CFGR |= (BIT21 | BIT19 ); 
    
    // Need to limit ADC clock to below 14MHz so will change ADC prescaler to 4
    RCC_CFGR |= BIT14;
    
    // and turn the PLL back on again
    RCC_CR |= BIT24;        
    // set PLL as system clock source 
    RCC_CFGR |= BIT1;
}


void initSysTick()
{
    
    STK_CSR |= ( BIT1 | BIT0); // enable systick, source = reference clock, enable interrupt
    //  Divide reference clock by value from calib register  to create a 1ms timebase        
    STK_RVR = (STK_CALIB & 0xffffff);   
    STK_CVR = 1; // don't want long wait for counter to count down from initial high unknown value
    
}
void SysTick()
{
    EnvelopeFactor = envelope[EnvelopeIndex];
    if (EnvelopeIndex < TABLE_LENGTH)
    {
        EnvelopeIndex += EnvelopeStepSize;
    }
    SysTickCounter++;        
}
void initTimer6()
{
    RCC_APB1ENR |= BIT4; // enable clocking of the timer registers
    TIM6_CNT = 1;        // set initial count to a low value
    TIM6_PSC = 0;        // initial prescaler value    
    TIM6_ARR  = 48000000/SAMPLE_RATE;   // initial auto-reload value  
    TIM6_DIER |= BIT0;   // enable update interrupt (occurs at reload)
    ISER |= BIT17;       // enable interrupt 17 in the NVIC
    TIM6_CR1 |= BIT0;    // enable the timer
}

void OnTimer6Tick()
{
    static uint16_t IRQCounter1  = 0;
    static uint16_t IRQCounter2  = 0;
    TIM6_SR = 0; // Clear the IRQ flag
    int DacValue = wavetable[IRQCounter1 % TABLE_LENGTH];//+wavetable[IRQCounter2 % 1024];
    DacValue = DacValue *EnvelopeFactor;
    // Scaling factor : Assuming maximum polyphony of 4
    // 12 bit DAC so need to scale down from 16 bits to 12 so divide by 16
    // Need also to scale down by EnvelopeFactor so divide by 1024
    // Total scaling =  16 bits.
    DacValue = DacValue >> 16;
    DacValue += 2047; // Level shift as DAC is unipolar
    writeDAC(DacValue);     
    IRQCounter1 +=WaveformStepSize;   
    IRQCounter2 +=32;
    
}
void playNote(uint16_t Frequency, uint16_t milliseconds)
{
    // Play tone of Frequency for milliseconds.  
    // Envelope array is stretched to required number of milliseconds 
    // If a value > TABLE_LENGTH is specified for milliseconds then
    // the note carries on indefinitely.
    WaveformStepSize=(Frequency*TABLE_LENGTH)/SAMPLE_RATE;
    EnvelopeStepSize = TABLE_LENGTH / milliseconds;
    EnvelopeIndex = 0;
    while(EnvelopeIndex < TABLE_LENGTH);
    
}
void playHappyBirthday()
{
    /*
     * Happy Birthday
     *            CCDCFE
     *            CCDCGF
     *            CChCAFED
     *            BbBbAFGF
     * Sounds better up an octave
     */ 
    playNote(261*2,350); // C
    playNote(261*2,350); // C
    playNote(294*2,500); // D
    playNote(261*2,500); // C
    playNote(349*2,500); // F
    playNote(329*2,500); // E
    
    playNote(261*2,350); // C
    playNote(261*2,350); // C
    playNote(294*2,500); // D
    playNote(261*2,500); // C
    playNote(392*2,500); // G        
    playNote(349*2,500); // F
    
    playNote(261*2,350); // C
    playNote(261*2,350); // C
    playNote(261*4,350); // Ch        
    playNote(440*2,500); // A
    playNote(349*2,500); // F
    playNote(329*2,500); // E
    playNote(294*2,500); // D
    
    playNote(466*2,350); // Bb
    playNote(466*2,350); // Bb
    playNote(440*2,500); // A
    playNote(349*2,500); // F
    playNote(392*2,500); // G        
    playNote(349*2,500); // F
}

int main()
{    
    RCC_AHBENR |= 0x00080000; // Turn on the clock for GPIOC
    GPIOC_MODER = 0x00050000; // Configure bit 8 and bit 9 of GPIOC outputs
    initClock();
    initDAC();    
    initSysTick();    
    initTimer6();
    enable_interrupts();    
    while(1)
    {        
        playHappyBirthday();   
        //playNote(1000,2000);
        delay(1000); // wait a second
    }
    return 0;
}
