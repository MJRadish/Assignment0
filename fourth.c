//Assignment 4 Matrix Exponention with added calculators for inverse matrix exponentiation (Ex: A^-2=(A^-1)(A^-1), A^2 = (A*A))

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

//Any int is greater than 0
char* readData(int file);
void printData();
char* AllData;

int row =1;
int column =1;
int NXN;
int power=0;
//int MATRIX[0][0];

void printData();

void printMatrixData(int NXN, long double **Matrix);

int Power(int power, int Breaker);

long double** Multiply (long double** M1, long double ** M2);

long double** Inverse(long double** M1, long double** M2);

bool isRREF(long double** M1);
//If not RREF, not invertible, not possible inverse!

long double** AddRow(long double entry, long double** M1, long int row);

long double** AddRows(long double entry, long double** M1, long int row1, long int row2);

long double** MultiplyRow(long double entry, long double** M1, long int row);

void freeMatrix(long double** M);

long double ** EMATRIX;

long int numOfPow(long double entry);

long double *** MRecord;

long int MCount = 0;

int main(int argc ,  char** argv){

int Accessed = open(argv[1],O_RDONLY);

if(Accessed==-1){
printf("Cannot open file");
return 0;
}


else{


readData(Accessed);

//char* str = (char*)malloc(2*sizeof(char));
//str[0] = AllData[0];
//str[1]='\0';
int h=0;
/*while(AllData[h]!='\0'){
printf("D%c",AllData[h]);
h++;
}*/
printf("%s",AllData);
//return 0;
int size = NXN;
//NXN = atoi(str);

//str[0]=AllData[strlen(AllData)-2];
//power = atoi(str);

if(power<0){
printf("POWER IS NEGATIVE");
//return -1;
}
printf("POWER: %d, NXN: %d", power,NXN);
//return 0;
//int* MATRIX = malloc(NXN*sizeof(int));
EMATRIX=malloc(NXN*sizeof(long double*));

long double** MATRIX = malloc(NXN*sizeof(long double*));
int q = 0;
while(q<NXN){
MATRIX[q] = malloc(NXN*sizeof(long double));
EMATRIX[q] = malloc(NXN*sizeof(long double));
q++;
}
int i=0;
int j=0;
printf("\n");
for (i=0; i<NXN; i++){
    for(j=0; j<NXN; j++){
    MATRIX[i][j]=0;
    //EMATRIX[i][j]=0;
    if(i==j){
    EMATRIX[i][j]=1;
    }
    else{
    EMATRIX[j][i]=0;
    }
    printf("MATRIX [%d][%d]: %ld  ",i,j,MATRIX[i][j]);  
    }
    printf("\n");
}
printf("\nPRINT\n");
printMatrixData(NXN,MATRIX);
//return 0;
int idx = 1;
int y = 0;
row=0;
column = 0;
int ALL = 0;

printf("NXN Squared: %d", NXN*NXN);

while(AllData[idx]!='\0'){
if(isdigit(AllData[idx])||AllData[idx]=='-'){
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
free(string);
string=NULL;
printf("\nVALUE %ld\n",value);
//addData(value, row,column, MATRIX);
MATRIX[column][row]=(long double)value;
printf("\n MATRIX[%d][%d]: %LG",column,row,MATRIX[column][row]);
column++;
ALL=ALL+1;
if(column==NXN){
column=0;
ALL--;
if(row<NXN){
row++;
ALL=ALL+1;;
}
else if(row==NXN||ALL==NXN*NXN){
printf("\n\n END OF READING \n\n");
break;
}
//printf("\nALL: %d\n:",ALL);
}

 if(ALL==NXN*NXN){
 printf("\n\n END OF READIN 2G \n\n");
 printf("ALL: %d, NXN^2, %d\n",ALL, NXN*NXN);
 break;
 }
 


//printf("\nALL: %d\n:",ALL);
//
 idx=f;
 continue;
}
idx++;
}

//return 0;

long double** CMATRIX = malloc(NXN*sizeof(long double*));
 q = 0;
while(q<NXN){
CMATRIX[q] = malloc(NXN*sizeof(long double));
//EMATRIX[q] = malloc(NXN*sizeof(long double));
q++;
}
int r=0;
q=0;
for(r=0;r<NXN;r++){
for(q=0;q<NXN;q++){
CMATRIX[q][r]=MATRIX[q][r];
}
}

free(AllData);



if(power<0){
Inverse(MATRIX,EMATRIX);
if(!isRREF(MATRIX)){
printf("\n MATRIX IS NOT INVERTIBLE!\n");

//FREE ALL MATRICES
freeMatrix(MATRIX);
freeMatrix(EMATRIX);
freeMatrix(CMATRIX);

return -1;
}
if(power==-1){

printMatrixData(NXN,EMATRIX);


//return 0;
}
else if(power==-2){

printf("\nMATRIX TO THE POWER OF:%d\n",power);

long double** I = Multiply(EMATRIX,EMATRIX);

printMatrixData(NXN,I);


free(I);
}
else{
//^-3 or higher
long double** New=NULL;
New=Multiply(EMATRIX,EMATRIX);

//MRecord[0]=New;
MCount++;
MRecord=malloc(sizeof(long double**));
MRecord[0]=New;
MRecord=realloc(MRecord,sizeof(long double**));
//long double** New=NULL;

i=-1;
while(i>power){
MCount++;
MRecord[MCount]=New;
New=Multiply(New,EMATRIX);
//MRecord[MCount]=New;
MRecord=realloc(MRecord,sizeof(long double**));
//MCount++;
i--;
}


printf("\nMATRIX TO THE POWER OF:%d\n",i);

printMatrixData(NXN,New);


}
freeMatrix(MATRIX);
freeMatrix(EMATRIX);
freeMatrix(CMATRIX);
int n=0;
while(n<MCount){
freeMatrix(MRecord[n]);
n++;
}
return 0;
}
if(power==0){
int h=0;
int k=0;
for(h=0;h<NXN;h++){
for(k=0;k<NXN;k++){
if(h==k){
MATRIX[h][k]=1;
}
else{
MATRIX[h][k]=0;
}
}

}

printf("\nMATRIX TO THE POWER OF: %d\n",power);

printMatrixData(NXN,MATRIX);

freeMatrix(MATRIX);
freeMatrix(EMATRIX);
freeMatrix(CMATRIX);

return 0;
}
else if(power==1){


printf("\nMATRIX TO THE POWER OF: %d\n",power);


printMatrixData(NXN,MATRIX);

freeMatrix(MATRIX);
freeMatrix(EMATRIX);
freeMatrix(CMATRIX);


return 0;
}

i = 1;
long double ** New = NULL;

New = Multiply(MATRIX,MATRIX);
MRecord[MCount]=New;
MCount++;

if(power==2){
//Done
printf("\nMATRIX TO THE POWER OF: %d\n",power);
printMatrixData(NXN,New);

freeMatrix(MATRIX);
freeMatrix(EMATRIX);
freeMatrix(CMATRIX);

return 0;
}
i=2;
while(i<power){

New=Multiply(New,MATRIX);
MRecord[MCount]=New;
MCount++;

i++;
}

printf("\nMATRIX TO THE POWER OF:%d\n",power);

printMatrixData(NXN,New);

freeMatrix(MATRIX);
freeMatrix(EMATRIX);
freeMatrix(CMATRIX);
int n=0;
while(n<MCount){
freeMatrix(MRecord[n]);
n++;
}
return 0;

}//	end elsei



/*freeMatrix(MATRIX);
freeMatrix(EMATRIX);
freeMatrix(CMATRIX);
*/

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
        printf("Check??%d\n",Checkit);
        Checkit=read(file,piece,99*sizeof(char));
        }while(Checkit!=0);     
	char* s = malloc(2*sizeof(char));
	s[1]='\0';	
	s[0]=AllData[strlen(AllData)-2];
	power = atoi(s);
	s[0] = AllData[0];
	NXN = atoi(s);
	free(s);
	s=NULL;
	//printData(); 
	free(piece);
	piece=NULL;                                                            
	char* t = malloc(sizeof(char));
	t[0]='\0';
	char* h = malloc(2*sizeof(char));
	//h[0]='\0';
	h[1]='\0';

        int i=strlen(AllData);
	h[0]=AllData[i];	
	while(!isdigit(AllData[i])){
	i--;
	}
	h[0]=AllData[i];
	
	while(isdigit(AllData[i])){
	h[0]=AllData[i];
	printf("NOT:%c",h[0]);
	i--;
	}
	//i++;
	printf("M2:%c, BUF: %c",h[0],AllData[i]);		
	char c = h[0];
	if(AllData[i]=='-'){
	int count =1;
	while(AllData[i]=='-'){
	printf("%c",AllData[i]);
	count++;
	i--;
	}
	//strcat(t,
	if(count%2==0){
	h[0]='-';
	strcat(t,h);
	}
	i=i+count-1;
	//h[0]=c;
	//strcat(t,h);
	//h[0]=AllData[i+1];
	i++;
	h[0]=AllData[i];
        printf("M3:%c, BUF: %c",h[0],AllData[i]);
	}
	else{
	i++;
	while(!isdigit(AllData[i])){
	printf("%c",AllData[i]);
	i++;
	}
	//Found back
	printf("FOUND BACK");
	h[0]=AllData[i];
	printf("\nBACKY:%c\n",h[0]);
	//strcat(t,h);
	}
	//h[0]=c;
	//strcat(t,h);
	
	while(isdigit(h[0])&&AllData[i]!='\0'){
	h[0]=AllData[i];
	
        printf("NOT:%c",h[0]);

	strcat(t,h);
	i++;
	}
	int y=0;

	//if is it -, concat
	int b = atoi(t);
	printf("GREATER POWER: %s,%d",t,b);
	
//exit(0);
	free(t);
	t=NULL;
	free(h);
	h=NULL;
	power=b;
	if(NXN<1){
	printf("Error, Number of rows and columns cannot be negative!");
	exit(0);
	}
	return AllData;	
}	


void printData(){
int f = 0;
//int SIZE = sizeof(AllData)/sizeof(AllData[0]);
while(AllData[f]!= '\0'){


printf("%c", AllData[f]);

f++;
}	                 
return;

} 

void printMatrixData(int NXN, long double **Array){
if(Array==NULL){

return;

}
int i = 0;
int k = 0;
for(i=0;i<NXN;i++){
	for(k=0;k<NXN;k++){
	printf("%LG ",Array[k][i]);
	}
	printf("\n");
}

return;


}       

//Return pointer to entire matrix multiplied
long double ** Multiply(long double** Matrix1, long double** Matrix2){
//BOTH OF SIZE NXN

long double** NewM = malloc(NXN*sizeof(long double*));

int g=0;
while(g<NXN){
NewM[g]=malloc(NXN*sizeof(long double));
g++;
}

int i=0;
int k=0;
int l=0;
//Columns then rows
long double sum =0;
long double mult = 1;

printf("MATRIX ORIG:\n");
printMatrixData(NXN,Matrix1);
//printf(" Times MATRIX 2:\n");
//printMatrixData(NXN,Matrix2);
printf("\n");
for (i=0; i<NXN; i++){
     for(k=0; k<NXN; k++){
	for(l=0; l<NXN; l++){
	//Iterate columns of M1, rows of M2 [col][row]
	mult = Matrix1[l][i]*Matrix2[k][l];	
	sum+=mult;
	}
	//printf("\nSUM[%d][%d] :%d\n",k,i,sum);
	NewM[k][i]=sum;
	sum=0;
	//NEXT COLUMN
     }
	//NEXT ROW
}

//printf("\nNEW MATRIX\n\n");
//printMatrixData(NXN,NewM);

//freeMatrix(Matrix1);
//freeMatrix(Matrix2);
/*
for(i=0;i<NXN;i++){
for(k=0;k<NXN;k++){
//Copy NewM to M1
Matrix1[k][i]=NewM[k][i];

}
}

freeMatrix(NewM);

*/


//freeMatrix(Matrix1);

//Simpler to just return the new matrix
return NewM;
}

void freeMatrix(long double** Matrix){
if(Matrix==NULL){

return;
}

int i=0;
int j=0;

while(i<NXN){
free(Matrix[i]);
Matrix[i]=NULL;
i++;
}

free(Matrix);
Matrix=NULL;


return;
}

long double** AddRow(long double entry, long double** M1, long int column){
//long int* TotalRow=M1[row][column];
//Total row space
if(column<0||column>=NXN){
printf("\n INVALID COLUMN #\n");
return M1;
}
long int i=0;
while(i<NXN){
printf("\nROW:%ld:%LG\n",i,M1[i][column]);
M1[i][column]+=entry;
i++;
}

return M1;
}

long double** AddRows(long double entry, long double** M1, long int column1, long int column2){
//long int* TotalRow=M1[row][column];
////Total row space
if(column1<0||column1>=NXN||column2<0||column2>=NXN){
printf("\n INVALID COLUMN #\n");
return M1;
}

long int i=0;
while(i<NXN){
printf("\nROW:%ld:%LG\n",i,M1[i][column]);
M1[i][column2]=M1[i][column2]+(entry*M1[i][column1]);
i++;
}

return M1;
}

long double** MultiplyRow(long double entry, long double** M1,long int column){
//long int* TotalRow=M1[row][column];
////Total row space
if(column<0||column>=NXN){
printf("\n INVALID COLUMN #\n");
return M1;
}
long int i=0;
while(i<NXN){
printf("\nROW:%ld:%LG\n",i,M1[i][column]);
M1[i][column]*=entry;
i++;
}

return M1;
}


long double** Inverse(long double** Matrix, long double** EMatrix){
long int i=0;
long int j=0;
long int k =0;
long double divisor = 0;
for(i=0;i<NXN;i++){
    for(j=0;j<NXN;j++){
    if(i==j){
       if(Matrix[j][i]!=1){
	//Make row such that == 1!
	
	divisor = Matrix[j][i];
	if(divisor!=0){
	MultiplyRow(1.0/divisor,Matrix,i);
        //divisor=EMatrix[j][i];
        MultiplyRow(1.0/divisor,EMatrix,i);
	}
	else{
	printf("\nCANNOT REDUCE\n");
	if(i<NXN)
	i++;
	}
	}
	//PIVOT
	k=0;
	while(k<NXN){
	//Iterate down all rows above and below pivot column
	//Matrix[j][k]... 1 .....
	//NOT PIVOTS
	if(k!=j){   
	if(Matrix[j][k]<0||Matrix[j][k]>0){
        //AddRows(-Matrix[j][k],Matrix,i,k);
        //divisor =  
	AddRows(-Matrix[j][k],EMatrix,i,k);		
	AddRows(-Matrix[j][k],Matrix,i,k);


	}
	else{
	printf("\nRow:%ld Column:%ld is already 0, %LG \n",j,k,Matrix[j][k]);
	}
	
	if(Matrix[j][j]!=1){
        //Make row such that == 1!
        divisor = Matrix[j][j];
        if(divisor!=0){
	MultiplyRow(1.0/divisor,Matrix,j);
        //divisor=EMatrix[k][k];
	MultiplyRow(1.0/divisor,EMatrix,j);
        }
	else{
	printf("CANNOT REDUCE");
	if(j<NXN)
	j++;
	}
	}
	
        //
	}
	k++;   
	}
	
	
        }
     printf("\n MATRIX NOW:\n");
	printMatrixData(NXN,Matrix);
     
     printf("\n EEEMATRIX NOW:\n");
        printMatrixData(NXN,EMatrix);
     //printf("\nMATRIX[%ld][%ld] : %LG\n",j,i,Matrix[j][i]);
     //printf("EMATRIX[%ld][%ld] : %LG",j,i,EMatrix[j][i]);
    }
     printf("\n");
}

//printMatrixData(NXN,EMatrix);

return Matrix;
}

bool isRREF(long double** Matrix){
long int i = 0;
long int j = 0;

for(i=0;i<NXN;i++){
    for(j=0;j<NXN;j++){
    if(i==j){ 
	if(Matrix[j][i]==1){

	}
	else{
        printf("\nNot RREF @ %ld,%ld,%LG\n",j,i,Matrix[j][i]);
        return false;
	}   	


    }
    else{
	if(Matrix[j][i]==0||numOfPow(Matrix[j][i])>14){	
	}
	else{
        printf("\nNot RREF @ %ld,%ld,%LG\n",j,i,Matrix[j][i]);
	return false;
	}
	}
    }
}
printf("\nIT Is RREF\n");
return true;
}


long int numOfPow(long double entry){
long int i=0;
if(entry>0&&entry<1){
while(entry<=1){
entry=entry*10;
i++;
}
}
else if(entry>-1&&entry<0){
while(entry>=-1){
entry=entry*10;
i++;
}
}
return i;
}
