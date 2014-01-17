/* 
 * File:   Measurements.h
 * Author: psycku
 *
 * Created on 17 de Janeiro de 2014, 21:32
 */

#ifndef MEASUREMENTS_H
#define	MEASUREMENTS_H

#define MEASUR_SIZE 200

typedef enum months {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, APRIL, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
} Months;

typedef struct data {
    unsigned short int day;
    Months month;
    unsigned short int year;
} Data;

typedef struct time {
    unsigned short int hour;
    unsigned short int minutes;
} Time;

typedef struct measurement {
    unsigned long int employee;
    unsigned short int station;
    Data data;
    Time time;
    unsigned short int temperature;
    unsigned short int wind;
    unsigned short int direction;
    unsigned short int speed;
    SensCloudiness cloudiness;
} Measurement;



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MEASUREMENTS_H */

