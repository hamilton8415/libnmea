#ifndef INC_NMEA_IIHDM_H
#define INC_NMEA_IIHDM_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double heading_mag;
} nmea_iihdm_s;

/* Value indexes */
#define NMEA_IIHDM_HEADING_MAG	0

#endif  /* INC_NMEA_IIHDM_H */
