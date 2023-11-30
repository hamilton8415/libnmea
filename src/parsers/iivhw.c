#include "../nmea/parser_types.h"
#include "iivhw.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_IIVHW);
	NMEA_PARSER_PREFIX(parser, "IIVHW");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_iivhw_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_iivhw_s));
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
	nmea_iivhw_s *data = (nmea_iivhw_s *) parser->data;

	switch (val_index) {
	case NMEA_IIVHW_HEADING_RELWATER_TRUE:
                data->heading_relwater_true = strtod(value, NULL);
		break;
	case NMEA_IIVHW_HEADING_RELWATER_MAG:
                data->heading_relwater_mag = strtod(value, NULL);
		break;
	case NMEA_IIVHW_SPEED_RELWATER_KTS:
                data->speed_relwater_kts = strtod(value, NULL);
		break;
	case NMEA_IIVHW_SPEED_RELWATER_KPH:
                data->speed_relwater_kph = strtod(value, NULL);
		break;

	default:
		break;
	}

	return 0;
}
