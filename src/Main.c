/*
 ============================================================================
 Name        : Main.c
 Author      : liufuliang
 Version     :
 Copyright   : Liu Fu Liang
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "HMM_viterbi.h"
//π€≤‚–Ú¡–
static Activity show_status[show_status_LEN] =
{
	Activity_walk,
	Activity_shop,
	Activity_clean,
};

static weather hide_status[hide_status_LEN] =
{
	weather_Rainy,
	weather_Sunny,
};

static double start_hide_probability[weather_MAX] =
{
	0.6,
	0.4
};

static double hide_transititon_probability[weather_MAX][weather_MAX] =
{
	{0.7,0.3},
	{0.4,0.6},
};

static double hide_to_see_probability[weather_MAX][Activity_MAX] =
{
	{0.1,0.4,0.5},
	{0.6,0.3,0.1},
};

static int result_path[show_status_LEN] = {0};

void printf_weather(int index,int value)
{
	switch(value)
	{
		case weather_Rainy:
		{
			printf("\n HMM viterbi result[%d] = Rainy",index);
			fflush(stdout);
		}
		break;
		case weather_Sunny:
		{
			printf("\n HMM viterbi result[%d] = Sunny",index);
			fflush(stdout);
		}
		break;
	}

}

int main(void) {
	int ret = -1;
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	fflush(stdout);

	ret = Hmm_viterbi_compute(show_status,show_status_LEN,hide_status,hide_status_LEN,
			start_hide_probability,weather_MAX,
			hide_transititon_probability,
			hide_to_see_probability,
			result_path,show_status_LEN);

	if(ret == 0)
	{
		int i = 0;
		for(i = 0;i < show_status_LEN;i++)
		{
			printf_weather(i,result_path[i]);
		}
	}

	puts("\n !!!Hello World!!!"); /* prints !!!Hello World!!! */
	fflush(stdout);

	return EXIT_SUCCESS;
}
