#include "../nmea/parser_types.h"
#include "iivpw.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_IIVPW);
	NMEA_PARSER_PREFIX(parser, "IIVPW");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_iivpw_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_iivpw_s));
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
	nmea_iivpw_s *data = (nmea_iivpw_s *) parser->data;
	
	switch (val_index) {
	case NMEA_IIVPW_SPD_KTS:
                data->speed_paralleltowind_kts = strtod(value, NULL);
		break;
	case NMEA_IIVPW_SPD_MPS:
                data->speed_paralleltowind_mps = strtod(value, NULL);
		break;

	default:
		break;
	}

	return 0;
}
