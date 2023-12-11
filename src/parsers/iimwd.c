#include "../nmea/parser_types.h"
#include "iimwd.h"
#include "parse.h"

int
init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_IIMWD);
	NMEA_PARSER_PREFIX(parser, "IIMWD");
	return 0;
}

int
allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof (nmea_iimwd_s));
	if (NULL == parser->data) {
		return -1;
	}

	return 0;
}

int
set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof (nmea_iimwd_s));
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
	nmea_iimwd_s *data = (nmea_iimwd_s *) parser->data;
        
	switch (val_index) {
	case NMEA_IIMWD_WINDDIR_TRUE:
                data->winddir_true = strtod(value, NULL);
		break;
	case NMEA_IIMWD_WINDDIR_MAG:
                data->winddir_mag = strtod(value, NULL);
		break;
	case NMEA_IIMWD_WINDSPEED_KTS:
                data->windspeed_kts = strtod(value, NULL);
		break;
	case NMEA_IIMWD_WINDSPEED_MPS:
                data->windspeed_mps = strtod(value, NULL);
		break;

	default:
		break;
	}

	return 0;
}
