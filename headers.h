#ifndef __HEADERS_H__
#define __HEADERS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

#include"types.h"
#include"ext2_fs.h"
#include"ext2_fs_sb.h"

int superblock_info(int);
int inode_table_info(int);
int block_group_descriptor_t_info(int);
int read_dir(int);

int ls(int , int); //filedescriptor , root_inode no
int cp(int , char * ,char *, int); //filedescriptor ,src filename , des filename ,root_inode no
int cd(int , char *,int); 	//filedescriptor ,directory path , root_inode no

#endif
