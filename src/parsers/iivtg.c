#include "../nmea/parser_types.h"
#include "iivtg.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_IIVTG);
	NMEA_PARSER_PREFIX(parser, "IIVTG");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_iivtg_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_iivtg_s));
	// Set the default undulation to an invalid value
	nmea_iivtg_s *data = (nmea_iivtg_s *) parser->data;
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
	nmea_iivtg_s *data = (nmea_iivtg_s *) parser->data;

	switch (val_index) {
	case NMEA_IIVTG_TRACKMADEGOOO_TRUE:
                data->trackmadegood_true = strtod(value, NULL);
		break;

	case NMEA_IIVTG_TRACKMADEGOOO_MAGNETIC:
                data->trackmadegood_mag = strtod(value, NULL);
                break;	

	case NMEA_IIVTG_SPEEDKTS:
                data->speed_kts = strtod(value, NULL);
                break;	

	case NMEA_IIVTG_SPEEDKPH:
                data->speed_kph = strtod(value, NULL);
                break;	

	case NMEA_IIVTG_MODEINDICATOR:
                data->mode = *value;
                break;	

	default:
		break;
	}

	return 0;
}
