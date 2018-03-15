//Hash Table Third Assignment (For Any integer, Table size is compressed to 10000)

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct DecreaseHash_{

unsigned int data;
double dataLost;
int numOfShifts;

}DecreaseHash;

typedef struct IntL_{

unsigned int data;
double dataLost;
int numOfShifts;
DecreaseHash* DH;
bool negBit;

}IntL;

typedef struct LL_{

//int Data;
struct LL_* Next;
IntL* IData;

} LL;

typedef struct HTable_{

LL* List;

}HTable;

HTable Hash[10000];


void printHash();

//0-9999
//HASH SEGMENTS
//Insert at beginning
//Search less than O(n), that means use key!
unsigned int HashFunc(IntL** proto);

void InsertData(int data);

void Insert(IntL** key);

bool Search(int data);

void FreeHash();

void createEntry(unsigned int data);

unsigned int UnHash(IntL** proto);

int main(int argc, char** argv){

//
IntL* G = malloc(sizeof(IntL));
G->data=G->dataLost=1005;
G->numOfShifts=0;
G->DH=malloc(sizeof(DecreaseHash));
//

HashFunc(&G);

printf("HASH [9999] : %d", Hash[9999]);

Insert(&G);

InsertData(5);

printHash();

InsertData(-5);

Insert(&G);

InsertData(-7);

printf("UNHASK KEY G: %lld",UnHash(&G));

//Search(1005);

printHash();

//Search(1005);

return 0;
}

unsigned int HashFunc(IntL** x){

printf("\n\nCREATE KEY FOR: %d\n\n",(*x)->negBit==true ? -1*(*x)->data:(*x)->data);

while((*x)->data>10000){
(*x)->data=(*x)->data/10;
(*x)->numOfShifts++;
}
unsigned int i=(*x)->data;

printf("\n X ORIG: %d\n",(*x)->negBit==true ? -1*(*x)->data:(*x)->data);
  (*x)->data = (((*x)->data >> 16) ^ (*x)->data) * 0x45d9f3b;
    (*x)->data = (((*x)->data >> 16) ^ (*x)->data) * 0x45d9f3b;
    (*x)->data = ((*x)->data >> 16) ^ (*x)->data;

(*x)->DH->data=(*x)->DH->dataLost=(*x)->data;
(*x)->data=i;
while((*x)->DH->data>10000){
(*x)->DH->data=(*x)->DH->data/10;
(*x)->DH->numOfShifts++;
}

   printf("\nKEY: %d\n",(*x)->negBit==true ? -1*(*x)->data:(*x)->data);
   printf("\n\n HASH ARRAYABLE: %d: \n\n",(*x)->DH->data);
   return (*x)->DH->data;

}

unsigned int UnHash(IntL** x){

while((*x)->DH->numOfShifts>0){
(*x)->DH->data=(*x)->DH->data*10;
(*x)->DH->numOfShifts--;
}

while((*x)->DH->data!=(*x)->DH->dataLost){
if((*x)->DH->data<(*x)->DH->dataLost){
(*x)->DH->data=(*x)->DH->data+1;
}
else if((*x)->data>(*x)->dataLost){
(*x)->DH->data=(*x)->DH->data-1;
}
} 
  (*x)->DH->data = (((*x)->DH->data >> 16) ^ (*x)->DH->data) * 0x119de1f3;
    (*x)->DH->data = (((*x)->DH->data >> 16) ^ (*x)->DH->data) * 0x119de1f3;
  (*x)->DH->data = ((*x)->DH->data >> 16) ^ (*x)->DH->data;

	return (*x)->DH->data;

}
void Insert(IntL** Key){
if(Key==NULL){
printf("\nNULL POINTER\n");
return;
}
if(*Key==NULL){
printf("\nNULL\n");
return;
}

printf("\nInsert Key Data:%d TO KEY:%u\n",(*Key)->negBit==true? -1*(*Key)->data:(*Key)->data,(*Key)->DH->data);

if(Hash[(*Key)->DH->data].List!=NULL){
if(Hash[(*Key)->DH->data].List!=NULL){
//Search
int I=0;
if((*Key)->negBit==true){

I=((*Key)->data)*-1;
}
else{
I=(*Key)->data;

}

if(Search(I)==true){

printf("\n ALREADY FOUND");

return;
}

printf("ADD 1");

LL* Ptr = malloc(sizeof(LL));

Ptr->IData=(*Key);

Ptr->Next=Hash[(*Key)->DH->data].List->Next;

Hash[(*Key)->DH->data].List->Next=Ptr;


}
}
else{
printf("ADD 2");
Hash[(*Key)->DH->data].List=malloc(sizeof(LL));
Hash[(*Key)->DH->data].List->IData=*Key;
Hash[(*Key)->DH->data].List->Next=NULL;
printf("\nDATA ADDED TO: %u: %u\n",(*Key)->DH->data,Hash[(*Key)->DH->data].List->IData->data);
}

return;
}

bool Search(int data){
//KEY
bool neg;
IntL* G = malloc(sizeof(IntL));
if(data<0){
G->negBit=true;
data=data*-1;
neg=true;
}
else{
G->negBit=false;
neg=false;
}
G->data=G->dataLost=data;
G->numOfShifts=0;
G->DH=malloc(sizeof(DecreaseHash));
G->DH->data=data;

HashFunc(&G);

printf("ADDRESSABLE KEY: %d",G->DH->data);
printf("DATA: %u",Hash[G->DH->data].List->IData->data);

LL** Ptr = &(Hash[G->DH->data].List);
free(G->DH);
G->DH=NULL;
free(G);
G=NULL;
if(neg==true){
data=data*-1;
}

while((*Ptr)!=NULL){
printf("\n\nFIRST\n\n");
if((*Ptr)->IData!=NULL){

printf("DATA STORED: %u\n PTR NEGBIT: %s",(*Ptr)->IData->data,(*Ptr)->IData->negBit ? "True":"False");

if((*Ptr)->IData->negBit==false){
printf("\n\nCASE 1\n\n");
if(data<0){
//Negative vs Positive
printf("\n\n NEGATIVE VS POSITIVE 1\n\n");
Ptr=&((*Ptr)->Next);
continue;
}
else{
if((*Ptr)->IData->data==data){
printf("\n\n POSITIVE AND POSITIVE \n\n");
break;
}
}
}

else if((*Ptr)->IData->negBit==true){
printf("\n\nCASE 2\n\n");
if(data>0){
//Negative vs Positive
printf("\n\n NEGATIVE VS POSITIVE 2\n\n");
Ptr=&((*Ptr)->Next);
continue;
}
else{
if((*Ptr)->IData->data*-1==data){
printf("\n\n NEGATIVE AND NEGATIVE \n\n");
break;
}
}
}


/*
if(((*Ptr)->IData->data*-1==data&&(*Ptr)->IData->negBit==true&&data<0)||((*Ptr)->IData->data==data&&(*Ptr)->IData->negBit==false&&data>=0)){
printf("GOT IT!");
break;
}
*/
}
Ptr=&((*Ptr)->Next);
}
if((*Ptr)==NULL){
printf("\nNOT FOUND\n");
return false;
}
else{
printf("\nFOUND\n");
}
return true;
}

void printHash(){
LL** L;
int i=0;
int F =0;
while(i<10000){
L=&(Hash[i].List);
F=0;
while(*L!=NULL){
printf("\nDATA FOR HList: %u\t NEGBIT: %s",(*L)->IData->data,(*L)->IData->negBit ? "True":"False");
L=&((*L)->Next);
F=1;
}
if(F==1)
printf("\n");
i++;
}
return;
}

void InsertData(int data){
printf("\nADD %d\n",data);
IntL* G = malloc(sizeof(IntL));
if(data<0){
G->negBit=true;
data=data*-1;
}
else{
G->negBit=false;
}
G->data=G->dataLost=data;
G->numOfShifts=0;
G->DH=malloc(sizeof(DecreaseHash));

printf("NEG BIT!! %s",G->negBit ? "True":"False");
HashFunc(&G);
Insert(&G);
return;
}

