#include "../nmea/parser_types.h"
#include "iimwv.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_IIMWV);
	NMEA_PARSER_PREFIX(parser, "IIMWV");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_iimwv_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_iimwv_s));
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
	nmea_iimwv_s *data = (nmea_iimwv_s *) parser->data;
        
	switch (val_index) {
	case NMEA_IIMWV_WINDHEADING:
                data->wind_heading = strtod(value, NULL);
		break;
	case NMEA_IIMWV_RELORTRUE:
                data->rel_true = *value;
		break;
	case NMEA_IIMWV_WINDSPEED:
                data->wind_speed = strtod(value, NULL);
		break;
	case NMEA_IIMWV_SPEEDUNITS:
                data->speed_units = *value;
		break;
	case NMEA_IIMWV_DATAVALID:
                data->data_valid = *value;
		break;

	default:
		break;
	}

	return 0;
}
