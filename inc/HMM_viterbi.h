#ifndef __HMM_VITERBI_H
#define __HMM_VITERBI_H

typedef enum __weather
{
	weather_Rainy = 0,
	weather_Sunny,

	weather_MAX
}weather;

typedef enum __Activity
{
	Activity_walk = 0,
	Activity_shop,
	Activity_clean,

	Activity_MAX
}Activity;

#define show_status_LEN	(3)
#define hide_status_LEN	(2)

extern int Hmm_viterbi_compute(int *p_show_status,int show_status_len,int *p_hide_status,int hide_status_len,
		int *p_start_hide_probability,int start_hide_probability_len,
		int *p_hide_transititon_probability,
		int *p_hide_to_see_probability,
		int *p_result_status,int result_status_len);
#endif//__HMM_VITERBI_H
