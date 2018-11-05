
#define EXT2_VALID_FS 1 	//Unmounted cleanly
#define EXT2_ERROR_FS 2 	//Errors detected

#define EXT2_XATTR_MAGIC 0xEA020000 //32 bit magic no of identification
#define EXT2_ERRORS_CONTINUE 1	 //continue as if nothing happened
#define EXT2_ERRORS_RO 2  	//remount read-only
#define EXT2_ERRORS_PANIC 3 	//cause a kernel panic

#define EXT2_OS_LINUX 0 	//Linux
#define EXT2_OS_HURD 1 		//GNU HURD
#define EXT2_OS_MASIX 2		//MASIX
#define EXT2_OS_FREEBSD 3 	//FreeBSD
#define EXT2_OS_LITES 4 	//Lites

#define EXT2_GOOD_OLD_REV 0   //Revision 0
#define EXT2_DYNAMIC_REV 1    // Revision 1 with variable inode sizes,extended attributes, etc.

#define EXT2_FEATURE_COMPAT_DIR_PREALLOC 0x0001 //Block pre-allocation for new directories
#define EXT2_FEATURE_COMPAT_IMAGIC_INODES 0x0002 
#define EXT3_FEATURE_COMPAT_HAS_JOURNAL 0x0004  //An Ext3 journal exists
#define EXT2_FEATURE_COMPAT_EXT_ATTR 0x0008     //Extended inode attributes are present
#define EXT2_FEATURE_COMPAT_RESIZE_INO 0x0010   //Non-standard inode size used
#define EXT2_FEATURE_COMPAT_DIR_INDEX 0x0020    //Directory indexing (HTree)

#define EXT2_FEATURE_INCOMPAT_COMPRESSION 0x0001 //Disk/File compression is used
#define EXT2_FEATURE_INCOMPAT_FILETYPE 0x0002
#define EXT3_FEATURE_INCOMPAT_RECOVER 0x0004
#define EXT3_FEATURE_INCOMPAT_JOURNAL_DEV 0x0008
#define EXT2_FEATURE_INCOMPAT_META_BG 0x0010

#define EXT2_FEATURE_RO_COMPAT_SPARSE_SUPER 0x0001 //Sparse Superblock
#define EXT2_FEATURE_RO_COMPAT_LARGE_FILE 0x0002 //Large file support, 64-bit file size
#define EXT2_FEATURE_RO_COMPAT_BTREE_DIR 0x0004 //Binary tree sorted directory files

#define EXT2_LZV1_ALG 0   //Binary value of 0x00000001
#define EXT2_LZRW3A_ALG 1 //Binary value of 0x00000002
#define EXT2_GZIP_ALG 2   //Binary value of 0x00000004
#define EXT2_BZIP2_ALG 3  //Binary value of 0x00000008
#define EXT2_LZO_ALG 4    //Binary value of 0x00000010

#define EXT2_BAD_INO 1 		//bad blocks inode
#define EXT2_ROOT_INO 2 	//root directory inode
#define EXT2_ACL_IDX_INO 3 	//ACL index inode (deprecated?)
#define EXT2_ACL_DATA_INO 4 	//ACL data inode (deprecated?)
#define EXT2_BOOT_LOADER_INO 5 	//boot loader inode
#define EXT2_UNDEL_DIR_INO 6 	//undelete directory inode

#define EXT2_S_IFSOCK 0xC000 //socket
#define EXT2_S_IFLNK 0xA000 //symbolic link
#define EXT2_S_IFREG 0x8000 //regular file
#define EXT2_S_IFBLK 0x6000 //block device
#define EXT2_S_IFDIR 0x4000 //directory
#define EXT2_S_IFCHR 0x2000 //character device
#define EXT2_S_IFIFO 0x1000 //fifo

#define EXT2_S_ISUID 0x0800 //Set process User ID
#define EXT2_S_ISGID 0x0400 //Set process Group ID
#define EXT2_S_ISVTX 0x0200 //sticky bit

#define EXT2_S_IRUSR 0x0100 //user read
#define EXT2_S_IWUSR 0x0080 //user write
#define EXT2_S_IXUSR 0x0040 //user execute
#define EXT2_S_IRGRP 0x0020 //group read
#define EXT2_S_IWGRP 0x0010 // group write
#define EXT2_S_IXGRP 0x0008 //group execute
#define EXT2_S_IROTH 0x0004 //others read
#define EXT2_S_IWOTH 0x0002 //others write
#define EXT2_S_IXOTH 0x0001 // others execute

#define EXT2_SECRM_FL 0x00000001 	//secure deletion
#define EXT2_UNRM_FL 0x00000002 	//record for undelete
#define EXT2_COMPR_FL 0x00000004 	//compressed file
#define EXT2_SYNC_FL 0x00000008		// synchronous updates
#define EXT2_IMMUTABLE_FL 0x00000010	// immutable file
#define EXT2_APPEND_FL 0x00000020 	//append only
#define EXT2_NODUMP_FL 0x00000040 	//do not dump/delete file
#define EXT2_NOATIME_FL 0x00000080	// do not update .i_atime
#define EXT2_DIRTY_FL 0x00000100 //Dirty (modified)
#define EXT2_COMPRBLK_FL 0x00000200 //compressed blocks
#define EXT2_NOCOMPR_FL 0x00000400 //access raw compressed data
#define EXT2_ECOMPR_FL 0x00000800 //compression error
#define EXT2_BTREE_FL 0x00010000  //b-tree format directory
#define EXT2_INDEX_FL 0x00010000 //hash indexed directory
#define EXT2_IMAGIC_FL 0x00020000 //AFS directory
#define EXT3_JOURNAL_DATA_FL 0x00040000 //journal file data
#define EXT2_RESERVED_FL 0x80000000 //reserved for ext2 library

#define EXT2_FT_UNKNOWN 0 //Unknown File Type
#define EXT2_FT_REG_FILE 1 //Regular File
#define EXT2_FT_DIR 2 //Directory File
#define EXT2_FT_CHRDEV 3 //Character Device
#define EXT2_FT_BLKDEV 4 //Block Device
#define EXT2_FT_FIFO 5 //Buffer File
#define EXT2_FT_SOCK 6 //Socket File
#define EXT2_FT_SYMLINK 7 //Symbolic Link

/*
#define EXT2_SECRM_FL 0x00000001 //secure deletion
#define EXT2_UNRM_FL 0x00000002 //record for undelete
#define EXT2_COMPR_FL 0x00000004 //compressed file
#define EXT2_SYNC_FL 0x00000008 //synchronous updates
#define #define EXT2_IMMUTABLE_FL 0x00000010 //immutable file
#define EXT2_APPEND_FL 0x00000020 //append only
#define EXT2_NODUMP_FL 0x00000040 //do not dump/delete file
#define EXT2_NOATIME_FL 0x00000080 //do not update .i_atime
#define EXT2_DIRTY_FL 0x00000100 //dirty (file is in use?)
#define EXT2_COMPRBLK_FL 0x00000200 //compressed blocks
#define EXT2_NOCOMPR_FL 0x00000400 //access raw compressed data
#define EXT2_ECOMPR_FL 0x00000800 //compression error
#define EXT2_BTREE_FL 0x00010000 //b-tree format directory
#define EXT2_INDEX_FL 0x00010000 //Hash indexed directory
#define EXT2_IMAGIC_FL 0x00020000 //?
#define EXT3_JOURNAL_DATA_FL 0x00040000 //journal file data
#define EXT2_RESERVED_FL 0x80000000 //reserved for ext2 implementation
 */

/***********************/

//EXT2 SUPERBLOCK STRUCTURE
struct ext2_super_block {
	__u32 s_inodes_count; 		/* Inodes count */
	__u32 s_blocks_count; 		 /* Blocks count */
	__u32 s_r_blocks_count;		 /* Reserved blocks count */
	__u32 s_free_blocks_count;	 /* Free blocks count */
	__u32 s_free_inodes_count;	 /* Free inodes count */
	__u32 s_first_data_block; 	/* First Data Block [always 1 --pls]*/
	__u32 s_log_block_size; 	/* Block size */
	/* s_log_block_size expresses block size as a power of 2, using 1024
	 * bytes as the unit. So 0 would be a 1024-byte block, 1 a 2048-byte
	 * block, etc. Note that the fragmentation stuff (below) is not yet
	 * implemented --pls */
	__s32 s_log_frag_size; 		/* Fragment size */
	__u32 s_blocks_per_group; 	/* # Blocks per group */
	__u32 s_frags_per_group; 	/* # Fragments per group */
	__u32 s_inodes_per_group; 	/* # Inodes per group */
	__u32 s_mtime; 			/* [last] Mount time */
	__u32 s_wtime; 			/* Write time */
	/* fields below cause the filesystem checker (ext2fsck) to
	 * run after a predefined number of mounts or a certain amount of
	 * time has passes since the last check. --pls */
	__u16 s_mnt_count; 		/* Mount count */
	__s16 s_max_mnt_count; 		/* Maximal mount count [before check]*/
	__u16 s_magic; 			/* Magic signature */
	__u16 s_state; 			/* File system state */
	__u16  s_errors; 		/* Behaviour when detecting errors */
	__u16 s_minor_rev_level;	/* minor revision level */
	__u32 s_lastcheck; 		/* time of last check */
	__u32 s_checkinterval; 		/* max. time between checks */
	__u32 s_creator_os; 		/* OS */
	__u32 s_rev_level; 		/* Revision level */
	__u16 s_def_resuid;		/* Default uid for reserved blocks*/
	__u16 s_def_resgid; 		/* Default gid for reserved blocks */
	__u8 s_prealloc_blocks; 	/* Nr of blocks to try to preallocate*/
	__u8 s_prealloc_dir_blocks; 	/* Nr to preallocate for dirs */
	__u16 s_padding1; 		/* Padding to the end of the block */
	__u32 s_reserved[204];
};

//EXT2 superblock operations
static struct super_operations ext2_sops = {
read_inode: ext2_read_inode,
	    write_inode: ext2_write_inode,
	    put_inode: ext2_put_inode,
	    delete_inode: ext2_delete_inode,
	    put_super: ext2_put_super,
	    write_super: ext2_write_super,
	    statfs: ext2_statfs,
	    remount_fs: ext2_remount,
};

// structer for group description table
struct ext2_group_desc
{
	__u32 bg_block_bitmap; 		/* [number of] Blocks bitmap block */
	__u32 bg_inode_bitmap; 		/* [number of]Inodes bitmap block */
	/* the next field actually holds the block number of the first block
	 * of the inode table --pls*/
	__u32 bg_inode_table; 		/* Inodes table block */
	__u16 bg_free_blocks_count; 	/* Free blocks count */
	__u16 bg_free_inodes_count; 	/* Free inodes count */
	__u16 bg_used_dirs_count; 	/* Directories count */
	__u16 bg_pad; 			/* alignment to word boundary --pls*/
	__u32 bg_reserved[3];  		/* nulls to pad out 24 bytes --pls*/
};

// Inode structure for ext2 file system
struct ext2_inode {
	__u16 i_mode;		 /* File mode */
	__u16 i_uid; 		/* Low 16 bits of Owner Uid */
	/* The highest-order bit of i_size is not used, effectively limiting
	 * the file size to 2GB, though there are ways of getting around this
	 * on certain 64-bit architectures. --pls */
	__u32 i_size; 		/* Size in bytes */
	__u32 i_atime;		/* [last] Access time */
	__u32 i_ctime; 		/* Creation time */
	__u32 i_mtime; 		/* Modification time */
	__u32 i_dtime; 		/* Deletion Time */
	__u16 i_gid; 		/* Low 16 bits of Group Id */
	__u16 i_links_count; /* Links count */
	/* Note that each file is currently stored in a whole number of
	 * blocks, so an empty file will start out with one block.
	 * This may change when/if fragmentation is implemented --pls*/
	__u32 i_blocks; 	/* Blocks count */
	__u32 i_flags; 		/* File flags */

	//union...osd1; 		/* big union to hold os-specific stuff --pls*/

	//linux os sysytems
	__u32 i_block[EXT2_N_BLOCKS]; /* Pointers to [data] blocks */
	__u32 i_generation; 	/*File version (for NFS) */
	__u32 i_file_acl; 	/*File ACL */
	__u32 i_dir_acl; 	/*Directory ACL */
	__u32 i_faddr; 		/*Fragment address */

	//union...osd2, 		/*big union to hold os-specific stuff --pls*/

};

// structure of the directory
struct ext2_dir_entry_2 {
	__u32 inode; 			/* Inode number */
	__u16 rec_len; 			/* Directory entry length */
	__u8 name_len; 			/* [actual] Name length */
	__u8 file_type; 		/* for example. 
					   1 is regular file, 
					   2 is directory, 
					   5 is named pipe--pls*/
	char  name[EXT2_NAME_LEN];	/* File name */
};

