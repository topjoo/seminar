#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

#include "att.h"

#define SQR(X) 			printf("==> The square of " #X " is %d.\n", ((X)*(X)))
#define PRT(ss)    		printf(#ss)


#define INT_i(n)        int i##n = n;
#define SUM(res, n)     ((res) += (i##n)); \
						printf(" i%d = (%d) => SUM: %d \n", n, i##n, res);



//#define TEST9 		0

#ifdef TEST9
#error Do Check TEST9 Logic
#endif



int 	main(int argc, char *argv[])
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

		printf("mul = %d / %d \n", MUL1(2,2), MUL2(2+1, 2+1) );

		PRT(THIS IS TEST CODE);


		bb = 55;

		if( ++i ) printf("i value =%d, aa:%d,  bb:%d\n", i, aa, bb);

		printf("ii =%d, jj=%d \n", ii, jj);

		printf("============== %d \n", MY_MACRO_2(3,5));

		SQR(4);
		SQR(9);



		for(i=0; i<10; i++)
		{
			INT_i(i);
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




#if TEST11
	int opt;
	int option_index = 0;
	char str_crcAdd[MAX_CHARS+1];
	char str_mjd[MAX_CHARS+1];
	char str_ignore[MAX_CHARS+1];
	char str_float[MAX_CHARS+1];
	char str_hash[MAX_CHARS+1];
	char str_address[MAX_CHARS+1];

	while( EOF != (opt = getopt_long(argc, argv, strOpt, long_options, &option_index)) ) 
	{
     
		switch(opt) 
		{ 

			case 'J' : /// 2014.06.27,  Modified Julian Date--

				if(optarg) 
				{
					memcpy(str_mjd, optarg, MAX_CHARS);

					if( 0==strcasecmp(str_mjd, "test" )  )
					{
					}
					else if( 0==strcasecmp(str_mjd, "current" ) )  
					{
					}
					else if( 0==strcasecmp(str_mjd, "date" ) )  
					{
					}
					else
					{
						printf("\nMJD>> WARNING:Wrong option. --mjd [date|mjd]. Check option.\n");

						exit(0);
						return 0;
					}
				}
				else
				{
					printf("\nMJD>> WARNING:option error. check option --mjd [date|mjd]. \r\n");

					exit(0);
					return 0;
				}
				break;

			case 'M' : /// 2014.06.27, MD5/SHA1/SHA256/SHA384/SHA512 Checksum
				if(optarg) 
				{
					if( 0==strcasecmp(str_hash, "MD5") )
					{
					}
					else if( 0==strcasecmp(str_hash, "SHA1") )
					{
					}
					else if( 0==strcasecmp(str_hash, "SHA224") )
					{
					}
					else if( 0==strcasecmp(str_hash, "SHA256") )
					{
					}
					else if( 0==strcasecmp(str_hash, "SHA384") )
					{
					}
					else if( 0==strcasecmp(str_hash, "SHA512") )
					{
					}
					else if( 0==strcasecmp(str_hash, "MD4") )
					{
					}
					else if( 0==strcasecmp(str_hash, "MD2") )
					{
					}
					else if( 0==strcasecmp(str_hash, "MD6") )
					{
					}
					else if( 0==strcasecmp(str_hash, "crc16") )
					{
					}
					else if( 0==strcasecmp(str_hash, "crc16ksc") )
					{
					}
					else if( 0==strcasecmp(str_hash, "crc16c") )
					{
					}
					else if( 0==strcasecmp(str_hash, "crc32") )
					{
					}
					else if( 0==strcasecmp(str_hash, "crc64") )
					{
					}
					else if( 0==strcasecmp(str_hash, "crc64isc") )
					{
					}
					else
					{

						printf("\n\nWarning: -M or --checksum MD2|MD4|MD5|MD6 \n");
						printf("                          SHA1|SHA224|SHA256|SHA384|SHA512 \n");
						printf("                          SHA3-224|SHA3-256|SHA3-384|SHA3-512|SHAKE128|SHAKE256 \n");
						printf("                          RipeMD128|RipeMD160 \n");
						printf("                          crc16|crc16c|crc32|crc64|adler32 \n");
						printf("                          CRC16|CRC16C|CRC32|CRC64|ADLER32 \n");

						exit(0);
						return 0;
					}

				}
				break;



			case 'g' : /* ignore inputfile and output file */

				if(optarg) 
				{
					memcpy(str_ignore, optarg, sizeof(str_ignore) );
				}

				break;


			case 'f' : /* convert float number to Hex-decial for using DR_GPS Trimble packet */
				if(optarg) 
				{
					memcpy(str_float, optarg, MAX_CHARS );
				}
				else
				{
					printf("\n\n WARNING:wrong option --float [float number]. \r\n");

					exit(0);	
					return 0;
				}
				break;

		    case 'h' : /* help */
				if(optarg)
				{

				}

				exit(0);
				return 0;

			case 'S': /* --startaddr : Starting Address hex2bin */

				if(optarg) 
				{
					memcpy(str_address, optarg, MAX_CHARS);

			        printf("\nHEX2BIN>> Start address : %s \n", str_address );
				}
				else
				{
					printf("\nHEX2BIN>> WARNING:wrong option --start [hexa value]. check option\r\n");

					exit(0);
					return 0;
				}
				break;

			case 'e': /// elf 2 bin

				break;

		    case 'A': /* convert mot2bin -> Motorola FORMAT family --- */
				printf("\n");
				printf(">>Hex family type : MOTOROLA family");

				break;
				
		    case 'L': /* convert intel2bin -> Intel FORMAT family --- */
				printf("\n");
				printf(">>Hex family type : Intel family");
				break;

		    case 'n': /* --alignword : Address Alignment Word -> Intel family only --- */


				break;
				
			case 'P': // --padbyte

				printf("padbyte \n");
				break;

			case 'E': // --endian
				if(optarg) 
				{}
				else
				{
					printf("\n\n WARNING:wrong option --endian [little|big]. check option\r\n");
			
					exit(0);
					return 0;
				}
				break;

		    case 'k':  /* --allpadarea : fill Padbye in all empty area */

				printf("\n");
				printf(">>Fill Pad Byte   : Pad byte in empty ALL area of binary \n" );
				break;

			case 'Z': // --zeroforced

				printf("\n");
				printf(">>Address Forced  : Using ZERO addressing forced. \n");

				break;

		    case 'l': /* Hex2bin Max size - length */

				if(optarg) 
				{
				}
				else
				{
					printf("\n WARNING:wrong --length [hexa value] in converting --intel or --motorola. check option [%s] \n");

					exit(0);
					return 0;
				}
				break;

			case 'R':

				if(optarg) 
				{
				}
				break;
				
		    case 'N': /* infotmation */
				if(optarg) 
				{
				}
				else
				{
					printf("\n\n WARNING:wrong option --nk [nb0 | none]. check option\r\n");

					exit(0);
					return 0;
				}
				break;
			
		    case 'I': /* infotmation */
				if(optarg) 
				{

				}
		        exit(0);
		    	break;

		    case 'F':

				if(optarg) 
				{
				}
				else
				{
					printf("\n\n WARNING:wrong option --fillsize [value]. check option\r\n");
					exit(0);
					return 0;
				}
		    	break;

			case 'j': /* 2017.04.05, File merge */

				if(optarg) 
				{
				}
				else
				{
					printf("\n\n WARNING:wrong option --join [in hexa]. check option\r\n");

					exit(0);
					return 0;
				}
				break;


		    case 'd': /* detach Header */

		        break;

	
		    case 'b': /* Attach Header : 16 characters */
				if(optarg) 
				{
				}
				else
				{
					printf("\n\n WARNING:wrong option --board [string]. check option\r\n");

					exit(0);
					return 0;
				}
		        break;

				
		    case 'm': /* Attach Header : 16 characters */
				if(optarg) 
				{
				}
				else
				{
					printf("\n\n WARNING:wrong option --model [string]. check option\r\n");

					exit(0);
					return 0;
				}
		        break;
		
		    case 'c': /* Attach Header : 16 characters ; date / crc16/crc32/crc64/adler32 */
				if( 0==strcasecmp(str_crcAdd, "crc16") )
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}
				else if( 0==strcasecmp(str_crcAdd, "crc16ksc") )
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}
				else if( 0==strcasecmp(str_crcAdd, "crc16c") )
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}
				else if( 0==strcasecmp(str_crcAdd, "crc32") )
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}
				else if( 0==strcasecmp(str_crcAdd, "crc64") )
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}
				else if( 0==strcasecmp(str_crcAdd, "crc64isc") )
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}
				else if( 0==strcasecmp(str_crcAdd, "adler32") ) 
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "joaat") ) 
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}
				else if( 0==strcasecmp(str_crcAdd, "sha1") )	// SHA1
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "sha224") )	// SHA2-224
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "sha256") )  // SHA2-256
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "sha384") ) // SHA2-384
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "sha512") ) // SHA2-512
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "sha3-224") ) 
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "sha3-256") ) 
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "sha3-384") ) 
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "sha3-512") ) 
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "shake128") ) 
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "shake256") ) 
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "md5") ) // MD5
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "md6") ) // MD6
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "md2") ) // MD2
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else if( 0==strcasecmp(str_crcAdd, "md4") ) // MD4
				{
					printf("The %s is inserted as signed image.", str_crcAdd);
				}	
				else
				{
					printf("\n\n WARNING:wrong option --cinfo [string]. check option\r\n");

					exit(0);
					return 0;
				}
		    	break;


		    case 'v': /* Attach Header : 16 characters */

				if(optarg) 
				{
					printf("\n\n[++ERROR++] Version Name length is too long.. Max Bytes\n\n"  );
				}
				else
				{
					printf("\n\n WARNING:wrong option --version [string]. check option\r\n");
					exit(0); /// 2017.11.21

					return 0;
				}

				break;
		
		    case 'i': /* input file name : 32 characters */
				if(optarg) 
				{
				}
				else
				{
					printf("\n\n[++ERROR++] Input file is NULL.  check option --input [filename]. \n\n" );
					exit(0);
					return 0;
				}

				break;
		

			case 'a': /* output file name : 32 characters -- append mode */



		    case 'o': /* 32 characters  -- write mode */
				
				if(optarg) 
				{
				}
				else
				{
					printf("\n\n[++ERROR++] Output file is NULL.  check option --output|--append [filename]. \n\n" );
					exit(0);
					return 0;
				}				
				break;

		    case 'z': /// printf, verbos ---

				printf("\n");

		    	break;

			default:
				printf("\n\n");

				exit(0);
				return 0;
				break;
		}


	}


#endif


	return 1;

}





