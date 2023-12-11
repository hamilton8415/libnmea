#include "../nmea/parser_types.h"
#include "pgrme.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_PGRME);
	NMEA_PARSER_PREFIX(parser, "PGRME");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_pgrme_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_pgrme_s));
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
	nmea_pgrme_s *data = (nmea_pgrme_s *) parser->data;
        
	switch (val_index) {
	  case NMEA_PGRME_HORIZ_ERROR:
                data->horiz_error = strtod(value, NULL);
		break;
	  case NMEA_PGRME_VERT_ERROR:
                data->vert_error = strtod(value, NULL);
		break;
	  case NMEA_PGRME_SPHERICAL_ERROR:
                data->spherical_position_error = strtod(value, NULL);
		break;

	default:
		break;
	}

	return 0;
}
