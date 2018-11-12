#include"headers.h"

int superblock_info(int fd)
{

//	char buf[10000];
	struct ext2_super_block *sb=NULL; 

	sb= malloc(sizeof(struct ext2_super_block));

//	lseek(fd,1024,SEEK_CUR);
	printf("offset = %lu \n",lseek(fd,1024,SEEK_CUR));
	if( read(fd,sb,sizeof(struct ext2_super_block)) <0 )	
	{
		printf("READ has been  failed:\n");
		perror("read : ");
		return -1;
	}	

	printf("s_inodes_count = %lu \n",sb->s_inodes_count);
	printf("s_inodes_per_group = %lu \n",sb->s_inodes_per_group);
	printf("s_free_inodes_count = %lu \n",sb->s_free_inodes_count);
return 0;
}

int block_group_descriptor_t_info(int fd)
{
	struct ext2_group_desc *g_desc=NULL;
	
	g_desc = malloc(sizeof(struct ext2_group_desc));

	printf("offset = %lu \n",lseek(fd,1024,SEEK_CUR));
	//lseek(fd,2048,SEEK_CUR)
	printf("dir count = %d\n",g_desc->bg_used_dirs_count);
	printf("bg_free_inodes_count = %d\n",g_desc->bg_free_inodes_count);
		
	return 0;

}
