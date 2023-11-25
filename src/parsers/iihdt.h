#ifndef INC_NMEA_IIHDT_H
#define INC_NMEA_IIHDT_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double heading_true;
} nmea_iihdt_s;

/* Value indexes */
#define NMEA_IIHDT_HEADING_TRUE	0

#endif  /* INC_NMEA_IIHDT_H */
