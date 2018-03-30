//Non-Static Array Second Assignment
//Hash function was provide by: https://github.com/aappleby/smhasher/tree/master/src

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

void addData(int data);
char* readData(int file);
void printData();
void printArray();

/*void LessThanPER(int ptr, int prev, int Array[], int data);
void LessThanPNER(int ptr, int prev, int Array[], int data );
void GreaterThanPER(int ptr, int prev, int Array[], int data);
*/
void Selectsort();
char* AllData;
int size;
int* Array;
//int A[0];

int main(int argc, char*argv[]){//Read File
//int Determinant = 0;

int fileOp = open(argv[1],O_RDONLY);

if(fileOp == -1){
printf("Error");
return 0;
}else if(fileOp==0){
			//EMPTY FILE
printf("Error");

close(fileOp);

return 0;

}
else {// Create Buffer Reader
//Check
readData(fileOp);
//char* AllData = (char*)malloc(sizeof(char));
//printf("AllData first: %c\n", AllData);

if(AllData==NULL){
//NO DATA COULD BE READ!!

return 0;
}
char* str = (char*)malloc(sizeof(char));
str[0] = AllData[0]; 
size = atoi(str);
//printf("Size of AAAAAAray: %d", size);

//Now create arrray!!
//
//int A[];
//
//size=1;

Array=malloc(size*sizeof(int));

//GOOD

size=0;

int idx = 1;
//int y = 0;

/////////////////////////////////////////////
while(AllData[idx]!='\0'){
printf("CHAR :%c",AllData[idx]);
if(isdigit(AllData[idx])){
int f = idx;
//printf("MADE IT\n");
//printf("Char: %c",AllData[idx]);
char* string = malloc(sizeof(char));
string[0]='\0';
char* app = malloc(sizeof(char));
app[0]='\0';
//app[0]=AllData[f];
//app[1]='\0';
//f=idx;
//int t = 0;
while(isdigit(AllData[f])&&AllData[f]!='\0'){
printf("\nChar 2:%c\n",AllData[f]);
app[0]=AllData[f];
strcat(string,app);
f++;
}
printf("\nThe String: %s", string);
int value = atoi(string);
printf("VALUE %d\n",value);
//ADD VALUE TO ARRAY!!!!
addData(value);
//printf("VALUER!!
idx=f;
}
idx++;

}


//free(A);
printArray();
free(Array);
//ADD MORE MEMORY!!!
//
}
//free(A);
close(fileOp);
return 0;
}



void addData(int data){

if(size==0){
//printf("NULL FIRST");
Array[0] = data;
size++;
printf("size FIRST:%d\n",size);

printArray();
return;
}

//////////////////////////////////////////////////ERROR HERRRRRRRRRR

//int r=0;
int SIZENEW = size+1;
printf("Siz NEW: %d\n", SIZENEW);

Array= (int*)realloc(Array,(SIZENEW)*sizeof(int));

if(Array==NULL){

printf("error");

exit(0);
//return;

}

*(Array+size)=data;

size++;



printf("BEFORE SORT\n");

printArray();

Selectsort();

printf("AFTER SORT\n");
printArray();

return;
}



char* readData(int file){
	int determinant = 0;
	char* piece = (char*)malloc(100*sizeof(char));
	if(piece==NULL){
	return NULL;
	}
	
	int go = 0;
	while(go<100){piece[go] = '\0';
	go++;
	}

	int Checkit = 1;
	
	do{
	Checkit = read(file,piece,99*sizeof(char));
	
	if(Checkit==-1){
	return NULL;
	}
	if(determinant == 0){
	AllData=(char*)malloc(100*sizeof(char));
	}

	else{
	
	char* ptr  = realloc(AllData,100*sizeof(char));
	if(ptr==NULL){
	return NULL;	
	}
	
	}
	
	int startp = 0;
	int t = determinant;
	
	while(piece[startp]!='\0'){
	AllData[t]=piece[startp];
	t++;
	startp++;
	}
	//Final Data
	AllData[t]='\0';
	determinant = determinant + Checkit;
	printf("Check??%d\n",Checkit);
	//WHY??
	Checkit=read(file,piece,99*sizeof(char));
	//Double check!!!
	}while(Checkit!=0);
	return AllData;
}

void printData(){
if(AllData==NULL){
return;
}
int e = 0;

while(AllData[e]!='\0'){
printf("%c",AllData[e]);
e++;
}



return;
}

void printArray(){
if(size==0){
printf("0");
return;
}

int e=0;
int SIZE = size;
while(e<SIZE){
if(Array[e]=='0'){
printf("0 ");
}
else{
printf("%d ",Array[e]);
	}
e++;
}

return;
}

void Selectsort(){
int SIZE = size;
int i = 0;
int k = 0;
int place;
int data;
int temp;
for(i = 0; i<SIZE; i++){
   for(k=i;k<SIZE;k++){
	if(Array[i]>Array[k]){
	//Switch
	temp = Array[i];
	Array[i]=Array[k];
	Array[k]=temp;
	}
      }
	}	
return;
}
