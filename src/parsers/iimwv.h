#ifndef INC_NMEA_IIMWV_H
#define INC_NMEA_IIMWV_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double wind_heading;
	char rel_true;
	double wind_speed;
	char speed_units;
	char data_valid;
} nmea_iimwv_s;

/* Value indexes */
#define NMEA_IIMWV_WINDHEADING	0
#define NMEA_IIMWV_RELORTRUE	1
#define NMEA_IIMWV_WINDSPEED	2
#define NMEA_IIMWV_SPEEDUNITS 	3
#define NMEA_IIMWV_DATAVALID	4

#endif  /* INC_NMEA_IIMWV_H */
