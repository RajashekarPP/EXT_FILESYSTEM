#include"headers.h"

int superblock_info(int fd)
{

//	char buf[10000];
	//struct ext2_super_block sb; 

	sb= (struct ext2_super_block *)calloc( 1, sizeof(struct ext2_super_block) );

	if(sb == NULL)
	{
		puts("memory allocation failed");
		perror("calloc ");
	}
//	lseek(fd,1024,SEEK_CUR);

//printf(" ** size of spr block is %lu \n",sizeof(struct ext2_super_block));

//	printf("fd = %d\n",fd);
	printf("offset address at = %lu \n",lseek(fd,1024,SEEK_SET));

//	if( read(fd,&sb,sizeof(struct ext2_super_block)) < 0 )	

	if( read(fd,sb,sizeof(*sb)) < 0 )	
	{
		printf("READ has been  failed:\n");
		perror("read : ");
		return -1;
	}	

//printf("%x \n",);
	if(sb->s_magic != EXT2_SUPER_MAGIC)
	{
		printf("sb.s_magic = %x \n",sb->s_magic);
		puts("Bad filesystem mount properly");
		return -1;
	}
	printf("sb.s_magic = %x \n",sb->s_magic);
	printf("s_inodes_count = %u\n",sb->s_inodes_count);
	printf("s_blocks_count = %u\n",sb->s_blocks_count);
	printf("s_inodes_per_group = %u\n",sb->s_inodes_per_group);
	printf("s_free_inodes_count = %u\n",sb->s_free_inodes_count);
	return 0;
}

int block_group_descriptor_t_info(int fd)
{

	
	g_desc = (struct ext2_group_desc *)calloc(1 ,sizeof(struct ext2_group_desc));

	printf("offset address at = %lu \n",lseek(fd,2048,SEEK_SET));

	//lseek(fd,2048,SEEK_CUR);
	if( read(fd ,g_desc , sizeof(*g_desc) ) != sizeof(*g_desc) )
	{
		perror("read ");
		return -1;
	}
	printf("directory count = %d\n",g_desc->bg_used_dirs_count);
	printf("bg_free_inodes_count = %d\n",g_desc->bg_free_inodes_count);
		
	return 0;

}
