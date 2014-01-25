
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Station.h"

int verifyStaExist(Station stations[], int numbSta) {
    int i, cont = 0;

    for (i = 0; i < STA_SIZE; i++) {
        if (stations[i].number == numbSta)
            cont++;
    }

    return cont;
}

unsigned short int verifyStaPosition(Station stations[]) {
    unsigned short int i, position;

    for (i = 0; i < STA_SIZE; i++) {
        if (stations[i].number == STA_INIT) {
            return position;
        }
    }
    return EOF;

}

Station getNumberStation(Station stations[]) {
    unsigned short int numbSta, check = 0;
    int verified;
    bool val = false;

    do {
        if (check == 0) {
            printf("Number station: ");
        } else {
            printf("New number station: ");
        }

        scanf("%hu", &numbSta);
        limparBufferEntradaDados();
        verified = verifyStaExist(stations, numbSta);
        check = 1;
        if (verified == 0) {
            if (numbSta > STA_INIT && numbSta < STA_NUMB_MAX) {
                stations[verified].number = numbSta;
                val = true;
            } else {
                val = false;
            }
        } else
            printf("Number of station in used %c", NEWLINE);

    } while (val == false);

    return stations[STA_SIZE];
}

Station getSensors(Station station) {

    int i;
    char sensors;

    do {
        printf("Sensor of TEMPERATURE? Y/N ");
        scanf("%d", &i);
        
    } while (i == 1 || i == 2);
    if (i == 1) {
        station.sensors[0] = true;
        printf("Sensor Temperatura Validado");
    } else {
        station.sensors[0] = false;
        printf(" merda");
    }
    do {
        printf("Sensor of PRECIPITATION? Y/N ");
        scanf("%c", &sensors);
        limparBufferEntradaDados();
    } while (sensors != 'Y' || sensors != 'N');
    if (sensors == 'Y')
        station.sensors[1] = true;
    else
        station.sensors[1] = false;
    limparBufferEntradaDados();
    do {
        printf("Sensor of WINDSPEED? Y/N ");
        scanf("%c", sensors);
    } while (sensors != 'Y' || sensors != 'N');
    if (sensors == 'Y')
        station.sensors[2] = true;
    else
        station.sensors[2] = false;
    limparBufferEntradaDados();

    do {
        printf("Sensor of WINDDIRECTION? Y/N");
        scanf("%c", sensors);
    } while (sensors != 'Y' || sensors != 'N');
    if (sensors == 'Y')
        station.sensors[3] = true;
    else
        station.sensors[3] = false;
    limparBufferEntradaDados();

    do {
        printf("Sensor of CLOUDINESS Y/N");
        scanf("%c", sensors);
    } while (sensors != 'Y' || sensors != 'N');
    if (sensors == 'Y')
        station.sensors[4] = true;
    else
        station.sensors[4] = false;
    limparBufferEntradaDados();

    return station;

}

Station getCoordinates(Station station) {

    bool val = false;




    do {
        printf("Insert Coordinates X: ");
        scanf("%f", &station.coordinatesX);
        limparBufferEntradaDados();
        if (station.coordinatesX >= -180 && station.coordinatesX <= 180)
            val = true;
        else
            val = false;

    } while (val == false);

    bool val2 = false;


    do {
        printf("Insert Coordinates Y:");
        scanf("%f", &station.coordinatesY);
        limparBufferEntradaDados();
        if (station.coordinatesY >= -180 && station.coordinatesY <= 180) {
            val2 = true;
        } else {
            val2 = false;
        }
    } while (val2 == false);

    return station;
} //** Resolver problema, aceita letras! 

Station addStation(Station stations[], int position) {

    stations[position] = getNumberStation(stations);
    stations[position].general = getName(stations[position].general);
    stations[position].general = getAddress(stations[position].general);
    stations[position] = getCoordinates(stations[position]);
    stations[position].general = getPhone(stations[position].general);
    stations[position].general = getLevel(stations[position].general);
    stations[position].contMeasurements = 0;
    stations[position] = getSensors(stations[position]);

    return stations[STA_SIZE];
}

Station modifyStation(Station station, int modOpt) {

    if (modOpt == 1) {
        station.general = getName(station.general);
    } else if (modOpt == 2) {
        station.general.address = getStreetName(station.general.address);
    } else if (modOpt == 3) {
        station.general.address = getNumber(station.general.address);
    } else if (modOpt == 4) {
        station.general.address = getPostalCode(station.general.address);
    } else if (modOpt == 5) {
        station.general.address = getCity(station.general.address);
    } else if (modOpt == 6) {
        station.general = getPhone(station.general);
    } else if (modOpt == 7) {
        station.general = getLevel(station.general);
    }

    return station;
}

/*
Station modifyStation(Station station[], unsigned short int staNumb) {

    int op;

    do {
        /// TESTE  printf("%hu\n", staNumb);
        printf("what you want to change? %c", NEWLINE);
        printf("1-Address %c", NEWLINE);
        printf("2-Name %c", NEWLINE);
        printf("3-Coordinates %c", NEWLINE);
        printf("4-Phone %c", NEWLINE);
        printf("5-Sensors %c", NEWLINE);
        printf("6-Exit %c", NEWLINE);
        printf("Option: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                station[staNumb].general = getAddress(station[staNumb].general);
                break;
            case 2:
                station[staNumb].general = getName(station[staNumb].general);
                break;
            case 3:
                station[staNumb] = getCoordinates(station[staNumb]);
                break;
            case 4:
                station[staNumb].general = getPhone(station[staNumb].general);
                break;
            case 5:
                //station[staNumb].sensors = getSensors(station[staNumb].sensors);
                break;
        }
    } while (op != 1 || op != 2 || op != 3 || op != 4 || op != 5 || op != 6);

    return station[staNumb];


}
 */

/*

Station modiStation(Station station[], unsigned short int numbSta) {

    unsigned short int position;

    position = numbSta - 1;

    if (station[position].number == numbSta)
        modifyStation(station, position);
    else
        printf("Station does not exist! %c", NEWLINE);

    return station[STA_SIZE];
}
 */

Station removeStation(Station stations[], unsigned short int number) {
    int i;

    for (i = 0; i < STA_SIZE; i++) {
        if (stations[i].number == number) {
            if (stations[i].contMeasurements == 0) {
                stations[i].number = 0;
                printf("Station number %hu deleted.", number);
                return stations[STA_SIZE];
            }
        }
        printf("Station number %hu not fund.", number);
    }

}

void listStations(Station stations[]) {
    int i;

    for (i = 0; i < STA_SIZE && stations[i].number != 0; i++) {
        printf("%d - %hu - %s %c", i, stations[i].number, stations[i].general.name, NEWLINE);
    }
}

/*
 * Altera durante a tarde, fazer parte dos sensores
 * Parte de verificar e pensar no restante
 */


Station iniStation(Station station[]) {

    int i;
    for (i = 0; i < STA_SIZE; i++) {
        station[i].number = STA_INIT;
    }

    return station[STA_SIZE];
}

void createStationFile(Station stations[]) {

    FILE *pStation = fopen("Stations", "w");
    if (pStation == (FILE *) NULL) {
        puts("Couldn't create file.");
    } else {
        fwrite(stations, sizeof (Station), STA_SIZE, pStation);
        fclose(pStation);
    }
}

Station initStationFile(Station stations[]) {
    int i;

    for (i = 0; i < STA_SIZE; i++) {
        stations[i].number = 0;
    }
    return stations[STA_SIZE];
}

Station readStationFile(Station stations[]) {

    FILE *pStation = fopen("Stations", "r");
    if (pStation == (FILE *) NULL) {
        puts("File doesn't exist");
        puts("Creating file now...");
        createStationFile(stations);
        stations[STA_SIZE] = initStationFile(stations);
        puts("File created.");
        readStationFile(stations);
    } else {
        fread(stations, sizeof (Station), STA_SIZE, pStation);
        fclose(pStation);
    }
}

void saveStationFile(Station stations[]) {

    FILE *pStation = fopen("Stations", "w");
    if (pStation == (FILE *) NULL) {
        puts("File doesn't exist.");
        puts("Couldn't save.");
    } else {
        fwrite(stations, sizeof (Station), STA_SIZE, pStation);
        puts("File saved.");
        fclose(pStation);
    }
}

