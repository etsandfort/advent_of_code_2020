#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

#define arr_cnt( arr ) (sizeof(arr)/sizeof(arr[0]))
#define input_fil_path "C:\\Users\\etsan\\Documents\\GitHub\\advent_of_code_2020\\"

static void day1(int list[], int count);

static void parse_input(const char * name, int output[], int len, int * count);

int main( void )
{
	int d1input[1000];
	int d1len = 0;
	parse_input("day1.txt", d1input, arr_cnt(d1input), &d1len);
	day1(d1input, d1len);
	return(0);
}

static void parse_input(const char * name, int output[], int len, int * count)
{
	FILE *file;
	char filname[255];
	char line[255];

	sprintf_s(filname, "%s%s\0", input_fil_path, name);
	fopen_s(&file, filname, "r");

	while ( *count < len)
	{
		if (fgets(line, 255, file) != NULL)
		{
			output[*count] = atoi(line);
			*count = *count + 1;
		}
		else
		{
			break;
		}
	}
	fclose(file);

}


static void day1(int list[], int count)
{
#define target 2020
	int i, j;

	for (i = 0; i < count; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (list[i] + list[j] == target)
			{
				printf("%i", list[i] * list[j]);
			}
		}
	}
#undef target
}