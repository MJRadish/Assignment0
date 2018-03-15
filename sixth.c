#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
char* String;
char* NEW;
void insertNEW(int data, char C);
void printAll(char* Arr);

int main(int arv, char**argc){
if(arv<2||arv>2){
printf("Not enough arguments or too many arguments");
return -1;
}

//String = malloc(256*sizeof(char));
//bzero(String,1);
NEW=malloc(500*sizeof(char));
//bzero(NEW,500);
int count2=0;
int count=0;
//printf("Enter a string \n");
//count = scanf("%[^\n]%*c",argc[1]);
//strcat(String,argc[1]);
String=argc[1];
if(count ==-1){
return 0;
}

count=0;

int i=0;
while(String[i]!='\0'){
i++;
count++;
}

printf("Count: %d", count);
//This is actual size of string including null terminator

int e=0;
while(e<count){
NEW[e]='\0';
e++;
}

int j=0;
int k=0;
int s=0;
char*S=malloc(2*sizeof(char));
S[0]=String[0];


while(s<count){
S[0]=String[s];
if(atoi(S)==1||atoi(S)==2||atoi(S)==3||atoi(S)==4||atoi(S)==5||atoi(S)==6||atoi(S)==7||atoi(S)==8||atoi(S)==9||S[0]==' ')
{
printf("error");
return 0;
}
s++;
}
//All ERRORS CHECKED

char* Concat = malloc(256*sizeof(char));
int Scount =0;
int LengthNew=0;
int compCount=0;
int temp =0;
char* S2=malloc(2*sizeof(char));
for(j=0;j<count;j++){
	
	//printf("J:%d, count:%d",j,count);
	S[0]=String[j];
	temp=j;
	while(S[0]==String[j]){
	//printf("%d",compCount);	
	j++;
	compCount++;
	}
	LengthNew+=compCount;
	j=temp+compCount-1;
	//Here is could is the one char
	//printf("Count of %c:%d",S[0],compCount);
	insertNEW(compCount,S[0]);	
	
	compCount=0;
}
printf("\n");
printf("OrigCount: %d\n", LengthNew);
//print out the new concat
//then count it!!
int r=0;
//printf("\n");
while(NEW[r]!='\0'){
//printf("%c",NEW[r]);
r++;
}
//printf("\n");
printf("Compared to r: %d\n",r);
//size of NEW
if(r>LengthNew){
printAll(String);

}
else{
printAll(NEW);
}

//free(String);
//free(NEW);

return 0;

}

void insertNEW(int data, char C){
int t=0;
char* d = malloc(500*sizeof(char));
while(NEW[t]!='\0'){

t++;
}

sprintf(d, "%d",data);

//printf("LENGTHHHHHHHH:%s", d);
//Here is where to add, at end!
//printf("HERE:%c,put this here%c", NEW[t],d);

NEW[t]=C;

int h=0;

while(d[h]!='\0'){
NEW[t+1+h]=d[h];
h++;
}
//NEW[t+1]=d;

free(d);
return;
}
void printAll(char* Arr){
int q=0;

while(Arr[q]!='\0'){
printf("%c",Arr[q]);
q++;
}

return;
}
