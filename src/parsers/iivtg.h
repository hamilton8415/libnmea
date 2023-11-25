#ifndef INC_NMEA_IIVTG_H
#define INC_NMEA_IIVTG_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double trackmadegood_true;
	double trackmadegood_mag;
	double speed_kts;
	double speed_kph;
        char mode;	
	/* sentence values */
} nmea_iivtg_s;

/* Value indexes */
#define NMEA_IIVTG_TRACKMADEGOOD_TRUE	0
#define NMEA_IIVTG_TRACKMADEGOOD_TRUEDIRBASIS  	1
#define NMEA_IIVTG_TRACKMADEGOOD_MAGNETIC  	2
#define NMEA_IIVTG_TRACKMADEGOOD_MAGDIRBASIS  	3
#define NMEA_IIVTG_SPEEDKTS	  	4
#define NMEA_IIVTG_SPEEDKTS_UNITS  	5
#define NMEA_IIVTG_SPEEDKPH  	6
#define NMEA_IIVTG_SPEEDKPH_UNITS  	7
#define NMEA_IIVTG_MODEINDICATOR  	8

#endif  /* INC_NMEA_IIVTG_H */
