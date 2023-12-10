#ifndef INC_NMEA_IIVWR_H
#define INC_NMEA_IIVWR_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double appwinddir_mag_degs;
	char appwinddir;
	double appwindspd_kts;
} nmea_iivwr_s;

/* Value indexes */
#define NMEA_IIVWR_DIRMAG_DEGS	0
#define NMEA_IIVWR_DIR 1
#define NMEA_IIVWR_APPWINDSPD_KTS 2

#endif  /* INC_NMEA_IIVWR_H */
