#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

#define arr_cnt( arr ) (sizeof(arr)/sizeof(arr[0]))
#define input_fil_path "C:\\Users\\etsan\\Documents\\GitHub\\advent_of_code_2020\\"

static void day1(int list[], int count);
static void day2(void);


static void parse_input_int(const char * name, int output[], int len, int * count);

int main( void )
{
	//int d1input[1000];
	//int d1len = 0;
	//parse_input_int("day1.txt", d1input, arr_cnt(d1input), &d1len);
	//day1(d1input, d1len);

	day2();

	return(0);
}

static void parse_input_int(const char * name, int output[], int len, int * count)
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
	int i, j, k;

	for (i = 0; i < count; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			for (k = j + 1; k < count; k++)
			{
				if (list[i] + list[j] + list[k] == target)
				{
					printf("%i", list[i] * list[j] * list[k]);
				}
			}
		}
	}
#undef target
}

static void day2(void)
{
	FILE *file;
	char line[255];
	char target;
	char substr[255];
	int i;
	int cnt;
	int min, max;

	int valid = 0;

	fopen_s(&file, input_fil_path"day2.txt", "r");

	while (1)
	{

		if (fgets(line, 255, file) != NULL)
		{
			i = 0;
			cnt = 0;
			while (line[i] != '-')
			{
				cnt++;
				i++;
			}
			strncpy_s(substr, &line[0], cnt * sizeof(char));
			min = atoi(substr);

			i++;
			cnt = 0;
			while (line[i] != ' ')
			{
				cnt++;
				i++;
			}
			strncpy_s(substr, &line[i-cnt], cnt * sizeof(char));
			max = atoi(substr);


			cnt = 0;
			while (line[i] != ':')
			{
				i++;
			}
			target = line[i - 1];

			strncpy_s(substr, &line[i + 2], (255 - (i + 2)) * sizeof(char));

			i = 0;
			cnt = 0;

			while (substr[i] != '\0' )
			{
				cnt += (substr[i] == target);
				i++;
			}

			valid += (cnt >= min && cnt <= max);
		}
		else
		{
			break;
		}
	}
	fclose(file);

	printf("%i", valid);
}

