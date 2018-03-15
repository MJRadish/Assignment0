# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
	
struct Junk{ int data; struct Junk* next;};

typedef struct Junk Node;

//Node LinkedList;

//Node* ptr;

Node* Origin = NULL;

void addData(int Data,Node** ptr);

void deleteData(int Data,Node** ptr);

void printData(Node** ptr);
				
void SelectSort(Node**ptr);
void FreeAll(Node** ptr);

int main (int argc, char*  argv[]){

//Origin = NULL;
Node* ptr = Origin;

//printf("Enter file name:");

if(argc<2){
printf("Not enough arguments");
return 0;
}

FILE * accessed = fopen(argv[1],"r");

if(accessed == NULL){

printf("0");

fclose(accessed);

return 0;						


}
char op;
int entry;



while(fscanf(accessed, "%c\t%d\n", &op, &entry) != EOF){

if(op=='i'){
printf("\nOP: %c, DATA: %d\n",op,entry);


addData(entry,&Origin);
}
else if(op=='d'){
//printf("DDDDDDDDDDDDDDDDDDDDD");
printf("\nOP: %c, DATA: %d\n",op,entry);

deleteData(entry,&Origin);
}
else{

printf("error");

return 0;

//continue;
printf("\nOP: %c, DATA: %d\n",op,entry);

}

//printf("\nOP: %c, DATA: %d\n",op,entry);



}
fclose(accessed);





/*
addData(-500,&Origin);
addData(-250,&Origin);
addData(-77,&Origin);
*/
//deleteData(-500,&Origin);
//deleteData(-250,&Origin);
//deleteData(-77,&Origin);


/*
addData(-1,&Origin);
addData(1,&Origin);
addData(2,&Origin);
addData(0,&Origin);
addData(3,&Origin);


//(-ta(-1,&Origin);
deleteData(-250,&Origin);
*/
/*
deleteData(1,&Origin);
deleteData(0,&Origin);
deleteData(2,&Origin);
deleteData(3,&Origin);
deleteData(5,&Origin);
deleteData(12,&Origin);
addData(5,&Origin);
deleteData(5,&Origin);
addData(5,&Origin);
*/
printf("SORT");

SelectSort(&Origin);

printf("FINAL:\n");


printData(&Origin);

FreeAll(&Origin);
/*
if(Origin!=NULL){
free(Origin);

}
*/
//printf("Originn is now:%d",Origin);
//free(ptr);
return 0;
}


////////////////////////////////////////////////////////////////////
void addData(int Data,Node**ptr){
if(ptr==NULL){
printf("PTR IS NULL, CANNOT ADD");
}
if(*ptr==NULL){
*ptr=malloc(sizeof(Node));
(*ptr)->data=Data;
(*ptr)->next=NULL;
return;
}
addData(Data,&((*ptr)->next));
return;
//break;
}


void deleteData(int Data,Node** ptr){
if(ptr==NULL){
printf("\nNO POINTER TO POINT TO!\n");
return;
}
if(*ptr==NULL){
printf("\nCOULD NOT FIND NUMBER TO DELETE\n");
return;
}
if((*ptr)->data==Data){
Node** pt = (ptr);
//free(ptr);
if(*pt==Origin){
printf("=========");
Origin=Origin->next;
if(Origin!=NULL){
printf("\n\nORIG: %d\n\n",Origin->data);
printData(&Origin);
return;
}
free(*pt);
*pt=NULL;
//return;
}
else{
(*ptr)=(*ptr)->next;
free(*pt);
*pt=NULL;
}
printf("DELETION LIST\n");
printData(&Origin);
return;
}
//printf("PT:%d",(*ptr)->data);
deleteData(Data,&((*ptr)->next));
//printData(Origin);
/////////////////////////////////////////////////////////
return;
}

void printData(Node**ptr){
//ptr=Origin;
if(ptr==NULL){
printf("N POINTER");
return;
}
if(*ptr==NULL){
printf("NNPOINTER");
return;
}
while((*ptr)!=NULL){
if((*ptr)->data==0){
printf("0");
}
else{
printf("%d ",(*ptr)->data);
}
ptr=&((*ptr)->next);
}
printf("\n");
return;
}


void FreeAll(Node** ptr){
//Node* prev = malloc(sizeof(Node));
//ptr=malloc(sizeof(Node));
if(ptr==NULL){
printf("NULL PT");
return;
}
if (*ptr==NULL){
printf("NO LIST");
return;
}
Node** pt;

while((*ptr)!=NULL){
printf("DATA TO FREE: %d",(*ptr)->data);
//ptr=&((*ptr)->next);
pt = &((*ptr)->next);
printf("\nFREE\n");
free(*ptr);
ptr=pt;
}

//free(prev);

return;


}

void SelectSort(Node** P){
if(P==NULL){
printf("NULL P");
return;
}
if(*P==NULL){

printf("NULL LIST");
return;
}
Node** P2=P;
while(*P!=NULL){
P2=P;
while(*P2!=NULL){
if((*P2)->data<(*P)->data){
//Switch
printf("SWITCH");
printData(&Origin);
int temp = (*P)->data;

(*P)->data=(*P2)->data;

(*P2)->data= temp;

}

P2=&((*P2)->next);
}
P=&((*P)->next);
}




return;
}
