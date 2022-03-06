/*
 * single4051.h
 *
 * Created: 3/3/2022 8:02:50 AM
 *  Author: clamm
 */ 



#ifndef SINGLE4051_H_
#define SINGLE4051_H_
//which ports do you want to use to control your 4051?
//default is PORTD 0-1
#define PORTCHOICE PORTD
#define PINCHOICE0 PIND0
#define PINCHOICE1 PIND1
#define PINCHOICE2 PIND2
#define PINCHOICE3 PIND3

void single4051_out(uint8_t output);

void single4051_inhibit(void);

#endif /* SINGLE4051_H_ */