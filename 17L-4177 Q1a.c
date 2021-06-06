#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int my_strcmp(char *strg1, char *strg2)
{
    while( ( *strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2 )
    {
        strg1++;
        strg2++;
    }
 
    if(*strg1 == *strg2)
    {
        return 0; // strings are identical
    }
 
    else
    {
	return 1;
    }
}

void _cwd()
{
	
	char cwd[50];
        getcwd(cwd,50);
	printf("%s",cwd);
	printf("\n");
}

void _cd(char input[50])
{
		
	int i=0;
	i=i+3;
	
	char buffer[30];
	int j=0;
	for(;input[i]!='\0';j++)
	{
		buffer[j]=input[i]; //desktop
		i++;
	}
	buffer[j]='\0';
				
	char cwd[80];
        getcwd(cwd,80);
        
        char concat[80];
	strcpy(concat,cwd);
	for(i=0;concat[i]!='\0';i++)
	{}
	concat[i]='/';
	i++;
	for(j=0;buffer[j]!='\0';j++)
	{
		concat[i]=buffer[j];
		i++;
	}
	concat[i]='\0';
		
	i=chdir(concat);
	if(i==-1)
		{printf("Entered directory not available :(\n");}
}

void _ls()
{	
	struct dirent *strc;
    	DIR *dir = opendir("."); 
  	
  	if (dir == NULL)
  	{ 
  	    printf("Could not open current directory" ); 
  	    //return; 
  	} 

  	while ((strc = readdir(dir)) != NULL) 
  	{
		printf("%s\n", strc->d_name); 
	}

  	closedir(dir);
	
}


char g_arr[50];
void _push(char input[50])
{
	//printf("\nINPUT: %s",input);
		
	int i=5;
	char buffer[50];
	int j=0;
	for(;input[i]!='\0';j++)
	{
		buffer[j]=input[i]; 
		i++;
	}
	buffer[j]='\0';	
	//printf("\nbuffer: %s",buffer);
		
	char cwd[80];
        getcwd(cwd,80);
	
	//printf("\ncwd: %s\n",cwd);
	strcpy(g_arr,cwd);
        //printf("\ngarr: %s\n",g_arr);
        char concat[80];
	strcpy(concat,cwd);
	for(i=0;concat[i]!='\0';i++)
	{}
	//concat[i]='/';
	//i++;

	for(j=0;buffer[j]!='\0';j++)
	{
		concat[i]=buffer[j];
		i++;
	}
	concat[i]='\0';
	//printf("\nconcat: %s",concat);	
	i=chdir(concat);
	if(i==-1)
		{printf("Entered directory not available :(\n");}

	
}

void _showtop()
{
	printf("\n%s",g_arr);
}

void _menu()
{
	printf("\n\tMethod for entering Input\n\tcwd Foldername\n\tpwd Foldername\n\tls\n\tpush \\Foldername\n\tpop\n\tpop -showtop\n\tcd Foldername\n\texit\n");
}

void _pop()
{	
	//printf("\nentered pop\n");
	int i;
	i=chdir(g_arr);	
	if(i==-1)
		{printf("Entered directory not available :(\n");}
}



int main()
{

	_menu();
	char input[50];
	while(strcmp("exit",input)!=0)
    	{
		printf("\n17L-4177 - ");
		_cwd();	
    	
		scanf(" %[^\n]s",input);

		//printf("\nINPUT: %s",input);
		char buffer1[5];
		char buffer2[3];
		buffer1[0]=input[0];
		buffer1[1]=input[1];
		buffer1[2]=input[2];
		buffer1[3]=input[3];
		buffer1[4]='\0';
		
		
		buffer2[0]=buffer1[0];
		buffer2[1]=buffer1[1];
		buffer2[2]='\0';
		
		//printf("\nbuffer1: %s",buffer1);
		if(strcmp(buffer1,"push")==0)
		{	
			//printf("\nentered push.\n");
			_push(input);
		}
		if(strcmp(input,"pop")==0)
		{
			_pop();
		}
		if(strcmp("ls",input)==0)
			_ls();
    		if(strcmp("pwd",input)==0)
   			_cwd(); 
	
	    	if(strcmp("cwd",input)==0)
			_cwd();
	
	    	if(strcmp("cd",buffer2)==0)
			_cd(input);   
		if(strcmp("pop -showtop",input)==0)
			_showtop();
	}
	return 0;
}
