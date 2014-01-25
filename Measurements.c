
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Measurements.h"

Measurement addMeasurement(Measurement measurement, unsigned long int employee,
         unsigned short int station) {
    bool val = false;
    
    measurement.employee = employee;
    measurement.station = station;
    do {
        printf("Insert ");
        scanf("%lu", &measurement);
    } while(val == false);
}






void createMeasurementFile(Measurement measurements[]) {
    
    FILE *pMeasurement = fopen("Measurements", "w");
    if(pMeasurement == (FILE *) NULL) {
        puts("Couldn't create file.");
    } else {
        fwrite(measurements, sizeof(Measurement), MEASUR_SIZE, pMeasurement);
        fclose(pMeasurement);
    }
}

Measurement initMeasurementFile(Measurement measurements[]) {
    int i;
    
    for(i=0; i<MEASUR_SIZE; i++){
        measurements[i].employee = 0;
        measurements[i].station = 0;
    }
    return measurements[MEASUR_SIZE];
}

Measurement readMeasurementFile(Measurement measurements[]) {
    
    FILE *pMeasurement = fopen("Measurements", "r");
    if (pMeasurement == (FILE *) NULL) {
        puts("File doesn't exist");
        puts("Creating file now...");
        createMeasurementFile(measurements);
        measurements[MEASUR_SIZE] = initMeasurementFile(measurements);
        puts("File created.");
        readMeasurementFile(measurements);
    } else {
        fread(measurements, sizeof(Measurement), MEASUR_SIZE, pMeasurement);
        fclose(pMeasurement);
    }
}

void saveMeasurementFile(Measurement measurements[]) {
    
    FILE *pMeasurement = fopen("Measurements","w");
    if(pMeasurement == (FILE *) NULL) {
        puts("File doesn't exist.");
        puts("Couldn't save.");
    } else {
        fwrite(measurements, sizeof(Measurement), MEASUR_SIZE, pMeasurement);
        puts("File saved.");
        fclose(pMeasurement);
    }
}
