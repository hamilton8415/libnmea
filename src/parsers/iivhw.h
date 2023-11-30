#ifndef INC_NMEA_IIVHW_H
#define INC_NMEA_IIVHW_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double heading_relwater_true;
	double heading_relwater_mag;
	double speed_relwater_kts;
	double speed_relwater_kph;
} nmea_iivhw_s;

/* Value indexes */
#define NMEA_IIVHW_HEADING_RELWATER_TRUE	0
#define NMEA_IIVHW_HEADING_RELWATER_MAG	2
#define NMEA_IIVHW_SPEED_RELWATER_KTS	4
#define NMEA_IIVHW_SPEED_RELWATER_KPH	6

#endif  /* INC_NMEA_IIVHW_H */
