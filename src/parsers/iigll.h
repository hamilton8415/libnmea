#ifndef INC_NMEA_IIGLL_H
#define INC_NMEA_IIGLL_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	nmea_position longitude;
	nmea_position latitude;
	struct tm time;
} nmea_iigll_s;

/* Value indexes */
#define NMEA_IIGLL_LATITUDE		0
#define NMEA_IIGLL_LATITUDE_CARDINAL	1
#define NMEA_IIGLL_LONGITUDE		2
#define NMEA_IIGLL_LONGITUDE_CARDINAL	3
#define NMEA_IIGLL_TIME			4

#endif  /* INC_NMEA_IIGLL_H */
