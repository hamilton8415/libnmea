#ifndef INC_NMEA_IIMWD_H
#define INC_NMEA_IIMWD_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double winddir_true;
	double winddir_mag;
	double windspeed_kts;
	double windspeed_mps;
} nmea_iimwd_s;

/* Value indexes */
#define NMEA_IIMWD_WINDDIR_TRUE	0
#define NMEA_IIMWD_WINDDIR_MAG	2
#define NMEA_IIMWD_WINDSPEED_KTS	4
#define NMEA_IIMWD_WINDSPEED_MPS 	6

#endif  /* INC_NMEA_IIMWD_H */
