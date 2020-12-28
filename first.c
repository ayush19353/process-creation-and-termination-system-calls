#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>



int main()
{int red;
pid_t pid=fork();
int* dd;

char buf[6864-79];
char* gff[400];
char* gfa[400];
char *p;
int file1=open("file.csv",O_RDONLY);
 red=lseek(file1,79,SEEK_SET);
if(file1!=-1)
{


 
if(pid<0)
{


	printf("%s\n","No child process created" );
}






else if(pid==0)
{
//for(int ab=0;ab<400;ab++)
	//{printf("%s\n",gfa[ab] );}


red=read(file1,buf,6864);
//printf("%s \n",buf );
if(red!=-1)
{
char* liner[400];

 p=strtok(buf,"\n");
 int hg=0;
while(p!=NULL)
{
	//printf("%s\n",p );
	//strcpy(liner[hg],p);
	gff[hg]=p;
	gfa[hg]=p;
//	strcpy(liner[hg],gff[hg]);
	//printf("%s\n",liner[hg]);
	hg++;
	p=strtok(NULL,"\n");
	//hg++;
}




double avg[400];
for(int i=0;i<400;i++)
{
char* op;
op=strtok(gff[i],",");
int as=0;
int kg=0;int sum=0;
while(op!=NULL)
{if(kg==1)
	{
if(*op=='B')
	{as=1;
		break;}
	}
	//printf("%s\n",op );
	if(kg!=0 && kg!=1)
	{
sum=sum+atoi(op);
	}
	
	op=strtok(NULL,",");
	kg++;

}//printf("%d\n",sum );
if(as==1)
{avg[i]=0;}
else
{
avg[i]=(double)sum/4;}



}
FILE *fp1;
char stra[200];
fp1=fopen("file.csv","r");
fgets(stra,200,fp1);
for(int jh=0;jh<200;jh++)
{
	fgets(stra,200,fp1);
printf("Student %d ->>  %s",jh+1,stra);
	//	printf("%s ",gfa[jh]);
	
	printf("Average score of Student %d ->> %f \n",jh+1,avg[jh] );
printf("%s\n","____________________________");
}
fclose(fp1);

exit(0);

}else
printf("%s\n","Error while reading" );

}
else if(pid>0)
{


waitpid(pid,dd,0);
printf("%s\n","_____________________________________________________________________" );
red=read(file1,buf,6864);
//printf("%s \n",buf );
if(red!=-1)
{
 p=strtok(buf,"\n");
 int hg=0;
while(p!=NULL)
{
	//printf("%s\n",p );
	gff[hg]=p;
	gfa[hg]=p;
	p=strtok(NULL,"\n");
	hg++;
}
double avg1[400];
for(int i=0;i<400;i++)
{
char* op;
op=strtok(gff[i],",");
int as=0;
int kg=0;int sum=0;
while(op!=NULL)
{if(kg==1)
	{
if(*op=='A')
	{as=1;
		break;}
	}
	//printf("%s\n",op );
	if(kg!=0 && kg!=1)
	{
sum=sum+atoi(op);
	}
	
	op=strtok(NULL,",");
	kg++;

}//printf("%d\n",sum );
if(as==1)
{avg1[i]=-2;}
else
{
avg1[i]=(double)sum/4;}



}

FILE *fp1;
char stra[200];
fp1=fopen("file.csv","r");

for(int ggd=0;ggd<201;ggd++)
{
fgets(stra,200,fp1);}
for(int jh=200;jh<400;jh++)
{
	fgets(stra,200,fp1);
printf("Student %d ->>  %s",jh+1,stra);
	//	printf("%s ",gfa[jh]);
	
	printf("Average score of Student %d ->> %f \n",jh+1,avg1[jh] );
printf("%s\n","____________________________");
}
fclose(fp1);




}
else 

printf("%s\n","error while reading" );
}}
else
{
	printf("%s\n","file not found or opened" );
}



return 0;}








