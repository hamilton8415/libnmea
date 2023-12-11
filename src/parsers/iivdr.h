#ifndef INC_NMEA_IIVDR_H
#define INC_NMEA_IIVDR_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double currdir_true;
	double currdir_mag;
	double currspeed_kts; 
} nmea_iivdr_s;

/* Value indexes */
#define NMEA_IIVDR_CURRDIR_TRUE	0
#define NMEA_IIVDR_CURRDIR_MAG	2
#define NMEA_IIVDR_CURRSPEED	4

#endif  /* INC_NMEA_IIVDR_H */
