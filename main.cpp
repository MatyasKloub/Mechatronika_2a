#include "mbed.h"
#include "LCD_DISCO_F469NI.h"
#include "makra.h"


LCD_DISCO_F469NI lcd;

Thread thread1, thread2;



void text1_thread()
{   
        lcd.SetTextColor(BARVA1);
        lcd.DisplayStringAtLine(SMER1, (uint8_t *)TEXT1);
        ThisThread::sleep_for(1s);
}

void text2_thread()
{   

    lcd.SetTextColor(BARVA2);
    lcd.DisplayStringAtLine(SMER2, (uint8_t *)TEXT2);
    ThisThread::sleep_for(1s);
}



int main()
{    
    thread1.start(text1_thread);
    thread1.join();
    lcd.Clear(BARVA3);
    ThisThread::sleep_for(1s);

    thread2.start(text2_thread);
    thread2.join();
    lcd.Clear(BARVA3);
    ThisThread::sleep_for(2s);


}


