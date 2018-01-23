/*
 ============================================================================
 Name        : HMM_viterbi.c
 Author      : liufuliang
 Version     :
 Copyright   : Liu Fu Liang
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "HMM_viterbi.h"


int Hmm_viterbi_compute(int *p_show_status,int show_status_len,int *p_hide_status,int hide_status_len,
											int *p_start_hide_probability,int start_hide_probability_len,
											int *p_hide_transititon_probability,
											int *p_hide_to_see_probability,
											int *p_result_status,int result_status_len)
{
	double show_hide_status_probability[show_status_LEN][hide_status_LEN] = {0};
	int hide_show_status[hide_status_LEN][show_status_LEN] = {0};
	int i,j,k;
	double temp[hide_status_LEN],tmp;



	//��ʼ��	weather_Rainy,	weather_Sunny,
	for(i = 0;i < hide_status_len;i++)
	{
		show_hide_status_probability[0][i] = p_start_hide_probability[i] * p_hide_to_see_probability[i * Activity_MAX + p_show_status[0]];

		hide_show_status[i][0] = i;

		temp[i] = p_start_hide_probability[i];
	}

	//	Activity_walk,	Activity_shop,	Activity_clean,
	for(i = 1;i < show_status_LEN;i++)
	{

			double temp1[hide_status_LEN] = {0.0};
			//weather_Rainy,	weather_Sunny,
			for(j = 0;j < hide_status_len;j++)
			{
					double temp0;
					//weather_Rainy,	weather_Sunny,
					for(k = 0;k < hide_status_len;k++)
					{
							//����Y = ǰһ�������X���� * Xת�Ƶ�Yd�ĸ��� * Y�����½��л�ĸ���
							temp0 = show_hide_status_probability[i - 1][k] * p_hide_transititon_probability[k * weather_MAX + j] * p_hide_to_see_probability[j * Activity_MAX + i];

							if(temp1[j] < temp0)
							{
								temp1[j] = temp0;

								show_hide_status_probability[i][j] = temp0;

								hide_show_status[k][i] = k;
							}
					}

			}

	}

	//�Ƚ����һ����������һ������ĸ���,�ҳ��ϴ����һ������,�������յĽ��
	i = 0;
	tmp = 0.0;
	for(k = 0;k < hide_status_len;k++)
	{
		if(show_hide_status_probability[show_status_LEN - 1][k] > tmp)
		{
			tmp = show_hide_status_probability[show_status_LEN - 1][k];
			i = k;
		}
	}

	//������
	if(result_status_len == show_status_LEN)
	{
		for(k = 0;k < show_status_LEN;k++)
		{
			p_result_status[k] = hide_show_status[i][k];

		}
	}
	else
	{
			return -1;
	}

	return 0;

}



