#include "functions.h"

int main(int argc, char* argv[])
{
	int action = validateCmdLine(argc, argv);
	char* input = NULL;
	char* output = NULL;

	switch(action)
	{
		case ERROR_EXIT:
		break;

		case HELP:
		printf("Usage message.\n");
		break;

		case FILE_TO_FILE:
		input = getFileName(argv, INPUT_NAME);
                output = getFileName(argv, OUTPUT_NAME);

                printf("Input: %s\nOutput: %s\n", input, output);
		//encodeToAsm(input, output);
		break;

		case FILE_TO_SREC_FILE:
		input = getFileName(argv, INPUT_NAME);
		output = getFileName(argv, OUTPUT_NAME);

		encodeToSrec(input, output);
		break;

		case FILE_TO_DEF_FILE:
		input = getFileName(argv, INPUT_NAME);
                output = getFileName(argv, OUTPUT_ASM_NAME);

                printf("Input: %s\nOutput: %s\n", input, output);
		//encodeToAsm(input, output);
		break;

		case FILE_TO_DEF_SREC_FILE:
		input = getFileName(argv, INPUT_NAME);
		output = getFileName(argv, OUTPUT_SREC_NAME);

		encodeToSrec(input, output);
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

	free(input);
	free(output);

	return 0;
}
