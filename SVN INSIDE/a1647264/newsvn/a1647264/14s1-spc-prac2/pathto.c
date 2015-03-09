#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void pathto(char* path)
{
	char* child_name;
	int inum_count = 0;

	// Create the parent directory from the child directory (concatenate /..)
	char path_buff[256];
	strncpy(path_buff, path, sizeof(path_buff));
	strncat(path_buff,"/..", sizeof(path_buff));

	struct stat childStat;
	stat(path,&childStat);
	int child_inum = childStat.st_ino;
	long child_dev = childStat.st_dev;



	struct dirent *parent_dirent;
    	DIR *parent_dirp;
	parent_dirp = opendir(path_buff); // The parent directory

	while ((parent_dirent = readdir(parent_dirp)) != NULL) 
	{
		// Adding the path to the name of the file
		char path_buff_2[256];
		strncpy(path_buff_2, path_buff, sizeof(path_buff_2));
		strncat(path_buff_2,"/", sizeof(path_buff_2));
		strncat(path_buff_2,parent_dirent->d_name, sizeof(path_buff_2));
		// ---------------------------------------
		
		
		struct stat whileStat;
		stat(path_buff_2,&whileStat);

		if (whileStat.st_ino == child_inum && whileStat.st_dev == child_dev)
		{
			child_name = parent_dirent->d_name;
			inum_count++;
		}
		
		if(inum_count == 2)
		{	
			// If there is ever 2 links (both . and ..) have the same I-NUM
			// we are in the root and are finished!
			return;
		}
	}
	pathto(path_buff);
	printf("/%s",child_name);
}

int main(int argc, char **argv)
{
	if(argc <= 1)
	{
		pathto(".");
		printf("/");
		return 1;
	}
	else
	{
		struct stat fileStat;
		stat(argv[1],&fileStat);
		if(S_ISDIR(fileStat.st_mode))
		{
			pathto(argv[1]);
			printf("/");
		}
		else if(S_ISREG(fileStat.st_mode))
		{
			if( strchr(argv[1],'/')!=NULL)
			{
				// Grab whatever is found before the last slash, this is the path
				const char *ptr = strrchr(argv[1], '/');
				int index = ptr - argv[1];
				char directory_string[index+1];

				strncpy(directory_string, argv[1], index);
				directory_string[index+1] = '\0';


				char file_string[(strlen(argv[1])-index)+1];
				strncpy(file_string, argv[1]+index+1, (strlen(argv[1])-index));	
				
				pathto(directory_string);
				printf("/");
				printf("%s",file_string);
			}
			else
			{
				pathto(".");
				printf("/");
				printf("%s",argv[1]);
			}
		}
	}
	
}


