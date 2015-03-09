#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char **argv)
{

	DIR *directory_point;
	
	if(argc <= 1)
	{
    		directory_point = opendir("./");
	}
	else
	{
		directory_point = opendir(argv[1]);
	}
}

char * path_search(char* path_old)
{

	

}

