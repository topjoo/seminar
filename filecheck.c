
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

#include <io.h>
#include <assert.h>	/* assert() */
#include <stdarg.h>



int isFileExist(const char *file)
{
	struct	_finddatai64_t fexist;
	long ret = 0L;
	int  retValue = 0;

	if(0==strcmp(file,"") || NULL==file) return 0;

	if( (ret = _findfirsti64( file, &fexist )) == -1L )
	{
		retValue = 0; // File NOT Exist
	}
	else
	{
		retValue = 1; // FIle Exist
	}
	_findclose( ret );

	printf("RETURN VALUE : %d -> [%s] -> %s  \n", retValue, file, retValue?"File Exist":"None File" );
	return retValue;
}



int 	main(int argc, char *argv[])
{
	int 	iret = -1;
	FILE	*fw = NULL;


	iret = isFileExist("./wifi.conf");
	if( 0 == iret )
	{
		fw = fopen("wifi.conf", "w");

		fprintf(fw,"ssid = Galaxy S10 \n");
		fprintf(fw,"password = 123456*7890 \n");
		fprintf(fw,"\n");
		fprintf(fw,"By kh.hwang@macriot.co.kr \n");
		fclose(fw);

		printf("wifi.conf -> New Create!!!!! \n");
	}
	else
	{
		printf("OK: Already file exist!!!\n");
	}
		
}


