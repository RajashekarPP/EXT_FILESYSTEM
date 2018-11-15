#include"headers.h"

int inode_table_info(int fd)
{
	puts("reading the inode structure");
	__u32 block_size = 1024 << sb->s_log_block_size ;//determining the size of each block in the filesystem default 1KB
	
	inode_t = (ext2_inode_table *)calloc(1, (sb->s_inodes_count)*(sb->s_inode_size) );
	if(!inode_t)
	{
		puts("memory allocation failed");
		perror("calloc ");
		return -1;
	}
	
// bg_inode_table this is the block no of the first inode table
	if( lseek(fd , (g_desc->bg_inode_table )*(block_size),SEEK_SET) != (g_desc->bg_inode_table )*block_size )
	{
		perror("lseek ");
		return -1;
	}

	if(read(fd ,inode_t , (sizeof(ext2_inode_table) * (sb->s_inodes_count))) != (sizeof(ext2_inode_table) * (sb->s_inodes_count)) )
	{ 
		perror("read ");
		return -1;
	}
 
	return 0;
}
