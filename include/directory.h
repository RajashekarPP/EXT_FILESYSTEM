/******************************************************************

FILENAME:       directory.h
Created Date:   8th Aug 2018

contains Directory structure, used to organize files hierarchically
2nd entry of inode table contains the inode pointing to root 
directory

Structure from http://www.nongnu.org/ext2-doc/ext2.html

In revision 0, directories are stored in linked list
In revision 1, indexed directory was introduced, 
which is backward compatible with Linked List
  
*******************************************************************/

#ifndef __INCLUDE_DIRECTORY_H__
#define __INCLUDE_DIRECTORY_H__

#include "types.h"

#define EXT2_FILENAME_LEN	255

// inode file type values
#define EXT2_FT_UNKNOWN		0 	// unknown file type
#define EXT2_FT_REG_FILE	1	// regular file
#define EXT2_FT_DIR		2	// directory file
#define EXT2_FT_CHRDEV		3	// character device
#define EXT2_FT_BLKDEV		4	// block device
#define EXT2_FT_FIFO		5	// buffer file
#define EXT2_FT_SOCK		6	// socket file
#define EXT2_FT_SYMLINK		7	// symbolic link

typedef struct directory_table
{
// inode number of file entry
// if 0, entry is not used
	__ule32 inode;

// displacement to the next directory entry 
// from the current directory entry
// The directories entry must be aligned on 4 bytes boundaries
// It should be a multiple of 4
	__ule16 rec_len;

// indicate the bytes of character data in name of file
// name_len < rec_len
	__ule8 name_len;

// indicate file type
	__ule8 file_type;

// Name of the file entry. name should not be more than 255 bytes
	__ule8 name[EXT2_FILENAME_LEN];


}ext2_dir_table;

#endif
