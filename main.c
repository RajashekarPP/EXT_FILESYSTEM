
#include"headers.h"

#define ARG_FILE 1
#define ARG_CMD  2  // ls cp cd
#define ARG_DIR  3  // path of the directory

#define ARG_SRC  3 //source file
#define ARG_DES	 4 //destination file 


int main(int argc , char **argv)
{
	int fd,root_inode;
	
	if(argc < 2)
	{
		puts("Insufficient arguments");
		puts("./ext2fs file_system file_cmd");
	}	
	
	fd = open(argv[ARG_FILE],O_RDONLY);
	if(fd == -1)
	{
		printf("unable to open the file\n");
		perror("open : ");
		return -1;
	}

	root_inode = EXT2_ROOT_INO; // root inode no is 2


	if(argc > ARG_CMD)
	{
		if(!strcpm(argv[ARG_CMD] , "ls"))
		{
			//call ls function		
		}
		else if(!strcmp(argv[ARG_CMD] , "cp"))
		{
			if(argc < 5)
			{
				puts("ERROR : Insufficient arguments");	
				printf("./ext2fs file_system cp src_file dest_file\n");
				return -1
			}
			//call cp command
				
		}		
		
		else if(!strcmp(argv[ARG_CMD],"cd"))
		{
			if(argc < 4)
			{
				puts("ERROR : Insufficient arguments");
				puts("./ext2fs file_system cd directory_path");
				return -1;
			}
			// call cd command 
		}		
		else 
		{
			printf("
		}
	}

	close(fd);
	
	return 0;
}

