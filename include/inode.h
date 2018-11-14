/******************************************************************

FILENAME:       inode.h
Created Date:   8th Aug 2018

Inode Structure, used to keep track of directories, regular file,
symbolic link or special files
This is the fundamental concept of ext2 filesystem
 
Structure from http://www.nongnu.org/ext2-doc/ext2.html

Each inode is used to in a way to have meta-data details of each
Filesystem object except its name

All the inodes are stored in inode tables
One inode table per block group, located by using bg_inode_table
There are s_inodes_per_group inodes per table
In rev 0, first 11 entries are reserved in inode table
In rev 1, reserved entries are specified in s_first_ino
  
*******************************************************************/

#ifndef __INCLUDE_INODE_H__
#define __INCLUDE_INODE_H__

#include "types.h"

//Defined Reserved Inodes
#define EXT2_BAD_INO	 	1	// bad blocks inode
#define EXT2_ROOT_INO	 	2	// root directory inode
#define EXT2_ACL_IDX_INO 	3	// ACL index inode
#define EXT2_ACL_DATA_INO	4	// ACL data inode
#define EXT2_BOOT_LOADER_INO	5	// boot loader inode
#define EXT2_UNDEL_DIR_INO	6	// undelete directory inode

//Values for file type and access rights

//----------------file format-----------------
#define EXT2_S_IFSOCK		0xC000	// Socket
#define EXT2_S_IFLNK		0xA000	// symbolic link
#define EXT2_S_IFREG		0x8000	// regular file
#define EXT2_S_IFBLK		0x6000	// block device
#define EXT2_S_IFDIR		0x4000	// directory
#define EXT2_S_IFCHR		0x2000	// character device
#define EXT2_S_IFIFO		0x1000	// FIFO

//-------------process executionuser/group override---------------
#define EXT2_S_ISUID		0x0800	// Set process User ID
#define EXT2_S_ISGID		0x0400	// Set process Group ID
#define EXT2_S_ISVTX		0x0200	// Sticky bit

//-------------------------access rights--------------------------
#define EXT2_S_IRUSR		0x0100	// user read
#define EXT2_S_IWUSR		0x0080	// user write
#define EXT2_S_IXUSR		0x0040	// user execute
#define EXT2_S_IRGRP		0x0020	// group read
#define EXT2_S_IWGRP		0x0010	// group write
#define EXT2_S_IXGRP		0x0008	// group execute
#define EXT2_S_IROTH		0x0004	// others read
#define EXT2_S_IWOTH		0x0002	// others write
#define EXT2_S_IXOTH		0x0001	// others execute

// Define i_flags values
#define EXT2_SECRM_FL		0x00000001	// secure deletion
#define EXT2_UNRM_FL		0x00000002	// record for undelete
#define EXT2_COMPR_FL		0x00000004	// compressed file
#define EXT2_SYNC_FL		0x00000008	// synchronous updates
#define EXT2_IMMUTABLE_FL	0x00000010	// immutable file
#define EXT2_APPEND_FL		0x00000020	// append only
#define EXT2_NODUMP_FL		0x00000040	// do not dum/delete file
#define EXT2_NOATIME_FL		0x00000080	// do not update .i_atime

//----------------Reserved for compression usage-----------------------
#define EXT2_DIRTY_FL		0x00000100	// Dirty(modified)
#define EXT2_COMPRBLK_FL	0x00000200	// compressed blocks
#define EXT2_NOCOMPR_FL		0x00000400	// access raw compressed data
#define EXT2_ECOMPRE_FL		0x00000800	// compression error

//----------------End of compression flags-----------------------------
#define EXT2_BTREE_FL		0x00010000	// b-tree format directory
#define EXT2_INDEX_FL		0x00010000	// hash indexed directory
#define EXT2_IMAGIC_FL		0x00020000	// AFS directory
#define EXT3_JOURNAL_DATA_FL	0x00040000	// journal file data
#define EXT2_RESERVED_FL	0x80000000	// reserved for ext2 library

typedef struct ino_table
{
// indicate file type and access rights
	__ule16 i_mode;

// user id associated with file
	__ule16 i_uid;

// size of files in bytes
	__ule32 i_size;

// Accessed time in seconds from EPOCH
	__ule32 i_atime;

// Time of creation on inode in seconds from EPOCH
	__ule32 i_ctime;

// modification time of inode in seconds from EPOCH
	__ule32 i_mtime;

// deletion time of inode in seconds from EPOCH
	__ule32 i_dtime;

// group having access to file
	__ule16 i_gid;

// determine the link count of inode
	__ule16 i_links_count;

// total number of 512 bytes blocks reserved to contain the data 
// of the inode
	__ule32 i_blocks;

// indicate how ext2 should behave when accessing the data
// i_flags values and meanings are defined in,
// http://www.nongnu.org/ext2-doc/ext2.html 
	__ule32 i_flags;

// OS dependent value
	union
	{
	   struct {
		__ule32 h_i_translator;   
	   }hurd1;
	   
	   struct {
		__ule32 l_i_reserved1;
	   }linux1;

	   struct {
		__ule32 m_i_reserved1;
	   }masix1;
	}i_osd1;

// block numbers pointing to block containing data for this inode
// There are total 15 pointers pointing to data blocks
// First 12 blocks are pointing to direct blocks
// 13th entry is the block number of first indirect block
// 14th entry is the block number of first doubly indirect block
// 15th entry is the block number of first triply indirect block
// indirect block contain array of block ID containing data (direct block)
// from Block 13 to 268 are indirect block
// doubly indirect block contain array of indirect block ID
// triply indirect block contain array of doubly indirect block ID
	__ule32 i_block[15];

// indicate file version
	__ule32 i_generation;

// indicate block number containing extended attr. In rev 0, it is 0
	__ule32 i_file_acl;

// If file is not regular file then it is 0
// If regular file, in rev 0 it is 0
// In rev 1, it contains high 32 bit value of 64 bit file size
	__ule32 i_dir_acl;

// indicate location of file fragment, In LINUX and HURD it is 0
	__ule32 i_faddr;

// OS dependent values
	union
	{
	   struct {
		__ule8 h_i_frag;	// fragment number, always 0
		__ule8 h_i_fsize;	// fragment size,always 0
		__ule16 h_i_mode_high;	// High 16 bit of 32 bit mode
		__ule16 h_i_uid_high;	// High 16 bit of uid
		__ule16 h_i_gid_high;	// High 16 bit of gid
		__le32 h_i_author;	// uid of file author, if -1 then POSIX uid is used
	   }hurd2;

	   struct {
		__ule8 l_i_frag;	// fragment number, always 0
		__ule8 l_i_fsize;	// fragment size, always 0
		__ule16 l_i_padding1;	// reserved bits
		__ule16 l_i_uid_high;	// High 16 bit of uid
		__ule16 l_i_gid_high;	// High 16 bit of gid
		__ule32 l_i_reserved2;	// reserved bits
	   }linux2;

	   struct {
		__ule8 m_i_frag;	// fragment number, always 0
		__ule8 m_i_fsize;	// fragment size, always 0
		__ule16 m_i_padding1;
		__ule32 m_i_reserved2[2];
	   }masix2;
	}i_osd2;

}ext2_inode_table;

#endif
