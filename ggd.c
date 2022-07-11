
#include <stdio.h>
#include "ggd.h"


int 	main(void)
{
	int i, j;


#if 0
	for(i=2; i<=MAX_GGD_NUM; i+=4)
	{
		printf(" ---%dDAN----    ---%dDAN----    ---%dDAN----    ---%dDAN---- \n", i, i+1, i+2, i+3);
		for(j=1; j<=MAX_GGD_NUM; j++)
		{
			printf("%2d X %2d = %2d   %2d X %2d = %2d   %2d X %2d = %2d   %2d X %2d = %2d \n", 
						i, j, MUL(i,j),  i+1, j, MUL(i+1,j), i+2, j, MUL(i+2,j), i+3, j, MUL(i+3,j) );
		}
		printf("--------------------------------------------------------- \n");
	}
#else

	i = 2;
	j = 1;
	do {
		printf(" ---%dDAN----    ---%dDAN----    ---%dDAN----    ---%dDAN---- \n", i, i+1, i+2, i+3);
		j = 1;
		do {
			printf("%2d X %2d = %2d   %2d X %2d = %2d   %2d X %2d = %2d   %2d X %2d = %2d \n", 
						i, j, MUL(i,j),  i+1, j, MUL(i+1,j), i+2, j, MUL(i+2,j), i+3, j, MUL(i+3,j) );
			j++;
		} while(j<=MAX_GGD_NUM);
		printf("--------------------------------------------------------- \n");

		i += 4;
	} while(i<=MAX_GGD_NUM);

#endif


	return 1;
}


