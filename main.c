#define F_CPU 4000000UL
#include <avr/io.h>
#include "util/delay.h"



#define stepPin PA4            //Define Step pin
#define dirPin PA6             //Define Direction pin
#define Enable PA5             //Define Enable pin
int d;

const float PI = 3.14159265359;
float radius=14.25, height=2.0, volume;
const float flowrate=10.0;
int d;

void delay()
{
	d =(18*volume)/flowrate;
	
	while (d>0)
	{
		
		_delay_ms(1);
		d--;
	}
	//return d;
}

void forward(void)
{
	int i = 0;
	PORTA.OUTSET |= PIN6_bm;
	for (i = 0; i < 50 * 5; i++)
	{
		PORTA.OUTSET = PIN4_bm;
		delay();
		
		PORTA.OUTCLR = PIN4_bm;
		delay();
	}
}

void reverse(void)
{
	int i = 0;
	PORTA.OUTCLR |= PIN6_bm;
	for (i = 0; i < 50 * 5; i++)
	{
		PORTA.OUTSET = PIN4_bm;
		delay();
		PORTA.OUTCLR = PIN4_bm;
		delay();
	}
}


int main()
{

	
	volume =PI * radius * radius * height;
	//d =18*(volume)*flowrate;

	PORTA.DIR |= PIN4_bm | PIN5_bm | PIN6_bm ;

	//PORTA.DIRSET |= PIN6_bm;
	while(1){
		//forward();
		//	_delay_ms(500);
		
		reverse();
		//delay_delay_us();
		
	}



}