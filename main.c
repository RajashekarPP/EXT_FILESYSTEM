
#include"headers.h"

#define ARG_FILE_SYSTEM 1 //type of file system
#define ARG_CMD  2        // ls cp cd
#define ARG_DIR  3        // path of the directory

#define ARG_SRC_FILE 3   //source file
#define ARG_DES_FILE 4   //destination file 


int main(int argc , char **argv)
{
	int fd,root_inode;
	
	if(argc < 2)
	{
		puts("Insufficient arguments");
		puts("./ext2fs file_system file_cmd");
	}	
	
	fd = open(argv[ARG_FILE_SYSTEM],O_RDONLY);
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
			if(ls(fd , root_inode))
				puts("listing of given directory is sucessful");	
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
			if(cp(fd,argv[ARG_SRC_FILE] ,argv[ARG_DES_FILE],root_inode))
				puts("copying has been done sucessfully");				
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
			cd(fd,argv[ARG_DIR],root_inode);
		}		
		else 
		{
			printf("%s : command not found\n",argv[ARG_CMD]);
		}
	}

	close(fd);
	
	return 0;
}

