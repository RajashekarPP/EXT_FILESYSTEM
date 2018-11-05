#ifndef __HEADERS_H__
#define __HEADERS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include"types.h"
#include"ext_fs.h"
#include"ext2_fs_sb.h"

int superblock_info(int);
int inode_info(int);
int block_group_dec_t_info(int);
int readdir(int);

int ls(int , int); //filedescriptor , root_inode no
int cp(int , char * char *, int); //filedescriptor ,src filename , des filename ,root_inode no
int cd(int , char *,int); 	//filedescriptor ,directory path , root_inode no

#endif
