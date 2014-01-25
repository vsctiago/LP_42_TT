/* 
 * File:   Station.h
 * Author: psycku
 *
 * Created on 14 de Janeiro de 2014, 14:27
 */

#ifndef STATION_H
#define	STATION_H

#include <time.h>
#include "General.h"

#define STA_SIZE 5
#define STA_INIT 0
#define STA_NUMB_MAX 999
#define NUMBER_SENSORS 5

typedef enum sensors {
    TEMPERATURE, PRECIPITATION, WINDSPEED, WINDDIRECTION, CLOUDINESS
} Sensors;

typedef struct station {
    unsigned short int number;
    General general;
    //Sensors sensors;
    //Posição 0-Temperatura 1-precipitacao 2- velocidade do vento
    // 3 direção do vento 4- nuvens
    bool sensors[NUMBER_SENSORS];
    //
    float coordinatesX;
    float coordinatesY;
    int contMeasurements;
    
} Station;

typedef struct sensCloudiness {
    char cloudType;
    char coverage;
} SensCloudiness;

unsigned short int verifyStaPosition(Station stations[]);
Station getNumberStation(Station station[]);
Station getSensors(Station station);
Station getCoordinates(Station station);
Station addStation(Station stations[], int position);
Station modifyStation(Station station, int modOpt);
Station removeStation(Station stations[], unsigned short int number);
void listStations(Station station[]);
Station modiStation(Station station[], unsigned short int numbSta);
void createStationFile(Station stations[]);
Station iniStation(Station station[]);
Station readStationFile(Station stations[]);
void saveStationFile(Station stations[]);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* STATION_H */

