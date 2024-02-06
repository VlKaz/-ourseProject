#include "temp_function.h"

int AddInfo(sensor* info, char filename[])
{
	int count = 0;
	int r;
	FILE *f;
	f = fopen(filename,"r");
	while((r = fscanf(f,"%hd;%hhd;%hhd;%hhd;%hhd;%hhd",&info[count].year, &info[count].month, &info[count].day, &info[count].hour, &info[count].minute, &info[count].t)) > 0)
	{
		if(r<6)
		{
			char s[30];
			r = fscanf(f, "%[^\n]", s);
			printf("=============================\n");
			printf("Error '%s' in line number \"%d\"\n", s, count);
			count--;
		}
	count++;
	}
	printf("=============================\n");
	return count;
}

void Print(sensor* info,int number)
{
	printf("\n");
	printf("#       |  Date     |  Time   | Temp\n");
	printf("======================================\n");
	for (int i = 0; i < number; i++)
		printf("%d\t|%04d-%02d-%02d | %02d : %02d | t=%d\n", i, info[i].year, info[i].month, info[i].day, info[i].hour, info[i].minute, info[i].t);
}

void InfoByMonth(sensor* info, int number, int m)
{
	if(m <= 0 || m > 12)
	{
		printf("!!ERROR INCORRECT PARAMETER <-m>!!");
		return;
	}
	int count = 0;
	int tempArr[1000];
	int temp = 0;
	for(int i = 0; i < number; i++)
	{
			if(info[i].month == m)
			{
				tempArr[count] = info[i].t;
				temp += info[i].t;
				count++;
			}
	}
	int max = tempArr[0];
	int min = tempArr[0];
	for(int i = 0; i < count; i++)
	{
		if(max < tempArr[i])
			max = tempArr[i];
		if(min > tempArr[i])
			min = tempArr[i];
	}
	printf("______________________________________________________________________________\n");
	printf("Month %02d | NumRec = %02d | MonthAvg = %4d | MonthMin = %4d  | MonthMax = %4d\n",m,count,temp/count,min,max);
	printf("______________________________________________________________________________\n");
}

void InfoByYear(sensor* info, int number)
{
	int maxYear = info[0].t;
	int minYear = info[0].t;
	for(int i = 1; i <= 12 ;i++)
		InfoByMonth(info,number,i);
	
	int temp = 0;
	for(int i = 0; i < number; i++)
	{
		temp +=info[i].t;
		if(maxYear < info[i].t)
			maxYear = info[i].t;
		if(minYear > info[i].t)
			minYear = info[i].t;
	}
	printf("      =================================================================\n");
	printf("      Year statistic: | TempAverage = %d | TempMax = %d | TempMin = %d\n",temp/number, maxYear, minYear);
	printf("      =================================================================\n");
}
