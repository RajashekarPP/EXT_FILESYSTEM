/******************************************************************

FILENAME:	superblock.h
Created Date:	8th Aug 2018

contains the structure of an ext2 superblock, with a bunch of
constants used within the superblock.

Structure from http://www.nongnu.org/ext2-doc/ext2.html

Superblock contains all the information about the configuration
of the filesystem.
Superblock is stored at an offset of 1024 bytes from the start
of the device.
All fields in superblock are stored in little endian format.

*******************************************************************/

#ifndef __INCLUDE_SUPERBLOCK_H__
#define __INCLUDE_SUPERBLOCK_H__

#include "types.h"

// constants used in some superblock fields.
#define EXT2_SUPER_MAGIC 	0xEF53	// Magic number for Ext2 FS
#define EXT2_VALID_FS 		1	// FS is cleanly unmounted
#define EXT2_ERROR_FS		2	// FS is mounted
#define EXT2_ERRORS_CONTINUE	1	// continue as if nothing happened
#define EXT2_ERRORS_RO		2	// remount read-only
#define EXT2_ERRORS_PANIC	3	// cause a Kernel panic
#define EXT2_OS_LINUX		0	// Linux
#define EXT2_OS_HURD		1	// GNU HURD
#define EXT2_OS_MASIX		2	// MASIX
#define EXT2_OS_FREEBSD		3	// FreeBSD
#define EXT2_OS_LITES		4	// Lites
#define EXT2_GOOD_OLD_REV	0	// Revision 0
#define EXT2_DYNAMIC_REV	1	// Revision 1 with variable inode sizes, extended attributes etc.
#define EXT2_DEF_RESUID		0	// Default user id for reserved blocks
#define EXT2_DEF_RESGID		0	// Default group id for reserved blocks
#define EXT2_GOOD_OLD_FIRST_INO	11	// In revision 0, first useable inode index
#define EXT2_GOOD_OLD_INODE_SIZE 128	// In revision 0, size of inode structure
#define EXT2_FEATURE_COMPAT_DIR_PREALLOC 0x0001 // Block pre-allocation for new directories
#define EXT2_FEATURE_COMPAT_IMAGIC_INODES 0x0002 
#define EXT2_FEATURE_COMPAT_HAS_JOURNAL 0x0004	// An EXT3 exists
#define EXT2_FEATURE_COMPAT_EXT_ATTR 0x0008	// Extended inode attributes are present
#define EXT2_FEATURE_COMPAT_RESIZE_INO 0x0010	// Non-standard inode size used
#define EXT2_FEATURE_COMPAT_DIR_INDEX 0x0020	// Directory indexing (HTree)

// bitmask of incompatible features.
#define EXT2_FEATURE_INCOMPAT_COMPRESSION 0x0001 // Disk/File compression is used
#define EXT2_FEATURE_INCOMPAT_FILETYPE 0x0002	 
#define EXT2_FEATURE_INCOMPAT_RECOVER  0x0004
#define EXT2_FEATURE_INCOMPAT_JOURNAL_DEV 0x0008
#define EXT2_FEATURE_INCOMPAT_META_BG 0x0010

#define EXT2_FEATURE_RO_COMPAT_SPARSE_SUPER 0x0001  // Sparse Superblock
#define EXT2_FEATURE_RO_COMPAT_LARGE_FILE 0x0002   // Large File support, 64-bit file size
#define EXT2_FEATURE_RO_COMPAT_BTREE_DIR 0x0004    // Binary tree sorted directory files

// determine compression method
#define EXT2_LZV1_ALG		0x00000001
#define EXT2_LZRW3A_ALG 	0x00000002 
#define EXT2_GZIP_ALG		0x00000004
#define EXT2_BZIP2_ALG		0x00000008
#define EXT2_LZO_ALG		0x00000010

//sizeof(struct ext_s_superblock) == 1024

typedef struct ext2_super_block {

// total number of inodes used and free in filesystem
// s_inodes_count <= (s_inodes_per_group * No. of block groups)
// s_inodes_count = sum(inodes in each block group)
	__ule32 s_inodes_count;

// total number of blocks in filesystem (free, used and reserved)
// s_blocks_count <= (s_blocks_per_group * No. of block groups)
// s_blocks_count = sum(blocks in each block group)
	__ule32 s_blocks_count;

// total number of blocks reserved for super user
	__ule32 s_r_blocks_count;

// total number of free blocks (including reserved blocks)
// s_free_blocks_count = sum(free blocks of all block group)
	__ule32 s_free_blocks_count;

// total number of free inodes
	__ule32 s_free_inodes_count;

// identifying the first data block or the id of the block containing the superblock structure
// s_first_data_block = 0 ; block size > 1KB
// 		      = 1 ; block size = 1KB
// superblock start at 1024th byte of the disk
	__ule32 s_first_data_block;

// blocksize is computed using s_log_block_size (always +ve)
// block size = 1024 << s_log_block_size
	__ule32 s_log_block_size;

// fragment size is computed using s_log_frag_size (can be +ve or -ve)
// fragmentsize = (s_log_frag_size > 0) ? 
// 		(1024 << s_log_frag_size) :(1024 >> -s_log_frag_size)
	__le32 s_log_frag_size;

// total number of blocks per group 
	__ule32 s_blocks_per_group;

// total number of fragments per group.
// also determine the size of block bitmap.
	__ule32 s_frags_per_group;

// total number of inodes per group. 
// can also be used to determine the size of inode bitmap.
	__ule32 s_inodes_per_group;

// last time the filesystem is mounted, since the EPOCH (UNIX Time)
	__ule32 s_mtime;

// last write access to filesystem, since the EPOCH (UNIX Time)
	__ule32 s_wtime; 

// number of time filesystem has been mounted in read-write mode without been checked (ie since fsck is being run)
	__ule16 s_mnt_count;

// maximum number of time filesystem has been mounted before verified
	__ule16 s_max_mnt_count;

// magic signature FS for ext2
// EXT2_SUPER_MAGIC = 0xEF53
	__ule16 s_magic;

// indicating filesystem state
// EXT2_ERROR_FS = 2 ; FS is mounted
// EXT2_VALID_FS = 1 ; FS is cleanly unmounted
	__ule16 s_state;

// indicate what filesystem shoulld do when an error is detected
	__ule16 s_error;

// identifies the minor revision level
	__ule16 s_minor_rev_level;

// time of the last file system check
	__ule32 s_lastcheck;

// maximum time interval, allowed between file system check
	__ule32 s_checkinterval;

// identify the OS that created the filesystem
	__ule32 s_creator_os;

// identify the revision level using filesystem
	__ule32 s_rev_level;

// default user id for reserved blocks
	__ule16 s_def_resuid; 

// default group id for reserved blocks
	__ule16 s_def_resgid;

// index to the first inode useable for std. files, 
// it's 11 in rev 0 and can be any value in rev 1
	__ule32 s_first_ino;

// indicate size of inode structure,
// it's 128 in rev 0 and power of 2 and smaller than or equal to the block size in rev 1
	__ule16 s_inode_size;

// indicate the block group numberhosting superblock structure.
// can be used to rebuild the filesystem from backup
	__ule16 s_block_group_nr;

// bitmask of compatible features
	__ule32 s_feature_compat;

// bitmask of incompatible features
	__ule32 s_feature_incompat;

// bitmask of read-only features
	__ule32 s_feature_ro_compat;

// used as a volume id, should be unique for each filesystem formatted
	__ule8 s_uuid[16];

// volume name, mostly unused. 0 terminated ISO-LATIN-1 characters
	__ule8 s_volume_name[16];

// directory path where filesystem was last mounted. 0 terminated ISO-Latin1 characters
	__ule8 s_last_mounted[64];

// used to determine compression algorithm
	__ule32 s_algo_bitmap;

// number of blocks attempted to pre-allocat when creating a new regular file
	__ule8 s_prealloc_blocks;

// number of blocks attempted to pre-allocate when creating a new directory.
	__ule8 s_prealloc_dir_blocks;

// padding bits
	__ule16 s_padding;

// contains the uuid of journal superblock
	__ule8 s_journal_uuid[16];

// inode number of journal file
	__ule32 s_journal_inum;

// device number of journal file
	__ule32 s_journal_dev;

// pointing to the first inode in the list of inodes to be deleted
	__ule32 s_last_orphan;

// seeds used for the hash algo for directories indexing
	__ule32 s_hash_seed[4];

// default hash version for directory indexing
	__ule8 s_def_hash_version;

// default mount option for filesystem
	__ule32 s_default_mount_option;

// block group id of first meta block group
	__ule32 s_first_meta_bg;

// reserved / unused bits
	__ule8 s_unused[760];

}ext2_superblock;

#endif
