#include "temp_function.h"

int main(int argc, char **argv)
{
	sensor info[SIZE];
	int key = 0;
	int number;
	
	if(argc == 1)
	{
		printf("Run the program with key <-h> for help\n");
		return 0;
	}
	
	while( (key = getopt(argc,argv,"hf:m:p")) !=-1)
	{
		switch(key)
		{
			case 'h': 	printf("Help information about programm.\n");
						printf("Enter key:\n");
						printf("-h for Help.\n");
						printf("-f <file_name> for load this file.\n");
						printf("-m <xx> statistic for xx month.\n");
						printf("-p data loaded from a .csv file without errors lines.\n");
						break;
			case 'f': 	number = AddInfo(info,optarg);
						if(argv[3] == NULL)
							InfoByYear(info,number);  
						break;
			case 'm': 	if(argv[2] == NULL)
						{
							printf("!!ERROR FOUND FILE!!\n");
							printf("Please enter key -f and <file_name> for load this file\n");
							break;
						}
						InfoByMonth(info,number,atoi(optarg));  
						break;
			case 'p': 	if(argv[2] == NULL)
						{
							printf("!!ERROR FOUND FILE!!\n");
							printf("Please enter key -f and <file_name> for load this file\n");
							break;
						}
						Print(info,number);  
						break;
			default: printf("!!FATAL ERROR!!\n");break;
		}
	} 
	return 0;
}

