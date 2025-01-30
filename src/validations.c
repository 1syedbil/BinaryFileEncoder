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
