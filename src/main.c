#include "functions.h"

int main(int argc, char* argv[])
{
	int action = validateCmdLine(argc, argv);

	switch(action)
	{
		case ERROR_EXIT:
		return ERROR_EXIT;

		case HELP:
		printf("Usage message.\n");
		return HELP;

		case FILE_TO_FILE:
		printf("Encode specified input file to specified asm output file.\n");
		return FILE_TO_FILE;

		case FILE_TO_SREC_FILE:
		printf("Encode specified input file to specified srec output file.\n");
		return FILE_TO_SREC_FILE;

		case FILE_TO_DEF_FILE:
		printf("Encode specified input file to default asm output file.\n");
		return FILE_TO_DEF_FILE;

		case FILE_TO_DEF_SREC_FILE:
		printf("Encode specified input file to default srec output file.\n");
		return FILE_TO_DEF_SREC_FILE;

		case STDIN_TO_FILE:
		printf("Encode from standard input to specified asm output file.\n");
		return STDIN_TO_FILE;

		case STDIN_TO_SREC_FILE:
		printf("Encode from standard input to specified srec output file.\n");
		return STDIN_TO_SREC_FILE;

		case STDIN_TO_STDOUT:
		printf("Encode from standard input to standard output asm format.\n");
		return STDIN_TO_STDOUT;

		case STDIN_TO_SREC_STDOUT:
		printf("Encode from standard input to standard output srec format.\n");
		return STDIN_TO_SREC_STDOUT;

		default:
		break;
	}

	return 0;
}
