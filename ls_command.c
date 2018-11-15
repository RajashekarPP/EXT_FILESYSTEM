#include"headers.h"

int ls(int fd , int root_inode)
{
	puts("executing ls command");
	
	while(direntry_table->inode)
	{
		if( strcmp(direntry_table->name ,".") && strcmp(direntry_table->name ,"..") )
		{		
			printf("%-20s",direntry_table->name);
			printf("%u",direntry_table->inode);
			printf("\ttype %u",direntry_table->file_type);
			puts("");
		}	
		lseek(fd, (direntry_table->rec_len - sizeof(ext2_dir_table)), SEEK_CUR);
//		lseek(fd, (direntry_table->rec_len), SEEK_CUR);

		// read the next file information into directory entry table
		if(read(fd, direntry_table, sizeof(ext2_dir_table)) != sizeof(ext2_dir_table))
	 	{
	        	perror("read");
			return -1;
		}

	}	
	puts("");	
	return 0;
}
