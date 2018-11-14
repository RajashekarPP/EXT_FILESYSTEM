#include"headers.h"

int read_dir(int fd , int root_inode)
{
	direntry_table = (ext2_dir_table *)calloc(1,sizeof(ext2_dir_table) );
	if(!direntry_table)
	{	
		puts("memory allocation failed");
		perror("calloc ");
	}

	if(lseek(fd, inode_t[root_inode-1].i_block[0] * 1024, SEEK_SET) != inode_t[root_inode-1].i_block[0] * 1024)
	{
		perror("lseek");
		return -1;
	}

	// read the directory entry table
	if(read(fd, direntry_table, sizeof(ext2_dir_table)) != sizeof(ext2_dir_table))
	{
		perror("read");
		return -1;
	}

	return 0;
}
