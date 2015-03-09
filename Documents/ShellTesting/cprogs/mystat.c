#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>



int main(int argc, char **argv)
{
	int i;
	
		for(i=1;i<argc;i++)
		{
		printf("%s", argv[i]);
		struct stat myStat;

		

	    	if(stat(argv[i],&myStat) < 0)
		{
			
			return 1;
		}   
	
		printf("%d ",myStat.st_ino);
	
		// User Permissions 
		if(S_ISDIR(myStat.st_mode))
			printf("d");
		else
			printf("-");

		if(myStat.st_mode & S_IRUSR)
			printf("r");
		else
			printf("-");

		if(myStat.st_mode & S_IWUSR)
			printf("w");
		else
			printf("-");

		if(myStat.st_mode & S_IXUSR)
			printf("x");
		else
			printf("-");

		// Group permissions

		if(myStat.st_mode & S_IRGRP)
			printf("r");
		else
			printf("-");

		if(myStat.st_mode & S_IWGRP)
			printf("w");
		else
			printf("-");

		if(myStat.st_mode & S_IXGRP)
			printf("x");
		else
			printf("-");

		// Other permissions
		if(myStat.st_mode & S_IROTH)
			printf("r");
		else
			printf("-");
		if(myStat.st_mode & S_IWOTH)
			printf("w");
		else
			printf("-");

		if(myStat.st_mode & S_IXOTH)
			printf("x");
		else
			printf("-");

		printf(" %d ",myStat.st_nlink);
	    	printf("%d\n",myStat.st_size);
	}
}
