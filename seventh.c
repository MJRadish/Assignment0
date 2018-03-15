#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char* String;
void insertFIND(char C);
char* FindLast;
void printFIND();

int main(int argc, char**argv){

if(argc<1){
printf("error");
exit(0);
}
int j=1;
char* G = malloc(sizeof(char));
G[0]='\0';
while(j<argc){
strcat(G,argv[j]);
strcat(G," ");
j++;
}

FindLast = malloc(256*sizeof(char));

//String = malloc(256*sizeof(char));
//NEW=malloc(500*sizeof(char));
//int count2=0;
int count=0;
//printf("Enter a string \n");

String=G;

//count = scanf("%[^\n]%*c",String);
//String containa all characters...
//if(count ==-1){

//return 0;
//}

count=0;

int i=0;
while(String[i]!='\0'){
//printf("%c",String[i]);
i++;
count++;
}

//printf("Count: %d, Last char: %c", count, String[count]);
////This is actual size of string including null terminator
//

int c=0;
char* S = malloc(2*sizeof(char));
char* Sprev = malloc(2*sizeof(char));
char* temp = malloc(2*sizeof(char));
while(String[c]!='\0'){
S[0]=String[c];

if(c==0){
Sprev[0]=S[0];
}

else{ 
temp[0]=String[c-1];
if(temp[0]!=S[0]){
Sprev[0]=temp[0];
}
}
printf("\nS:%c,Sprev:%c\n",S[0],Sprev[0]);
if(S[0]==' '){

insertFIND(Sprev[0]);

}
else if(S[0]==String[count-1]&&c==count-1){
insertFIND(S[0]);

}

c++;
}


printFIND();

//free (FindLast);
free (S);
free (Sprev);
free (temp);
//free (String);

return 0;
}



void insertFIND(char C){
int t=0;
while(FindLast[t]!='\0'){
t++;
}
//printf("Data added:%c to:%c", C, FindLast[t]);
FindLast[t]=C;
return;
}

void printFIND(){
int r=0;
while(FindLast[r]!='\0'){
printf("%c",FindLast[r]);
r++;
}
return;
}

