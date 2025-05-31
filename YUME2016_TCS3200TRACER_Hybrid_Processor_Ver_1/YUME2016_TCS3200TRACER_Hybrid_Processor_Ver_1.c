/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
� Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : YUME TCS3200 + Photodiode Tracer Processor 
Version : Ver.1.0
Date    : April 21st 2016
Author  : Intelligent Fire Fighting Robot Division 
Company : University of Brawijaya
Comments: 


Chip type               : ATmega8
Program type            : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega8.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h> 
#include <math.h>
#include <YUME2016_TCS3200TRACER_Hybrid_Processor_Ver_1.h> 

// Standard Input/Output functions
#include <stdio.h>



#ifndef RXB8
#define RXB8 1
#endif

#ifndef TXB8
#define TXB8 0
#endif

#ifndef UPE
#define UPE 2
#endif

#ifndef DOR
#define DOR 3
#endif

#ifndef FE
#define FE 4
#endif

#ifndef UDRE
#define UDRE 5
#endif

#ifndef RXC
#define RXC 7
#endif

#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<DOR)
#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)

// USART Receiver buffer
#define RX_BUFFER_SIZE 8
char rx_buffer[RX_BUFFER_SIZE];

#if RX_BUFFER_SIZE <= 256
unsigned char rx_wr_index,rx_rd_index,rx_counter;
#else
unsigned int rx_wr_index,rx_rd_index,rx_counter;
#endif

// This flag is set on USART Receiver buffer overflow
bit rx_buffer_overflow;

// USART Receiver interrupt service routine
interrupt [USART_RXC] void usart_rx_isr(void)
{
char status,data;
status=UCSRA;
data=UDR;
if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
   {
   rx_buffer[rx_wr_index++]=data;
#if RX_BUFFER_SIZE == 256
   // special case for receiver buffer size=256
   if (++rx_counter == 0)
      {
#else
   if (rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
   if (++rx_counter == RX_BUFFER_SIZE)
      {
      rx_counter=0;
#endif
      rx_buffer_overflow=1;
      }
   }
}

#ifndef _DEBUG_TERMINAL_IO_
// Get a character from the USART Receiver buffer
#define _ALTERNATE_GETCHAR_
#pragma used+
char getchar(void)
{
char data;
while (rx_counter==0);
data=rx_buffer[rx_rd_index++];
#if RX_BUFFER_SIZE != 256
if (rx_rd_index == RX_BUFFER_SIZE) rx_rd_index=0;
#endif
#asm("cli")
--rx_counter;
#asm("sei")
return data;
}
#pragma used-
#endif

// Standard Input/Output functions
#include <stdio.h>

// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
// Place your code here
    TCS3200_COUNTER++;

}

#define ADC_VREF_TYPE 0x60

// Read the 8 most significant bits
// of the AD conversion result
unsigned char read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCH;
}

// Declare your global variables here

void main(void)
{

    YUME_Initialization();  
    TCS3200_Config(3);   

    while (1)
    {   
//        TRIGGER= getchar();
//        printf("\r\r");
//        if(TRIGGER=='X')
//        {
////            Tracer_Sampling(FRONT);  
////            Tracer_Sampling(MIDDLE);
////            Tracer_Sampling(REAR);
//
//            Tracer_GetRule();
//            
//            //TCS3200_Sampling();           
////            TCS3200_GetRule();                         
//            TRIGGER=0;
//        }   
        
        Get_CMD(); 

    }
}


void YUME_Initialization(void)
{
    // Declare your local variables here

    // Input/Output Ports initialization
    // Port B initialization
    // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=Out Func1=Out Func0=Out 
    // State7=T State6=T State5=T State4=T State3=T State2=0 State1=0 State0=0 
    PORTB=0x00;
    DDRB=0x07;

    // Port C initialization
    // Func6=In Func5=Out Func4=Out Func3=Out Func2=In Func1=In Func0=In 
    // State6=T State5=0 State4=0 State3=0 State2=T State1=T State0=T 
    PORTC=0x00;
    DDRC=0x38;

    // Port D initialization
    // Func7=In Func6=In Func5=In Func4=Out Func3=Out Func2=In Func1=In Func0=In 
    // State7=T State6=T State5=T State4=0 State3=0 State2=T State1=T State0=T 
    PORTD=0x00;
    DDRD=0x18;

    // Timer/Counter 0 initialization
    // Clock source: System Clock
    // Clock value: Timer 0 Stopped
    TCCR0=0x00;
    TCNT0=0x00;

    // Timer/Counter 1 initialization
    // Clock source: System Clock
    // Clock value: Timer1 Stopped
    // Mode: Normal top=0xFFFF
    // OC1A output: Discon.
    // OC1B output: Discon.
    // Noise Canceler: Off
    // Input Capture on Falling Edge
    // Timer1 Overflow Interrupt: On
    // Input Capture Interrupt: Off
    // Compare A Match Interrupt: Off
    // Compare B Match Interrupt: Off
    TCCR1A=0x00;
    TCCR1B=0x00;
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x00;
    OCR1AL=0x00;
    OCR1BH=0x00;
    OCR1BL=0x00;

    // Timer/Counter 2 initialization
    // Clock source: System Clock
    // Clock value: Timer2 Stopped
    // Mode: Normal top=0xFF
    // OC2 output: Disconnected
    ASSR=0x00;
    TCCR2=0x00;
    TCNT2=0x00;
    OCR2=0x00;

    // External Interrupt(s) initialization
    // INT0: Off
    // INT1: Off
    MCUCR=0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=0x04;

    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: On
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA=0x00;
    UCSRB=0x98;
    UCSRC=0x86;
    UBRRH=0x00;
    UBRRL=0x67;

    // Analog Comparator initialization
    // Analog Comparator: Off
    // Analog Comparator Input Capture by Timer/Counter 1: Off
    ACSR=0x80;
    SFIOR=0x00;

    // ADC initialization
    // ADC Clock frequency: 500.000 kHz
    // ADC Voltage Reference: AVCC pin
    // Only the 8 most significant bits of
    // the AD conversion result are used
    ADMUX=ADC_VREF_TYPE & 0xff;
    ADCSRA=0x85;

    // SPI initialization
    // SPI disabled
    SPCR=0x00;

    // TWI initialization
    // TWI disabled
    TWCR=0x00;

    // Global enable interrupts
    #asm("sei")

}

void Send_UART(unsigned char data)
{
    while(!(UCSRA & (1<<UDRE))){};
    UDR=data;
}


void TCS3200_Config(unsigned int mode)
{
    if(mode==0)         //output frequency scaling power down
    {
        TCS3200_S0=0;
        TCS3200_S1=0;    
    }
    if(mode==1)         //output frequency scaling 1:50
    {
        TCS3200_S0=0;
        TCS3200_S1=1;
    }
    if(mode==2)         //output frequency scaling 1:5
    {
        TCS3200_S0=1;
        TCS3200_S1=0;
    }
    if(mode==3)         //output frequency scaling 1:1
    {
        TCS3200_S0=1;
        TCS3200_S1=1;
    }
    return;
}


void TCS3200Read(void)
{
    TCS3200Read_R();
    TCS3200Read_G();
    TCS3200Read_B();
    TCS3200Read_W();   
    
    printf("Red  : %d \t",(int)TCS3200_Pulse_R);
    printf("Green: %d \t",(int)TCS3200_Pulse_G);
    printf("Blue: %d \t",(int)TCS3200_Pulse_B);
    printf("White: %d \r",(int)TCS3200_Pulse_W); 
}

int TCS3200Read_R(void)
{
     TCS3200_S2=0;
     TCS3200_S3=0;
     delay_ms(5);
     TCCR1B=0x06;
     delay_ms(5);
     TCCR1B=0x00;
     TCS3200_Pulse_R=((int)TCS3200_COUNTER*256)+(int)TCNT1;
     TCNT1=0;
     TCS3200_COUNTER=0;
     delay_ms(10);    
     return TCS3200_Pulse_R;

}

int TCS3200Read_G(void)
{
     TCS3200_S2=1;
     TCS3200_S3=1;   
     delay_ms(5);
     TCCR1B=0x06;
     delay_ms(5);
     TCCR1B=0x00; 
     TCS3200_Pulse_G=((int)TCS3200_COUNTER*256)+(int)TCNT1;
//    TCS3200_Pulse_G=((int)MIDDLE_COUNTER*65536)+(int)TCNT1;
     TCNT1=0;
     TCS3200_COUNTER=0;
     delay_ms(10);  
     return TCS3200_Pulse_G;
     
}

int TCS3200Read_B(void)
{
     TCS3200_S2=0;
     TCS3200_S3=1; 
     delay_ms(5);
     TCCR1B=0x06;
     delay_ms(5);
     TCCR1B=0x00;   
     TCS3200_Pulse_B=((int)TCS3200_COUNTER*256)+(int)TCNT1;
//     TCS3200_Pulse_B=((int)TCS3200_COUNTER*65536)+(int)TCNT1;
     TCNT1=0;
     TCS3200_COUNTER=0;
     delay_ms(10);    
     return TCS3200_Pulse_B;
     
}

int TCS3200Read_W(void)
{
     TCS3200_S2=1;
     TCS3200_S3=0;  
     delay_ms(5);
     TCCR1B=0x06;
     delay_ms(5);
     TCCR1B=0x00;  
     TCS3200_Pulse_W=((int)TCS3200_COUNTER*256)+(int)TCNT1;
//    TCS3200_Pulse_W=((int)TCS3200_COUNTER*65536)+(int)TCNT1;
     TCNT1=0;
     TCS3200_COUNTER=0;
     delay_ms(10);   
     return TCS3200_Pulse_W;
    
}



/*
 * DATA PACKET STRUCTURE 
 * [COMMAND_FLAG_A] [COMMAND_FLAG_B] [F_DETECTED_COLOUR] [M_DETECTED_COLOUR] [TRACER_STAT] [COLOUR_STAT]
 *
*/
void Send_TCS3200_Conclusion(void)
{
    Send_UART(COMMAND_FLAG_A); 
    Send_UART(COMMAND_FLAG_B);  
    Send_UART(DETECTED_COLOUR);
    Send_UART(TRACER_STAT);    
}

void Get_CMD(void)
{
    TCS3200_CMD[TEMPORARY] = getchar();;
    
    if(TCS3200_CMD[TEMPORARY]!=CMD_IDLE)
    {
        TCS3200_CMD[1] = TCS3200_CMD[0];
        TCS3200_CMD[0] = TCS3200_CMD[TEMPORARY]; 
    }  
    
    //Switch-case version
    switch(TCS3200_CMD[0])
    {
        case TCS3200_CMD_SEND_RAW:{
                                    TCS3200_Sampling();                                  
                                    Send_UART(COMMAND_FLAG_A); 
                                    Send_UART(COMMAND_FLAG_B);
                                    Send_UART(RAW_VAL_FLAG);  
                                         
                                    //RED FILTER RAW VALUE
                                    MULTIPLY_COUNTER=0;                                 
                                    if(MOV_AVG[TCS3200_RED]>255)
                                    {
                                        while( MOV_AVG[TCS3200_RED] >255)
                                        {
                                           MOV_AVG[TCS3200_RED]-=255;
                                           MULTIPLY_COUNTER++;
                                        }
                                    }
                                    Send_UART(MULTIPLY_COUNTER);  
                                    Send_UART(MOV_AVG[TCS3200_RED]); 
                                      
                                    //GREEN FILTER RAW VALUE
                                    MULTIPLY_COUNTER=0;                                 
                                    if(MOV_AVG[TCS3200_GREEN]>255)
                                    {
                                        while( MOV_AVG[TCS3200_GREEN] >255)
                                        {
                                           MOV_AVG[TCS3200_GREEN]-=255;
                                           MULTIPLY_COUNTER++;
                                        }
                                    }     
                                    Send_UART(MULTIPLY_COUNTER);  
                                    Send_UART(MOV_AVG[TCS3200_GREEN]);
                                      
                                    //BLUE FILTER RAW VALUE
                                    MULTIPLY_COUNTER=0;                                 
                                    if(MOV_AVG[TCS3200_BLUE]>255)
                                    {
                                        while( MOV_AVG[TCS3200_BLUE] >255)
                                        {
                                           MOV_AVG[TCS3200_BLUE]-=255;
                                           MULTIPLY_COUNTER++;
                                        }
                                    }     
                                    Send_UART(MULTIPLY_COUNTER);  
                                    Send_UART(MOV_AVG[TCS3200_BLUE]); 
                                    
                                    //WHITE FILTER RAW VALUE
                                    MULTIPLY_COUNTER=0;                                 
                                    if(MOV_AVG[TCS3200_WHITE]>255)
                                    {
                                        while( MOV_AVG[TCS3200_WHITE] >255)
                                        {
                                           MOV_AVG[TCS3200_WHITE]-=255;
                                           MULTIPLY_COUNTER++;
                                        }
                                    }     
                                    Send_UART(MULTIPLY_COUNTER);  
                                    Send_UART(MOV_AVG[TCS3200_WHITE]);
                                    
                                    //SUM FILTER RAW VALUE
                                    MULTIPLY_COUNTER=0;                                 
                                    if(TCS3200_TOTAL_SUM>255)
                                    {
                                        while( TCS3200_TOTAL_SUM >255)
                                        {
                                           TCS3200_TOTAL_SUM-=255;
                                           MULTIPLY_COUNTER++;
                                        }
                                    }     
                                    Send_UART(MULTIPLY_COUNTER);  
                                    Send_UART(TCS3200_TOTAL_SUM);
                                     
                                }break;     
                                
                                
        case TRACER_CMD_SEND_RAW:{  
                                        Tracer_GetRule();
                                        Send_UART(COMMAND_FLAG_A); 
                                        Send_UART(COMMAND_FLAG_B);
                                        Send_UART(RAW_VAL_FLAG);                                          
                                        Send_UART(TRACER[FRONT]); 
                                        Send_UART(TRACER[MIDDLE]);
                                        Send_UART(TRACER[REAR]);
                                        Send_UART(TRACER_STAT); 
                                        Send_UART(TRACER_THRESHOLD);
                                    
                                }break;                            
                                                                  
        case HYBRID_CMD_SEND_CONCLUSION:
                                    {  
                                        Tracer_GetRule();
                                        TCS3200_GetRule();
                                        Send_UART(COMMAND_FLAG_A); 
                                        Send_UART(COMMAND_FLAG_B);                                          
                                        Send_UART(DETECTED_COLOUR);
                                        Send_UART(TRACER_STAT);
                                    
                                    }break;
        
        case TCS3200_CMD_SAVE_EEPROM:   
                                    {
                                        TCS3200Read();                                                                                                                        
                                        EEPROM_A= TCS3200_Pulse_G;
                                        EEPROM_B= TCS3200_Pulse_B;
                                        EEPROM_C= TCS3200_Pulse_W; 
                                        EEPROM_D= TCS3200_Pulse_Sum;          
                                    }break;
        
        case HYBRID_CMD_SEND_THRESHOLD:
                                    {
                                        Send_Threshold();                                     
                                    }break;
        
        case TCS3200_CALIBRATE_WHITE:
                                    {  
                                        TCS3200_Sampling();
                                        Threshold_White= TCS3200_TOTAL_SUM; 
                                    }break;
        case TCS3200_CALIBRATE_BLACK:
                                    {           
                                        
                                        TCS3200_Sampling();
                                        Threshold_Black = TCS3200_TOTAL_SUM;      
                                    }break;  
        case TCS3200_CALIBRATE_GRAY:
                                    { 
                                         
                                        TCS3200_Sampling();
                                        Threshold_Gray = TCS3200_TOTAL_SUM;      
                                    }break; 
        case TCS3200_CALIBRATE_GETRULE:
                                    {                                          
                                        Threshold_Diff = Threshold_White-Threshold_Gray;
                                         
                                        if(Threshold_Diff>1400)
                                        {
                                            Threshold_BW = Threshold_Gray + 1390;     
                                        }   
                                        else if(Threshold_Diff>1350)
                                        {
                                            Threshold_BW = Threshold_Gray + 1340;     
                                        }
                                                                                
                                        else if(Threshold_Diff>1300)
                                        {
                                            Threshold_BW = Threshold_Gray + 1290;     
                                        } 
                                        else if(Threshold_Diff>1250)
                                        {
                                            Threshold_BW = Threshold_Gray + 1240;     
                                        }
                                                                                
                                        else if(Threshold_Diff>1200)
                                        {
                                            Threshold_BW = Threshold_Gray + 1190;     
                                        } 
                                        else if(Threshold_Diff>1150)
                                        {
                                            Threshold_BW = Threshold_Gray + 1140;     
                                        }
                                                                                
                                        else if(Threshold_Diff>1100)
                                        {
                                            Threshold_BW = Threshold_Gray + 1190;     
                                        }
                                        else if(Threshold_Diff>1050)
                                        {
                                            Threshold_BW = Threshold_Gray + 1040;     
                                        }
                                        else if(Threshold_Diff>1000)
                                        {
                                            Threshold_BW = Threshold_Gray + 990;     
                                        }
                                                                                
                                        else if(Threshold_Diff>950)
                                        {
                                            Threshold_BW = Threshold_Gray + 940;     
                                        }
                                        
                                        else if(Threshold_Diff>900)
                                        {
                                            Threshold_BW = Threshold_Gray + 890;     
                                        }
                                                                               
                                        else if(Threshold_Diff>850)
                                        {
                                            Threshold_BW = Threshold_Gray + 840;     
                                        } 
                                        
                                        else if(Threshold_Diff>800)
                                        {
                                            Threshold_BW = Threshold_Gray + 790;     
                                        } 
                                        else if(Threshold_Diff>700)
                                        {
                                            Threshold_BW = Threshold_Gray + 690;     
                                        }  
                                        else if(Threshold_Diff>600)
                                        {
                                            Threshold_BW = Threshold_Gray + 590;     
                                        }  
                                        else if(Threshold_Diff>500)
                                        {
                                            Threshold_BW = Threshold_Gray + 490;     
                                        }   
                                        else if(Threshold_Diff>450)
                                        {
                                            Threshold_BW = Threshold_Gray + 440;     
                                        }
                                        else if(Threshold_Diff>400)
                                        {
                                            Threshold_BW = Threshold_Gray + 390;     
                                        } 
                                        else if(Threshold_Diff>350)
                                        {
                                            Threshold_BW = Threshold_Gray + 340;     
                                        }  
                                        else if(Threshold_Diff>300)
                                        {
                                            Threshold_BW = Threshold_Gray + 290;     
                                        } 
                                        else if(Threshold_Diff>250)
                                        {
                                            Threshold_BW = Threshold_Gray + 240;     
                                        }    
                                        else if(Threshold_Diff>200)
                                        {
                                            Threshold_BW = Threshold_Gray + 190;     
                                        }         
                                        else if(Threshold_Diff>150)
                                        {
                                            Threshold_BW = Threshold_Gray + 140;     
                                        }             
                                        else if(Threshold_Diff>100)
                                        {
                                            Threshold_BW = Threshold_Gray + 90;     
                                        }                                                          
                                        else if(Threshold_Diff>50)
                                        {
                                            Threshold_BW = Threshold_Gray + 40;     
                                        }
                                        else 
                                        {
                                            Threshold_BW = Threshold_Gray + 30;
                                        }    
                                                     
                                        
                                        Threshold_Diff= Threshold_Gray - Threshold_Black;   
                                          
//                                        if(Threshold_Diff>400)
//                                        {
//                                            Threshold_BG = Threshold_Black + 375;     
//                                        }  
//                                        if(Threshold_Diff>375)
//                                        {
//                                            Threshold_BG = Threshold_Black + 350;     
//                                        }    
//                                        else if(Threshold_Diff>350)
//                                        {
//                                            Threshold_BG = Threshold_Black + 325;     
//                                        }
                                          
                                        if(Threshold_Diff>310)
                                        {
                                            Threshold_BG = Threshold_Black + 300;     
                                        }
                                         
                                        else if(Threshold_Diff>300)
                                        {
                                            Threshold_BG = Threshold_Black + 290;     
                                        }
                                        
                                        else if(Threshold_Diff>290)
                                        {
                                            Threshold_BG = Threshold_Black + 280;     
                                        }                    
                                        
                                        
                                        else if(Threshold_Diff>280)
                                        {
                                            Threshold_BG = Threshold_Black + 270;     
                                        } 
                                        
                                        else if(Threshold_Diff>270)
                                        {
                                            Threshold_BG = Threshold_Black + 260;     
                                        }
                                        
                                        else if(Threshold_Diff>260)
                                        {
                                            Threshold_BG = Threshold_Black + 250;     
                                        }
                                        
                                        else if(Threshold_Diff>250)
                                        {
                                            Threshold_BG = Threshold_Black + 225;     
                                        }
                                        else if(Threshold_Diff>225)
                                        {
                                            Threshold_BG = Threshold_Black + 200;     
                                        }           
                                        
                                        else if(Threshold_Diff>200)
                                        {
                                            Threshold_BG = Threshold_Black + 175;     
                                        }  
                                        else if(Threshold_Diff>175)
                                        {
                                            Threshold_BG = Threshold_Black + 150;     
                                        }
                         
                                        else if(Threshold_Diff>150)
                                        {
                                            Threshold_BG = Threshold_Black + 125;     
                                        }    
                                        else if(Threshold_Diff>125)
                                        {
                                            Threshold_BG = Threshold_Black + 100;     
                                        }         
                                        else if(Threshold_Diff>100)
                                        {
                                            Threshold_BG = Threshold_Black + 75;     
                                        }             
                                        else if(Threshold_Diff>75)
                                        {
                                            Threshold_BG = Threshold_Black + 50;     
                                        }                                                          
                                        else if(Threshold_Diff>50)
                                        {
                                            Threshold_BG = Threshold_Black + 25;     
                                        }
                                        else 
                                        {
                                            Threshold_BG = Threshold_Black + 25;
                                        }                                             
                                    }break;  
                                    
            case TRACER_CALIBRATE_GRAY:
                                    {                                          
                                        Tracer_GetData_Gray();      
                                    }break;   
                                    
            case TRACER_CALIBRATE_WHITE:
                                    { 
                                        Tracer_GetData_White();      
                                    }break;   
            
            case TRACER_CALIBRATE_GETRULE:
                                    { 
                                        Tracer_Calibrate_GetRule();      
                                    }break;
    }
   
}

int Tracer_Sampling(int MODE)
{
    switch(MODE)
    {
        case 0: {
                    TRACER[FRONT]= read_adc(2);
                    if(TRACER[FRONT]>=TRACER_THRESHOLD)
                    { 
                        printf("TRACER FRONT ACTIVE \r");
                        TRACER_SECTION[FRONT]= TRACER_ACTIVE;
                    }
                     
                    else 
                    {
                        printf("TRACER FRONT INACTIVE \r");
                        TRACER_SECTION[FRONT]= TRACER_INACTIVE; 
                    }
                    return TRACER[FRONT];                   
                }break; 
                 
        case 1: {
                    TRACER[MIDDLE]= read_adc(1);
                    if(TRACER[MIDDLE]>=TRACER_THRESHOLD)
                    { 
                        printf("TRACER MIDDLE ACTIVE \r");
                        TRACER_SECTION[MIDDLE]= TRACER_ACTIVE;
                    }
                     
                    else 
                    {
                        printf("TRACER MIDDLE INACTIVE \r");
                        TRACER_SECTION[MIDDLE]= TRACER_INACTIVE; 
                    }
                    return TRACER[MIDDLE];                        
                }break; 
                
        case 2: {
                    TRACER[REAR]= read_adc(0);
                    if(TRACER[REAR]>=TRACER_THRESHOLD)
                    { 
                        printf("TRACER REAR ACTIVE \r");
                        TRACER_SECTION[REAR]= TRACER_ACTIVE;
                    }
                     
                    else 
                    {
                        printf("TRACER REAR INACTIVE \r");
                        TRACER_SECTION[REAR]= TRACER_INACTIVE; 
                    }
                    return TRACER[REAR];                      
                }break;
    }
}

void Tracer_GetRule(void)
{
    Tracer_Sampling(FRONT);
    Tracer_Sampling(MIDDLE);
    Tracer_Sampling(REAR); 
    
    printf("TRACER[FRONT]: %d \t TRACER[MIDDLE]: %d \t TRACER[REAR]: %d  \r",TRACER[FRONT],TRACER[MIDDLE],TRACER[REAR] );
    
    if( (TRACER_SECTION[FRONT]==TRACER_ACTIVE) || (TRACER_SECTION[MIDDLE]==TRACER_ACTIVE) || (TRACER_SECTION[REAR]==TRACER_ACTIVE) )
    {  
        printf("TRACER STAT ACTIVE \r");
        TRACER_STAT=TRACER_ACTIVE;
    }
    else
    {          
        printf("TRACER STAT INACTIVE \r");
        TRACER_STAT=TRACER_INACTIVE;
    } 
    
}

void Tracer_GetData_Gray(void)
{
     int TRC_FRONT,TRC_MIDDLE,TRC_REAR;
     int THold_Temp;
     
     TRC_FRONT  = Tracer_Sampling(FRONT); 
     TRC_MIDDLE = Tracer_Sampling(MIDDLE);
     TRC_REAR   = Tracer_Sampling(REAR); 
     
//     THold_Temp = max(TRC_FRONT, TRC_MIDDLE);
//     THold_Temp = max(THold_Temp, TRC_REAR);
     if(TRC_FRONT >= TRC_MIDDLE) THold_Temp = TRC_FRONT;
     else THold_Temp= TRC_MIDDLE;
     
     if(TRC_REAR >= THold_Temp) THold_Temp = TRC_REAR;
     
     TRACER_GRAYDATA= THold_Temp;
     
}

void Tracer_GetData_White(void)
{
     int TRC_FRONT,TRC_MIDDLE,TRC_REAR;
     int THold_Temp;
     
     TRC_FRONT  = Tracer_Sampling(FRONT); 
     TRC_MIDDLE = Tracer_Sampling(MIDDLE);
     TRC_REAR   = Tracer_Sampling(REAR); 
     
//     THold_Temp = min(TRC_FRONT, TRC_MIDDLE);
//     THold_Temp = min(THold_Temp, TRC_REAR);

     if(TRC_FRONT <= TRC_MIDDLE) THold_Temp = TRC_FRONT;
     else THold_Temp= TRC_MIDDLE;
     
     if(TRC_REAR <= THold_Temp) THold_Temp = TRC_REAR;
     
     TRACER_WHITEDATA= THold_Temp;
}

void Tracer_Calibrate_GetRule(void)
{
    int Tracer_Diff;
    int Tracer_White= TRACER_WHITEDATA;
    int Tracer_Gray= TRACER_GRAYDATA;
    
    //Tracer_Diff= TRACER_WHITEDATA-TRACER_GRAYDATA;
    Tracer_Diff= Tracer_White-Tracer_Gray;    
    
    if(Tracer_Diff>=80)      TRACER_THRESHOLD   = Tracer_Gray + 75;
    else if(Tracer_Diff>=75) TRACER_THRESHOLD   = Tracer_Gray + 70;
    else if(Tracer_Diff>=70) TRACER_THRESHOLD   = Tracer_Gray + 65;
    else if(Tracer_Diff>=65) TRACER_THRESHOLD   = Tracer_Gray + 60;
    else if(Tracer_Diff>=60) TRACER_THRESHOLD   = Tracer_Gray + 55;
    else if(Tracer_Diff>=50) TRACER_THRESHOLD   = Tracer_Gray + 45;
    else if(Tracer_Diff>=40) TRACER_THRESHOLD   = Tracer_Gray + 35;
    else if(Tracer_Diff>=30) TRACER_THRESHOLD   = Tracer_Gray + 25; 
    else if(Tracer_Diff>=20) TRACER_THRESHOLD   = Tracer_Gray + 15; 
    else if(Tracer_Diff>=10) TRACER_THRESHOLD   = Tracer_Gray + 7;
        
}




void TCS3200_Sampling(void)
{

    int counter;        
    
    MOV_AVG[TCS3200_RED]=0;
    MOV_AVG[TCS3200_GREEN]=0;
    MOV_AVG[TCS3200_BLUE]=0;
    MOV_AVG[TCS3200_WHITE]=0;
    
    for(counter=1;counter<=1;counter++)
    {
        TCS3200Read_R();
        TCS3200Read_G();
        TCS3200Read_B();
        TCS3200Read_W();
        
        MOV_AVG[TCS3200_RED]+=TCS3200_Pulse_R;
        MOV_AVG[TCS3200_GREEN]+=TCS3200_Pulse_G;
        MOV_AVG[TCS3200_BLUE]+=TCS3200_Pulse_B;
        MOV_AVG[TCS3200_WHITE]+=TCS3200_Pulse_W;   
        
         TCS3200_TOTAL_SUM = TCS3200_Pulse_R + TCS3200_Pulse_B + TCS3200_Pulse_G + TCS3200_Pulse_W;
//         if(TCS3200_TOTAL_SUM >= 1800)
//         {
//            DETECTED_COLOUR         = COLOUR_WHITE;
//            TRACER_STAT             = TRACER_ACTIVE;    
//            printf("========== CONCLUSION: WHITE ============= \r"); 
//            
//            Send_UART(COMMAND_FLAG_A); 
//            Send_UART(COMMAND_FLAG_B);      
//            Send_UART(DETECTED_COLOUR);
//            Send_UART(TRACER_STAT);
//            
//         }
    }     
    
    MOV_AVG[TCS3200_RED]/=1;
    MOV_AVG[TCS3200_GREEN]/=1;
    MOV_AVG[TCS3200_BLUE]/=1;
    MOV_AVG[TCS3200_WHITE]/=1;
 
            
//    FRONT_THRESHOLD = FRONT_Pulse_R - FRONT_Pulse_B;
//    FRONT_TOTAL_SUM = FRONT_Pulse_R + FRONT_Pulse_B + FRONT_Pulse_G + FRONT_Pulse_W;
//        
//    printf("FRONT_THRESHOLD = %d \t\t FRONT_TOTAL_SUM %d \r",FRONT_THRESHOLD, FRONT_TOTAL_SUM);   

    TCS3200_TOTAL_SUM = MOV_AVG[TCS3200_RED] + MOV_AVG[TCS3200_GREEN] + MOV_AVG[TCS3200_BLUE] + MOV_AVG[TCS3200_WHITE];
        
    printf("TCS3200_TOTAL_SUM %d \r",TCS3200_TOTAL_SUM);   
    
    
     
}

//TCS3200_MODE
// 1 -> FRONT
// 2 -> MIDDLE
void Display_Raw_Data(int TCS3200_MODE)
{
    switch(TCS3200_MODE)
    {  
        case 1:
                {  
                    printf("============================================================================= \r",);
                    printf("==========================FRONT TCS3200 MONITOR============================== \r",);
                    printf("============================================================================= \r",);
                    printf("============================================================================= \r",);  
                }break;
        case 2:
                {      
                    printf("============================================================================= \r",);
                    printf("===========================MIDDLE TCS3200 MONITOR============================ \r",);
                    printf("============================================================================= \r",);
                    printf("Red  : %d \t",(int)MOV_AVG[TCS3200_RED]);
                    printf("Green: %d \t",(int)MOV_AVG[TCS3200_GREEN]);
                    printf("Blue: %d \t",(int)MOV_AVG[TCS3200_BLUE]);
                    printf("White: %d \r",(int)MOV_AVG[TCS3200_WHITE]); 
                    printf("TCS3200_THRESHOLD = %d \t\t TCS3200_TOTAL_SUM %d \r",TCS3200_THRESHOLD, TCS3200_TOTAL_SUM);
                    printf("============================================================================= \r",); 
                }break; 
    }
}

void TCS3200_GetRule(void)
{
    TCS3200_Sampling(); 
    
  if(TCS3200_TOTAL_SUM >= Threshold_BW ) //WHITE  
//    if(TCS3200_TOTAL_SUM >= 900 ) //WHITE
    {
        DETECTED_COLOUR       = COLOUR_WHITE;
        //TRACER_STAT           = TRACER_ACTIVE;    
        printf("========== CONCLUSION: WHITE ============= \r"); 
    }
  else if (TCS3200_TOTAL_SUM < Threshold_BW) //GREY CARPET OR BLACK FLOOR
//    else if (TCS3200_TOTAL_SUM < 900) //GREY CARPET OR BLACK FLOOR
    {
        //BLACK FLOOR
        if(TCS3200_TOTAL_SUM < Threshold_BG)
//        if(TCS3200_TOTAL_SUM < 380)
        {
            DETECTED_COLOUR   = COLOUR_BLACK;
            //TRACER_STAT        = TRACER_INACTIVE;   
            printf("========== CONCLUSION: BLACK ============= \r"); 
        }

        //Grey Carpet
        else if(TCS3200_TOTAL_SUM >= Threshold_BG)
//        else if( TCS3200_TOTAL_SUM >= 380)
        {
            DETECTED_COLOUR   = COLOUR_GRAY;
           // TRACER_STAT        = TRACER_INACTIVE;   
           printf("========== CONCLUSION: GRAY ============= \r"); 
        }  
        else
        {
            DETECTED_COLOUR     = COLOUR_ERROR;
            //TRACER_STAT         = TRACER_INACTIVE;    
        }                       
    }
}


void TCS3200_Autocalibration(void)
{
    TCS3200_CMD[0] = getchar();
        
    while (TCS3200_CMD[0] != START_BUTTON)
    {
        TCS3200_CMD[0] = getchar();    
    }       
}


void Send_Threshold(void)
{                        
    int Thold_BW,Thold_BG,Thold_Tracer;
    Thold_BW= Threshold_BW;
    Thold_BG= Threshold_BG;
    Thold_Tracer= TRACER_THRESHOLD; 
           
    Send_UART(COMMAND_FLAG_A); 
    Send_UART(COMMAND_FLAG_B);
    Send_UART(RAW_VAL_FLAG);
    
    //Threshold_BW VALUE
    MULTIPLY_COUNTER=0;                                 
    if(Thold_BW>255)
    {
        while( Thold_BW >255)
        {
           Thold_BW-=255;
           MULTIPLY_COUNTER++;
        }
    }
    Send_UART(MULTIPLY_COUNTER);  
    Send_UART(Thold_BW); 
    
    //Threshold_BG VALUE
    MULTIPLY_COUNTER=0;                                 
    if(Thold_BG>255)
    {
        while( Thold_BG >255)
        {
           Thold_BG-=255;
           MULTIPLY_COUNTER++;
        }
    }
    Send_UART(MULTIPLY_COUNTER);  
    Send_UART(Thold_BG); 
    
    //PHOTODIODE TRACER B/W THRESHOLD
    Send_UART(Thold_Tracer);
}



/*=============== MOVING AVERAGE SMOOTHING ALGORITHM =================
New average = old average * (n-1)/n + new value /n
=====================================================================*/

// Function Prototypes
//int GetMov_AVG(unsigned int TCS_MODE, unsigned int NewVal)
//{
//    Mov_AVG[TCS_MODE]= Mov_AVG[TCS_MODE] * (MovAVG_Counter[TCS_MODE]-1) / MovAVG_Counter[TCS_MODE] + NewVal/MovAVG_Counter[TCS_MODE];    
//    MovAVG_Counter[TCS_MODE]++;
//    return Mov_AVG[TCS_MODE];     
//}

//void GetRule_MovAVG(void)
//{
////    int buff_1,buff_2;
////    
////    for(MovAVG_Counter=1;MovAVG_Counter<=5;MovAVG_Counter++)
////    {      
////        NewVal=FRONT_Read_R(); 
////        buff_1= Mov_AVG * (MovAVG_Counter-1);
////        buff_1= buff_1/ MovAVG_Counter;
////        buff_2= NewVal/MovAVG_Counter; 
////        Mov_AVG= buff_1 + buff_2 ;        
////    }
////  
//   
////   NewVal[F_GREEN]=FRONT_Read_G();
////   GetMov_AVG(F_GREEN,NewVal[F_GREEN]);
////   
////   NewVal[F_BLUE]=FRONT_Read_B();
////   GetMov_AVG(F_BLUE,NewVal[F_BLUE]);
////   
////   NewVal[F_WHITE]=FRONT_Read_W(); 
////   GetMov_AVG(F_WHITE,NewVal[F_WHITE]);   
//   
//    printf("============================================================================= \r",);
//    printf("==========================FRONT TCS3200 MONITOR============================== \r",);
//    printf("============================================================================= \r",);
//    printf("Red  : %d \t",(int)Mov_AVG);
////    printf("Green: %d \t",(int)Mov_AVG[F_GREEN]);
////    printf("Blue : %d \t",(int)Mov_AVG[F_BLUE]);
////    printf("White: %d \r",(int)Mov_AVG[F_WHITE]); 
//    printf("============================================================================= \r",);
//}void Send_UART(unsigned char data)

