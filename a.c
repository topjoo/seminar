#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

#include "att.h"

#define SQR(X) 			printf(" ==> " #X "의 제곱은 %d입니다.\n", ((X)*(X)))
#define PRT(ss)    		printf(#ss)


#define INT_i(n)        int i##n = n;
#define PRINT(n)        printf("i%d = %d\n", n, i##n)
#define SUM(res, n)     ((res) += (i##n))



//#define TEST9 		0

#ifdef TEST9
#error Do Check TEST9 Logic
#endif



int 	main(void)
{
char    c_a=0x7d;
int 	i_b=20;
int 	i = 057;

CHAR    array[10] = "123456789";
CHAR    *pointer = NULL; // = "123456789";
short   s_c;
char    ch;
int 	*ipnt;
int 	iarry[] = {11,21,31,41,51,61,71,81,91,111,120};

const   int aa = 5;
volatile int bb = 5;

int 	ii, jj;




#if TEST1
{
int 	i=0;
int     bb5;
int     a=9;
int 	res=0;

	i = 033;
	printf(" mul = %d / %d \n", MUL1(2,2), MUL2(2+1, 2+1) );

	PRT(THIS IS TEST CODE);

	printf("asadasd" "AAAAAAAAAAAAAAAAAAAA \n"  );
//	aa = 10;
	bb = 55;

	if( ++i ) printf("i value =%d, aa:%d,  bb:%d\n", i, aa, bb);

	printf(" ii =%d, jj=%d \n", ii, jj);

	printf(" ============== %d \n", MY_MACRO_2(3,5));

	SQR(4);



	for(i=0; i<10; i++)
	{
		INT_i(i);
		PRINT(i);
		SUM(res,i);
	}

}
#endif

#if (TEST2)
	printf("sizeof(char)=%d,  sizeof(int)=%d, sizeof(short)=%d, \nsizeof(array)=%d, sizeof(pointer)=%d, sizeof(iarry)=%d \n ", 
				sizeof(char), sizeof(int), sizeof(short), sizeof(array), sizeof(pointer), sizeof(iarry) );
#endif


	
#if TEST3


	pointer = array;
	pointer++;
	printf(" pointer 0x%x = [%s] \n", pointer, pointer);
 	pointer += 1;
	printf(" pointer 0x%x = [%s] \n", pointer, pointer);
	pointer-=1;
	printf(" pointer 0x%x = [%s] \n", pointer, pointer);

	printf(" ====== integer pointer \n\n");

	ipnt = iarry;
	printf(" integer pointer 0x%x = [%d] \n", ipnt, *ipnt);
	ipnt++;
	printf(" integer pointer 0x%x = [%d] \n", ipnt, *ipnt);
	ipnt++;
	printf(" integer pointer 0x%x = [%d] \n", ipnt, *ipnt);
	ipnt++;
	printf(" integer pointer 0x%x = [%d] \n", ipnt, *ipnt);
	ipnt+=2;
	printf(" integer pointer 0x%x = [%d] \n", ipnt, *ipnt);

	
#endif


#if TEST4
	c_a++;
	printf(" c_a = %d (%x) \n", c_a, c_a);
	c_a = c_a + 1;
	printf(" c_a = %d (%x) \n", c_a, c_a);
	c_a += 1;
	printf(" c_a = %d (%x) \n", c_a,c_a);


	i_b++;
	printf(" i_b = %d \n", i_b);
	i_b = i_b + 1;
	printf(" i_b = %d \n", i_b);
	i_b += 1;
	printf(" i_b = %d \n", i_b);
#endif

#define TEST7 	1
#if TEST7
	{
	FILE	*inp=NULL, *out=NULL;
	int 	isize=0;
	int     itot = 0;
	typedef struct _file_cap {
		unsigned char 	board[16];
		unsigned char 	model[16];
		unsigned char 	version[16];
		unsigned char 	hash[32];
		unsigned char 	data[1024*30];
	} file_cap;

	unsigned char  hdr[32+1];
	file_cap 	aa;
	int 		line=1;
	
	inp = fopen("STM32.out", "rb");

	//if(inp) fseek(inp, 16+16+16+32, SEEK_SET);

	//aa.data = (char *)malloc( 1024*30*sizeof(char) );
	//memset( &aa, 0x00, sizeof(aa) );
	printf("sizeof aa = %d \n", sizeof(aa) );
	
	if(inp)
	{
		printf("file read OK ~~ \n");


#if 0
		memset( hdr, 0x00, sizeof(hdr) );
		isize = fread( (char*)&hdr, sizeof(unsigned char), 16, inp );
		printf(" board   = [%s] / %d \n", hdr, isize );

		memset( hdr, 0x00, sizeof(hdr) );
		isize = fread( (char*)&hdr, sizeof(unsigned char), 16, inp );
		printf(" model   = [%s] / %d \n", hdr, isize );

		memset( hdr, 0x00, sizeof(hdr) );
		isize = fread( (char*)&hdr, sizeof(unsigned char), 16, inp );
		printf(" version = [%s] / %d \n", hdr, isize );

		memset( hdr, 0x00, sizeof(hdr) );
		isize = fread( (char*)&hdr, sizeof(unsigned char), 32, inp );
		hdr[32] = '\0';
		printf(" hash    = [%s] / %d \n", hdr, isize );

		memset( hdr, 0x00, sizeof(hdr) );
		while( isize = fread( (char*)&hdr, sizeof(unsigned char), 16, inp ) )
		{
			itot += isize;
			printf(" ++Read Size++ = %2d/%5d (0x%04x) : ", isize, itot, itot-16);
			for(i=0;  i<isize ; i++)
			{
				printf("%02X ", hdr[i] );
				if( 0==(line%16) ) printf("\n");
				line++;
			}
			memset( hdr, 0x00, sizeof(hdr) );

		}

		
#else

		memset( (char *)aa.data, 0x00, sizeof(aa.data) );

		while( isize = fread( (char*)&aa, sizeof(unsigned char), 1024*30, inp ) )
		{
			//fwrite(aa->data, sizeof(unsigned char), isize, out); 
			printf(". isize = %d \n", isize);
			itot += isize;

		}

		printf(" aa.board   = [%s] \n", aa.board );
		printf(" aa.model   = [%s] \n", aa.model );
		printf(" aa.version = [%s] \n", aa.version );
		aa.hash[32] = '\0';
		printf(" aa.hash    = [%s] \n", aa.hash );

		printf("++++++++++++++++++++++++++++++++++++ isize=%d, itot=%d \n", isize, itot);
		printf(" +1+ (0x%04x) +1+: ", 0);

		itot = itot - 16-16-16-32;

	#if 1
		for(i=0;  i<itot ; i++)
		{
			printf("%02X ", aa.data[i] );
			if( 0==(line%16) && itot>line ) 
			{
				printf("\n +1+ (0x%04x) +1+: ", line);
			}
			line++;
		}
	#else
		i = 0;
		do {
			printf("%02X ", aa.data[i] );
			if( 0==(line%16) && itot>line) 
			{
				printf("\n +2+ (0x%04x) +2+: ", line);
			}
			line++;
			i++;
		} while( i<itot );
	#endif
	
#endif

		
		printf(" \nread data - completed \n");
	}
	else
	{
		printf("\n\nThe File is NONE~~ \n");
	}


	//free(aa.data);
	
	}
#endif


}





