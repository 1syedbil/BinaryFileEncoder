#include "functions.h"


void encodeToSrec(char* input, char* output)
{
	char* stdInput = "stdin";
	char* stdOutput = "stdout";
	bool usingStdin = true;
	bool usingStdout = true;
	int recCounter = 0;
	int sum = 0;
	int count = 0;

	FILE* inputFile = NULL;
	FILE* outputFile = NULL;

	char s0[MAX_SREC] = "S0";
	char s1[MAX_SREC] = "S1";
	char s5[MAX_SREC] = "S5";
	char s9[MAX_SREC] = "S9";

	char byte[MAX_STRING] = "";
	char byteCount[MAX_STRING] = "";
	char address[MAX_STRING] = "";
	char checkSum[MAX_STRING] = "";

	unsigned char data[S1_DATA_SIZE];

	if (strcmp(input, stdInput) != 0)
	{
		usingStdin = false;
		inputFile = fopen(input, "rb");
		if (inputFile == NULL)
		{
			perror("could not open input file.\n");
			return;
		}
	}
	if (strcmp(output, stdOutput) != 0)
	{
		usingStdout = false;
		outputFile = fopen(output, "a");
		if (outputFile == NULL)
		{
			perror("could not open output file.\n");
			return;
		}
	}

	if (!usingStdin && !usingStdout)
	{
		char* str = createS0(s0);
		strcpy(s0, str);
		fprintf(outputFile, "%s\n", s0);

		int bytesRead = 0;

		while ((bytesRead = fread(data, sizeof(unsigned char), S1_DATA_SIZE, inputFile)) > 0)
		{
			count = bytesRead + 3;

			sum = count + (recCounter * S1_DATA_SIZE);

			sprintf(byteCount, "%02X", count);
			sprintf(address, "%04X", recCounter * S1_DATA_SIZE);

			strcat(s1, byteCount);
			strcat(s1, address);

			for (int i = 0; i < bytesRead; i++)
			{
				sprintf(byte, "%02X", (int)data[i]);

				strcat(s1, byte);

				sum += (int)data[i];
			}

			sum = getCheckSum(sum);

			sprintf(checkSum, "%02X", sum);

			strcat(s1, checkSum);

			fprintf(outputFile, "%s\n", s1);

			strcpy(s1, "S1");

			recCounter++;
		}

		count = 3;

		sum = count + recCounter;
		sum = getCheckSum(sum);
		sprintf(checkSum, "%02X", sum);

		sprintf(byteCount, "%02X", count);
		strcat(s5, byteCount);

		sprintf(address, "%04X", recCounter);
		strcat(s5, address);

		strcat(s5, checkSum);

		fprintf(outputFile, "%s\n", s5);

		sum = count;
		sum = getCheckSum(sum);
		sprintf(checkSum, "%02X", sum);

		sprintf(byteCount, "%02x", count);
		strcat(s9, byteCount);

		sprintf(address, "%04X", 0);
		strcat(s9, address);

		strcat(s9, checkSum);

		fprintf(outputFile, "%s\n", s9);

		free(str);
	}
	else if (usingStdin && !usingStdout)
	{
	}
	else if (usingStdin && usingStdout)
	{
	}

	if (fclose(inputFile) != 0)
	{
		perror("could not close the input file.\n");
	}
	if (fclose(outputFile) != 0)
	{
		perror("could not close the output file.\n");
	}
}


char* createS0(char s0[MAX_SREC])
{
	char address[5] = "";
	char count[3] = "";
	char data[3] = "";
	char mm[3] = "";
	char name[6] = "BILAL";
	char* record = malloc(MAX_SREC);
	if (record == NULL)
	{
		return NULL;
	}

	int sum = 0 + S0_COUNT;

	sprintf(address, "%04X", 0);
	sprintf(count, "%02X", S0_COUNT);

	strcat(s0, count);
	strcat(s0, address);

	for (int i = 0; i < strlen(name); i++)
	{
		sprintf(data, "%02X", (int)name[i]);
		strcat(s0, data);

		sum += (int)name[i];
	}

	int checkSum = getCheckSum(sum);

	sprintf(mm, "%02X", checkSum);

	strcat(s0, mm);

	strcpy(record, s0);

	return record;
}


int getCheckSum(int sum)
{
	int comp = ~sum;
	int lsb = comp & 0xFF;

	return lsb;
}
