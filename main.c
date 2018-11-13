/*
	Before runnig the main program some of the command line executions are
	dd  if=/dev/zero op=ext2fs.img bs=1024 count=10240 //for 10MB
	mkfs.ext2 ext2fs.img
	sudo mount ext2fs.img ./
*/

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
	perror("fd ");

	printf("fd = %d\n",fd);

	if(fd == -1)
	{
		printf("unable to open the file\n");
		perror("open ");
		return -1;
	}

	root_inode = EXT2_ROOT_INO; // root inode no is 2


	// read superblock                                                           
	if(superblock_info(fd) == -1)                                                
	{                                                                            
		printf("Superblock reading failed\n");                                  
		return -1;                                                              
	}                                                                            

	// read block group descriptor table                                         
	if( block_group_descriptor_t_info(fd) == -1)                                 
	{                                                                            
		printf("Block Group Descriptor Table Building failed\n");               
		return -1;                                                              
	}                                                                            

	// read inode table                                                          
	if(inode_table_info(fd) == -1)                                               
	{                                                                            
		printf("Inode Table Building failed\n");                                
		return -1;                                                              
	}                                                                            

	// read directory entry table                                                
	if(read_dir(fd, root_inode) == -1)                                            
	{                                                                            
		printf("Directory Entry Table failed\n");                               
		return -1;                                                              
	}   


	if(argc > ARG_CMD)
	{
		if(!strcmp(argv[ARG_CMD] , "ls"))
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
				return -1;
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

