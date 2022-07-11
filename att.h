
//#pragma once

#ifndef __ATTACHED_H__
#define __ATTACHED_H__

#include <stdio.h>
#include <unistd.h> /* for getopt() */
#include <assert.h>	/* assert() */
#include <getopt.h> /* getopt_long() */

#define PI 			3.141592

#define TEST0 		1
#define TEST1 		0
#define TEST2 		1
#define TEST3       0
#define TEST4       0

#define TEST7 		0

#define TEST11 		0






typedef unsigned int 	WORD;
typedef unsigned char   CHAR;



#define MUL1(a,b)		(a*b)
#define MUL2(a,b)		((a)*(b))

#define MY_MACRO_2(x,y)   x##y

#define MY_MACRO(x) #x

#define MAX_CHARS 		16


static int verbose_flag;
static char strOpt[] = "g:ALz:h:b:m:v:i:o:a:c:d:F:I:N:S:f:B:M:J:l:ej:nE:P:kZR:";

const struct option long_options[] =
{
	/* These options set a flag. */
	{"brief",		no_argument,	   &verbose_flag, 0},
	/* These options don't set a flag.	We distinguish them by their indices. */
	{"append",		required_argument, 0, 'a'}, /// Output (append) filename
	{"board",		required_argument, 0, 'b'}, /// Attach Header : Board Name(16byte)
	{"cinfo",		required_argument, 0, 'c'}, /// create current system date or insert checksum
	{"detach",		required_argument, 0, 'd'}, /// detach Header (16byte * 4 lines)
	{"elf", 		no_argument,	   0, 'e'}, /// elf
	{"float",		required_argument, 0, 'f'}, /// float number to hex-decimal
	{"ignore",		required_argument, 0, 'g'}, /// ignore input & output-file
	{"help",		required_argument, 0, 'h'}, /// help
	{"input",		required_argument, 0, 'i'}, /// input file name
	{"join",		required_argument, 0, 'j'}, // file merged!!  2017.04.05
	{"allpadarea",	no_argument,	   0, 'k'}, /// checksum type for hex2bin
	{"length",		required_argument, 0, 'l'}, /// Mot2bin, hex2bin : MaxSize
	{"model",		required_argument, 0, 'm'}, /// Attach Header : Module Name (16byte)
	{"alignword",	no_argument,	   0, 'n'}, // intel family address alignment word ENABLE
	{"output",		required_argument, 0, 'o'}, /// output filename

	{"version", 	required_argument, 0, 'v'}, /// Attach Header : Version Name (16byte)

	{"verbose", 	required_argument, 0, 'z'}, /// verbos --

	/// ------------------------------------------------------------------------------
	{"motorola",	no_argument,	   0, 'A'}, /// convert Motorola to binary
	{"bmp", 		required_argument, 0, 'B'}, /// bmp file

	{"endian",		required_argument, 0, 'E'}, /* 0:little-endian,  1:big-endian */
	{"fillsize",	required_argument, 0, 'F'}, /// Fill Data (0xFF)

	{"fileinform",	required_argument, 0, 'I'}, /// File Information in PC
	{"mjd", 		required_argument, 0, 'J'}, /// Modified Julian Date---

	{"intel",		no_argument,	   0, 'L'}, /// convert Intel Format to binary
	{"checksum",	required_argument, 0, 'M'}, /// checksum MD5, SHA1, SHA256, SHA384, SHA512--
	{"nk",			required_argument, 0, 'N'}, /// WinCE OS Kernel, nk.bin information

	{"padbyte", 	required_argument, 0, 'P'}, // Padbyte 0xff

	{"random",		required_argument, 0, 'R'},
	{"startaddr",	required_argument, 0, 'S'}, /// start address Hex2bin--


	{"zeroforced",	no_argument,	   0, 'Z'},

	{0, 0, 0, 0}
};



#endif //__ATTACHED_H__


