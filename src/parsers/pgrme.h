#ifndef INC_NMEA_PGRME_H
#define INC_NMEA_PGRME_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double horiz_error;
	double vert_error;
	double spherical_position_error;
} nmea_pgrme_s;

/* Value indexes */
#define NMEA_PGRME_HORIZ_ERROR	0
#define NMEA_PGRME_VERT_ERROR	2
#define NMEA_PGRME_SPHERICAL_ERROR	4

#endif  /* INC_NMEA_PGRME_H */
