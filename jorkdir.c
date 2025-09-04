// i name it jorkdir cuz readdir already exists in dirent apparently
// i love jorking it
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef _WIN32
	#include <windows.h>
	
	char**jorkdir(char*dir,int*sz) {
		char**res=NULL;
		HANDLE hJorker = INVALID_HANDLE_VALUE;
		int realSz = 0;
		bool didJork = false;
		WIN32_FIND_DATA*jorked=malloc(sizeof(WIN32_FIND_DATA));
		char*sanitarySrc=malloc(strlen(dir)+1);
		memset(jorked, 0, sizeof(WIN32_FIND_DATA));
		strcpy(sanitarySrc,dir);
		if(!((dir[strlen(dir)-1]=="/"[0])||(dir[strlen(dir)-1]=="\\"[0]))) {
			sanitarySrc=realloc(sanitarySrc,strlen(sanitarySrc)+2); // strlen excludes null terminator, and +1 for "\\"
			sanitarySrc[strlen(sanitarySrc)-1]="\\"[0];
		}
		// it SURELY shouldnt end with "*" now cuz the dir is supposed to be dir to search, not a search pattern
		sanitarySrc=realloc(sanitarySrc,strlen(sanitarySrc)+2);
		sanitarySrc[strlen(sanitarySrc)-1]="*"[0];
		sanitarySrc[strlen(sanitarySrc)] = 0;
		hJorker=FindFirstFile(sanitarySrc,jorked); // not exactly a jork, but ok ig
		while ((!(didJork))||(FindNextFile(hJorker,jorked)!=0)) { // mmhhhhhh yes im DELIGHTFULLY jorking it
			didJork = true; // aka "unsafety the flag, please"
			if(!(strcmp(jorked->cFileName,".")))continue;
			res=realloc(res,(++realSz)*sizeof(char*));
			res[realSz-1]=malloc(strlen(jorked->cFileName)+1);
			strcpy(res[realSz-1],jorked->cFileName);
		}
		*sz=realSz;
		free(jorked);
		free(sanitarySrc);
		return res;
	}
#else
	#include <linux/limits.h> // this is for MAX_PATH btw
	#include <dirent.h>
	
	char**jorkdir(char*dir,int*sz) {
		char**res=NULL;
		int realSz = 0;
		struct dirent*jorked = NULL;
		DIR*dObj = opendir(dir);
		while((jorked=readdir(dObj))!=NULL){ // I AM FUCKING JORKING IT BABYYYYEAHHHHHH
			if(!(strcmp(jorked->d_name,".")))continue;
			res=realloc(res,(++realSz)*sizeof(char*));
			res[realSz-1]=malloc(strlen(jorked->d_name)+1);
			strcpy(res[realSz-1],jorked->d_name);
		}
		*sz=realSz;
		closedir(dObj);
		return res;
	}
#endif