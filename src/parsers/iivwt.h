#ifndef INC_NMEA_IIVWT_H
#define INC_NMEA_IIVWT_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	double truewinddir_mag_degs;
	char truewinddir;
	double truewindspd_kts;
} nmea_iivwt_s;

/* Value indexes */
#define NMEA_IIVWT_DIRMAG_DEGS	0
#define NMEA_IIVWT_DIR 1
#define NMEA_IIVWT_TRUEWINDSPD_KTS 2

#endif  /* INC_NMEA_IIVWT_H */
