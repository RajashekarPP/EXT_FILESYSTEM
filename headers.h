#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#include"include/type.h"
#include"include/types.h"
#include "include/superblock.h"
#include "include/bgd_table.h"
#include "include/inode.h"
#include "include/directory.h"

ext2_superblock *sb;
ext2_blkgrpdesc_table *g_desc;
ext2_inode_table *inode_t;
ext2_dir_table *direntry_table;

__le32 superblock_info(__le32);
__le32 block_group_descriptor_t_info(__le32);
__le32 inode_table_info(__le32);
__le32 read_dir(__le32, __le32);
int ls(int, int);
//void cp(int , char *, char* ,int);
//int cd(int, char *,char *, int);
