#include "../nmea/parser_types.h"
#include "idhdm.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_IIHDM);
	NMEA_PARSER_PREFIX(parser, "IIHDM");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_idhdm_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_idhdm_s));
	// Set the default undulation to an invalid value
	nmea_idhdm_s *data = (nmea_idhdm_s *) parser->data;
	data->mode = 'N';
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
	nmea_idhdm_s *data = (nmea_idhdm_s *) parser->data;

	switch (val_index) {
	case NMEA_IIHDM_HEADING_MAG:
                data->heading_mag = strtod(value, NULL);
		break;

	default:
		break;
	}

	return 0;
}
