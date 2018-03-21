#include "stdio.h"
#include "iostream"
#include "stdlib.h"

#define SIZE 256

using namespace std;

void read_raw(char* path, unsigned char image_data[3][SIZE][SIZE]){
	FILE *file;
	if (!(file = fopen(path, "rb")))
	{
		printf("Cannot open file!\n");
		exit(1);
	}

	fread(image_data, sizeof(unsigned char), SIZE* SIZE * 3, file);
	fclose(file);
}

void write_raw(char* path, unsigned char gray_image[SIZE][SIZE]){
    FILE *file;
	if (!(file = fopen(path, "wb")))
	{
		printf("Cannot open file!\n");
		exit(1);
    }

	fwrite(gray_image, sizeof(unsigned char), SIZE*SIZE, file);
	fclose(file);
}
