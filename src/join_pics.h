#ifndef JOIN_PIC_H
#define JOIn_PIC_H
#include <stdio.h>


#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif
EXTERNC int join_pics(int rand_seed, int width,int height,int divide_x,int divide_y,const char* pics_path, const char* join_pic_name);
EXTERNC int join_16_pics(int rand_seed, const char** picNames,  int join_pic_sizex, int join_pic_sizey, const char* join_pic_name);
#endif