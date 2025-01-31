#include "functions.h"

int main(int argc, char* argv[])
{
	int action = validateCmdLine(argc, argv);

	switch(action)
	{
		case ERROR_EXIT:
		break;

		case HELP:
		printf("Usage message.\n");
		break;

		case FILE_TO_FILE:
		printf("Encode specified input file to specified asm output file.\n");
		break;

		case FILE_TO_SREC_FILE:
		printf("Encode specified input file to specified srec output file.\n");
		break;

		case FILE_TO_DEF_FILE:
		printf("Encode specified input file to default asm output file.\n");
		break;

		case FILE_TO_DEF_SREC_FILE:
		printf("Encode specified input file to default srec output file.\n");
		break;

		case STDIN_TO_FILE:
		printf("Encode from standard input to specified asm output file.\n");
		break;

		case STDIN_TO_SREC_FILE:
		printf("Encode from standard input to specified srec output file.\n");
		break;

		case STDIN_TO_STDOUT:
		printf("Encode from standard input to standard output asm format.\n");
		break;

		case STDIN_TO_SREC_STDOUT:
		printf("Encode from standard input to standard output srec format.\n");
		break;

		default:
		break;
	}

	return 0;
}
