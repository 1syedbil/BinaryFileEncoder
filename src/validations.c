#include "functions.h"

int validateCmdLine(int argc, char* argv[])
{
	int check = 0;

	char* curSwitch = argv[0];

	char help[3] = "-h";
	char srec[6] = "-srec";

	bool stdInput = true;
	bool stdOutput = true;
	bool isSrec = false;

	if (argc > 5)
	{
		return ERROR_EXIT;
	}

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], srec) == 0)
		{
			if (!isSrec)
			{
				isSrec = true;
				continue;
			}

			return ERROR_EXIT;
		}

		if (strcmp(argv[i], help) == 0)
		{
			return HELP;
		}

		check = checkSwitch(argv[i]);

		if (check == 1)
		{
			if (stdInput)
			{
				stdInput = false;
				continue;
			}

			return ERROR_EXIT;
		}

		if (check == 2)
		{
			if (stdOutput)
			{
				stdOutput = false;
				continue;
			}

			return ERROR_EXIT;
		}

		if (check == 0)
		{
			return ERROR_EXIT;
		}
	}

	if (!stdInput && !stdOutput && !isSrec)
	{
		return FILE_TO_FILE;
	}
	if (!stdInput && !stdOutput && isSrec)
	{
		return FILE_TO_SREC_FILE;
	}
	if (stdInput && stdOutput && !isSrec)
	{
		return STDIN_TO_STDOUT;
	}
	if (stdInput && stdOutput && isSrec)
	{
		return STDIN_TO_SREC_STDOUT;
	}
	if (!stdInput && stdOutput && !isSrec)
	{
		return FILE_TO_DEF_FILE;
	}
	if (!stdInput && stdOutput && isSrec)
	{
		return FILE_TO_DEF_SREC_FILE;
	}
	if (stdInput && !stdOutput && !isSrec)
	{
		return STDIN_TO_FILE;
	}
	if (stdInput && !stdOutput && isSrec)
	{
		return STDIN_TO_SREC_FILE;
	}

	return ERROR_EXIT;
}


int checkSwitch(char* str)
{
	char input[3] = "-i";
	char output[3] = "-o";
	char curSwitch[3] = "";

	for (int i = 0; i < strlen(input); i++)
	{
		curSwitch[i] = str[i];
	}
	curSwitch[strlen(input)] = '\0';

	if (strcmp(curSwitch, input) == 0)
	{
		return 1;
	}

	if (strcmp(curSwitch, output) == 0)
	{
		return 2;
	}

	return 0;
}


char* getFileName(char* argv[], int choice)
{
	char fileName[MAX_STRING] = "";
	char* fileNamePtr = malloc(MAX_STRING);
	char* arg = malloc(MAX_STRING);

	int index = 2;
	int counter = 0;

	switch (choice)
	{
		case INPUT_NAME:
		arg = retrieveArg(argv, INPUT_NAME);
		for (; index < strlen(arg); index++)
		{
			fileName[counter] = arg[index];
			counter++;
		}
		strcpy(fileNamePtr, fileName);
		break;

		case OUTPUT_NAME:
		arg = retrieveArg(argv, OUTPUT_NAME);
                for (; index < strlen(arg); index++)
                {
                        fileName[counter] = arg[index];
                        counter++;
                }
                strcpy(fileNamePtr, fileName);
                break;

		case OUTPUT_ASM_NAME:
		arg = retrieveArg(argv, INPUT_NAME);
                for (; index < strlen(arg); index++)
                {
                        fileName[counter] = arg[index];
                        counter++;
                }
                strcat(fileName, ".asm");
		strcpy(fileNamePtr, fileName);
                break;

		case OUTPUT_SREC_NAME:
		arg = retrieveArg(argv, INPUT_NAME);
                for (; index < strlen(arg); index++)
                {
                        fileName[counter] = arg[index];
                        counter++;
                }
                strcat(fileName, ".srec");
                strcpy(fileNamePtr, fileName);
                break;
	}

	return fileNamePtr;
}


char* retrieveArg(char* argv[], int choice)
{
	if (choice == INPUT_NAME)
	{
		for (int i = 0; argv[i] != NULL; i++)
		{
			if (checkSwitch(argv[i]) == 1)
			{
				return argv[i];
			}
		}
	}
	else if (choice == OUTPUT_NAME)
	{
		for (int j = 0; argv[j] != NULL; j++)
		{
			if (checkSwitch(argv[j]) == 2)
			{
				return argv[j];
			}
		}
	}

	return NULL;
}
