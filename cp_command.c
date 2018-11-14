#include "headers.h"

__le32 findSrcFile(__le32 fd, __le8 *src, __le32 type, __le32 root_ino)
{
   __le8 *filname;
   __le32 fil_ino_num;
   __le32 filtype;

   while(direntry_table->inode)
   {
	filname = (__le8 *)calloc(1,direntry_table->name_len+1);
	if(filname == NULL)
	{
		printf("ERROR: Memory allocation failed\n");
		return -1;
 	}
	
	fil_ino_num = direntry_table->inode;
	filtype = direntry_table->file_type;
 	strncpy(filname, direntry_table->name, direntry_table->name_len);

	if(filtype == type)
	{
		if(!strcmp(filname,src))
		{
			free(filname);
			return fil_ino_num;
		}
	}

	lseek(fd, (direntry_table->rec_len - sizeof(ext2_dir_table)), SEEK_CUR);

	if(read(fd, direntry_table, sizeof(ext2_dir_table)) != sizeof(ext2_dir_table))
 	{
        	perror("read");
		free(filname);
		return -1;
	}
   	free(filname);
   }
   return -1;   
}

__le32 copyDestFile(__le32 fd, __le8 *dest, __le32 src_fil_ino)
{
   __le32 dest_fd;
   __le8 *buffer;
   __le32 size = inode_t[src_fil_ino-1].i_size;

   buffer = (__le8 *)calloc(1, size+1);
   if(buffer == NULL)
   {
	printf("ERROR: Memory allocation failed\n");
	return -1;
   }

   if(lseek(fd, (inode_t[src_fil_ino-1].i_block[0] * 1024), SEEK_SET) != (inode_t[src_fil_ino-1].i_block[0] * 1024))
   {
	perror("lseek");
	free(buffer);
	return -1;
   }
   
   if(read(fd, buffer, size) != size)
   {
	perror("read");
	free(buffer);
	return -1;
   }

//   printf("%d\n",inode_t[src_fil_ino-1].i_size);

   dest_fd = open(dest, O_WRONLY|O_CREAT|O_TRUNC);
   if(dest_fd == -1)
   {
	perror("open");
	free(buffer);
	return -1;
   }

   if(write(dest_fd, buffer, strlen(buffer)) != strlen(buffer))
   {
	perror("write");
	free(buffer);
	return -1;
   }
   free(buffer);
   close(dest_fd);
   return 0;
}

void cp(__le32 fd, __le8 *src, __le8 *dest, __le32 root_ino)
{
   __le32 ret_ino, ret_cp;
   
   ret_ino = findSrcFile(fd, src, EXT2_FT_REG_FILE, root_ino);
   if(ret_ino == -1)
   {
	printf("File %s not found\n",src);
   }
   else
   {
	ret_cp = copyDestFile(fd, dest, ret_ino);
	if(ret_cp == -1)
	{
		printf("Copying %s to %s failed\n", src, dest);
	}
	else
	{
		printf("Copying file Successful\n");
	}
   }
	return;
}
