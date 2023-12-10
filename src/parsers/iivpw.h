#ifndef INC_NMEA_IIVPW_H
#define INC_NMEA_IIVPW_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double speed_paralleltowind_kts;
	double speed_paralleltowind_mps;
} nmea_iivpw_s;

/* Value indexes */
#define NMEA_IIVPW_SPD_KTS	0
#define NMEA_IIVPW_SPD_MPS	2

#endif  /* INC_NMEA_IIVPW_H */
