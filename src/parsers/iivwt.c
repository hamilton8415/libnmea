#include "../nmea/parser_types.h"
#include "iivwt.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_IIVWT);
	NMEA_PARSER_PREFIX(parser, "IIVWT");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_iivwt_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_iivwt_s));
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
	nmea_iivwt_s *data = (nmea_iivwt_s *) parser->data;
	
	switch (val_index) {
	case NMEA_IIVWT_DIRMAG_DEGS:
                data->truewinddir_mag_degs = strtod(value, NULL);
		break;
	case NMEA_IIVWT_DIR: 
                data->truewinddir = *value;
		break;
	case NMEA_IIVWT_TRUEWINDSPD_KTS:
                data->truewindspd_kts = strtod(value, NULL);
		break;

	default:
		break;
	}

	return 0;
}
