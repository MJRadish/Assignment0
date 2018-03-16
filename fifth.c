//Find the magic matrix, which is a matrix which the sum of all of each row,column, and diagonals are equal to the same number.
//EX:
/*1 1 1
  1 1 1	Is a Magic matrix, because the sum of each row is 3, the sum of each column is 3, and the sum of each diagonal is 3.
  1 1 1
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//Any int is greater than 0
char* readData(int file);
void printData();
char* AllData;

int row =0;
int column =0;
int NXN;
//int MATRIX[0][0];
void addData(int data, int row, int column, int ** Matrix);

void printMatrixData(int NXN, int **Matrix);



int main(int argc ,  char** argv){

int Accessed = open(argv[1],O_RDONLY);

if(Accessed==-1){


return 0;
}


else{


readData(Accessed);

char* str = (char*)malloc(sizeof(char));
str[0] = AllData[0];
printf("ALL DATA: %s",AllData);
//return 0;
int size = atoi(str);
NXN = atoi(str);

str[0]=AllData[strlen(AllData)-2];
//int power = atoi(str);
//printf("POWER: %d", power);
//int* MATRIX = malloc(NXN*sizeof(int));
int** MATRIX = malloc(NXN*sizeof(int*));

int q = 0;
while(q<NXN){
MATRIX[q] = malloc(NXN*sizeof(int));
q++;
}

//printf("PRINT");
//printMatrixData(NXN,MATRIX);

int idx = 1;
int y = 0;
row=0;
column = 0;
int nowRow = 0;
int nowColumn=0;
int ALL =0;
while(AllData[idx]!='\0'){
if(isdigit(AllData[idx])){
int f = idx;
//printf("Char: %c",AllData[idx]);

while(AllData[f]!=' '&&AllData[f]!='\0'){
f++;
}
char* string = malloc(f*sizeof(char));
f=idx;
int t = 0;
while(AllData[f]!='\n'&&AllData[f]!=' '&&AllData[f]!='\0'){
string[t]=AllData[f];
t++;
f++;
}

int value = atoi(string);
printf("VALUE %d\n",value);

//addData(value, row,column, MATRIX);
MATRIX[column][row]=value;
column++;
ALL++;
if(column==NXN){
//nowColumn=0;
column=0;
ALL--;
if(row<NXN){
row++;
ALL++;
}
else{
break;
}
}

//if(row<NXN)
//row++;
//printMatrixData(row, column, MATRIX);

//printf("F?? %d", f);
//printf("IDX?? %d", idx);
//printf("AllData location now:%c, Before it??%c", AllData[f],AllData[f-1]);
if(ALL==NXN*NXN){
printf("\nHAVE ALL DATA\n");
break;
}
idx=f;
continue;
}
idx++;
}







printf("PRINT MATRIX");
printMatrixData(NXN,MATRIX);
//return 0;
//Two diagonals, 2* NXN Rows and COLUMNS
int* sums = malloc((2*NXN*sizeof(int))+2*sizeof(int));
 y=0;
while(y<(2*NXN)+2){
sums[y]=0;
printf("\nSUMS of %d: %d\n",y,sums[y]);
y++;
}

//return 0;
y=0;
int i;
int j;
//ALL ROWS AND COLUMNS

for(i=0; i<NXN; i++){
	for(j=0;j<NXN;j++){
	//printf("Sum %d + %d\n", sums[y], MATRIX[j][i]);
	sums[i]+=MATRIX[j][i];
	sums[i+NXN]+=MATRIX[i][j];
	if(i==j){
	//printf("\nDATA MM: %d\n, SLOT: %d",MATRIX[j][i],(2*NXN));	
	sums[(2*NXN)]+=MATRIX[j][i];
	}
	if(i==NXN-1&&j==0){
	int y=j;
	int z = i;
	while(y<NXN&&z>=0){
        sums[2*NXN+1]+=MATRIX[y][z];
        printf("\n DATA:%d\n",MATRIX[y][z]);
	y++;
        z--;
			}
		}
	}
}
y=0;
while(y<(2*NXN)+2){
printf("\nSUMS of %d: %d\n",y,sums[y]);
y++;
}
  
int Magic = 0;
int data = sums[0];
//NXN
for(y=0;y<(2*NXN)+2;y++){
printf("\nSUMS[y]:%d\n",sums[y]);
if(data==sums[y]){
Magic=1;
}
else{
Magic=0;
break;
}

}

if(Magic==0){

printf("not-magic");
}
else{
printf("magic");
}







free(MATRIX);
free(sums);
close(Accessed);
free(AllData);


}//	end elsei




return 0;

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
        AllData[t]='\0';
        determinant = determinant + Checkit;
        //printf("Check??%d\n",Checkit);
        Checkit=read(file,piece,99*sizeof(char));
        }while(Checkit!=0);     
	//printData();                                                             
	return AllData;	
}	


void printData(){
int f = 0;
//int SIZE = sizeof(AllData)/sizeof(AllData[0]);
while(AllData[f]!= '\0'){


//printf("%c", AllData[f]);

f++;
}	                 
return;

} 

void addData(int data, int row,int  column, int** Array){

Array[column][row]=data;

return;
}
//printf("H\n");
void printMatrixData(int NXN, int **Array){
int i = 0;
int k = 0;
printf("\n");
for(i=0;i<NXN;i++){
	for(k=0;k<NXN;k++){
	printf("%d ",Array[k][i]);
	}
	printf("\n");
}

return;


}       


