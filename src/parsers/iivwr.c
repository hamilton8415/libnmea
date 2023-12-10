#include "../nmea/parser_types.h"
#include "iivwr.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_IIVWR);
	NMEA_PARSER_PREFIX(parser, "IIVWR");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_iivwr_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_iivwr_s));
	return 0;
}

int
free_data(nmea_s *data)
{
	free(data);
	return 0;
}

int
parse(nmea_parser_s *parser, char *value, int val_index)
{
	nmea_iivwr_s *data = (nmea_iivwr_s *) parser->data;
	
	switch (val_index) {
	case NMEA_IIVWR_DIRMAG_DEGS:
                data->appwinddir_mag_degs = strtod(value, NULL);
		break;
	case NMEA_IIVWR_DIR: 
                data->appwinddir = *value;
		break;
	case NMEA_IIVWR_APPWINDSPD_KTS:
                data->appwindspd_kts = strtod(value, NULL);
		break;

	default:
		break;
	}

	return 0;
}
