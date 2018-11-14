/******************************************************************

FILENAME:       bgd_table.h
Created Date:   8th Aug 2018
 
Block-Group Descriptor Structure, used to define parameters of all
the block groups

Structure from http://www.nongnu.org/ext2-doc/ext2.html

Block Group Descriptor is located after superblock.
3rd block on 1KiB block Filesystem OR
2nd block on 2KiB or higher block Filesystem.

copies of block-group descriptor table are stored with copies of
superblock
 
*******************************************************************/

#ifndef __INCLUDE_BGD_TABLE_H__
#define __INCLUDE_BGD_TABLE_H__

#include "types.h"

typedef struct ext2_group_desc
{
// block id of the first block of the block bitmap
	__ule32 bg_block_bitmap;

// block id of the first block of the inode bitmap
	__ule32 bg_inode_bitmap;

// block id of the first block of inode table
	__ule32 bg_inode_table;

// total number of free blocks
	__ule16 bg_free_blocks_count;

// total number of free inodes
	__ule16 bg_free_inodes_count;

// number of inodes allocated to the directories
	__ule16 bg_used_dirs_count;

// used for padding the structure on a 32-bit boundary
	__ule16 bg_pad;

// reserved for future revisions
	__ule8 bg_reserved[12];

}ext2_blkgrpdesc_table;

#endif
