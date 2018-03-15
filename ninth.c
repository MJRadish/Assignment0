# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
#include <stdbool.h>
	
struct Junk{ int data; struct Junk* left; struct Junk* right; int size; int depth;};

typedef struct Junk Node;

//Node LinkedList;
int size;
int sizeLeft;
int sizeRight;
//int Depth;
//int Switch;
Node* Origin;
//int* S;
//int path;

void Rm(Node *F);


Node* LMost(Node** O);
Node* RMost(Node **O);
int Depth(Node** ptr);

bool Insert(int Data);
//Balance insertions once and for all!
bool InsertFix(int Data);

Node* InsertALL(Node**P);
void Delete(int Data);
void Search(int Data);
void SetDepth(Node ** Ptr);
void FreeTree(Node*O);
void BalanceAllTree(Node** O);

void PrintTree(Node*T);
void PrintTreeOrder(Node* T, int type);


Node* RCCWise(Node**O,bool lSide);
Node* RCWise(Node** O,bool rSide);

typedef struct VisitNode_{

Node* N;

struct VisitNode_* Next;

}VisitNode;

VisitNode* Visited = NULL;

void AddToVisited(Node*O,VisitNode** V);
bool isVisited(Node* O,VisitNode** V);
void DeleteVisited(Node* O, VisitNode** V);
void PopulateVisited(Node* O, VisitNode** V);
void PrintVisited(VisitNode** V);
void FreeAllVisited(VisitNode* V);
//UpdateBalance

//Balance for all nodes THAT REQUIRE IT!
//Check if updated balance is >1 or < -1, IF BALANCE >1, rotate group CCWISE
//IF BALANCE <-1, rotate group CWISE

//int Depth(Tree) RETURNS DEEPEST SIDE REGARDLESS OF WHICH SIDE IT TAKES
/*

//PREORDER TRAVERSAL
RCCWISE(Tree)

//POSTORDER TRAVERSAL
RCWise(Tree)

BalanceTree(Tree)

Insert(1)

Delete(1)

Search(1)
*/

int UPALL(Node **ptr);

int addData(int Data, Node** ptr, Node**prev, Node**prev2,int path,int Depth);

void Trails(Node** ptr, Node** prev, Node** prev2);

//int Search(Node**ptr,int Data);

//void SearchRes(Node** ptr,int Data, int *S);

int RecursiveBalance(Node** ptr,Node** prev, Node** prev2, int path, int data);

int Balance(Node**ptr,Node** prev,Node** prev2);

int UpdateSize(Node**ptr);

int  RecurseDeleteData(Node** ptr,int Data);

int SizeRight(Node**ptr);

int SizeLeft(Node**ptr);

int printData(Node* ptr);
				
int main (int argc, char*  argv[]){
sizeLeft=0;
sizeRight=0;
//int path=0;
//Switch=0;

/*int* S=malloc(sizeof(int));
*S=0;
*/
if(argc>2||argc<2){

printf("Argument count is too large or too small");
return -1;
}
//Depth=0;
//Depth=0;
Origin = 0;

FILE * accessed = fopen(argv[1],"r");

if(accessed == NULL){
printf("error");
//fclose(accessed);
//printData(Origin);
return 0;						
}


char op;
int entry;

while(fscanf(accessed, "%c\t%d\n", &op, &entry) != EOF){
printf("%c\t%d",op,entry);
if(op=='i'){
Insert(entry);
printf("\n");
//InsertFix(entry);
BalanceAllTree(&Origin);
InsertFix(entry);
//printData(Origin);
continue;
}
else if(op=='s'){
//Search(&Origin,entry);
Search(entry);
printf("\n");
continue;
}
else if(op=='d'){
//RecurseDeleteData(ptr,entry);
Delete(entry);
BalanceAllTree(&Origin);
printf("\n");
//printData(Origin);
continue;
}
else{
printf("error");
break;
//continue;
}
}


/*
Insert(1);
Insert(2);
Insert(3);


Insert(4);
Insert(5);
Insert(6);

*/

PrintTreeOrder(Origin,0);

FreeTree(Origin);

return 0;
//ROTATION WORKS!!! :) :) :)
Insert(1);
BalanceAllTree(&Origin);
Insert(-33);
BalanceAllTree(&Origin);
Insert(22);
BalanceAllTree(&Origin);
Insert(-5);
BalanceAllTree(&Origin);
Insert(41);
BalanceAllTree(&Origin);



Insert(0);

BalanceAllTree(&Origin);

Insert(2);

BalanceAllTree(&Origin);

Insert(5);

BalanceAllTree(&Origin);

Insert(-4);

BalanceAllTree(&Origin);

Insert(-16);

BalanceAllTree(&Origin);

Insert(-17);

BalanceAllTree(&Origin);

Insert(-8);

BalanceAllTree(&Origin);

Insert(7);
BalanceAllTree(&Origin);


Insert(69);
BalanceAllTree(&Origin);


Insert(68);
BalanceAllTree(&Origin);


Insert(-11);
BalanceAllTree(&Origin);


Insert(-22);
BalanceAllTree(&Origin);


Insert(8111);
BalanceAllTree(&Origin);


//ROTATION WORKS!! :) :) :)
PrintTree(Origin);
//123
//return 0;
//While the depths of both sides is greater than 1
//Node** C = &Origin;


//RCCWise(C,true);

/*
while(Depth(&((*C)->right))-Depth(&((*C)->left))<0){

RCWise(C,true);
printf("\n");
PrintTree(*C);

}

*/
/*
RCWise(C,true);
RCWise(C,true);
*/
//RCWise(C,true);
//while(1){
/*
RCCWise(C,true);
printf("\n");
PrintTree(*C);
*/
//}

/*

while(Depth(&((*C)->right))-Depth(&((*C)->left))>0){

RCCWise(C,true);
printf("\n");
PrintTree(*C);

}

//srandom(9);
int i =0;


//BALANCE FUNCTION MODIFIED TO WORK FOR ANY TREE.
while(i<101){
//while(Depth(&((*C)->right))-Depth(&((*C)->left))<0){
if(i%7==0){
RCWise(C,true);
printf("\n");
PrintTree(*C);
}
else{
RCCWise(C,true);
printf("\n");
PrintTree(*C);
}
i=i+1;
}
i=0;
*/
//BalanceAllTree(C);

/*while(Depth(&((*C)->right))-Depth(&((*C)->left))>0){


RCCWise(C,true);
printf("\n");
PrintTree(*C);

}
*/

printf("\n");
PrintTree(Origin);
printf("\n");

PrintTreeOrder(Origin,0);

Search(1);
Search(-33);
Search(22);
Search(-5);
Search(41);
Search(0);
Search(2);
Search(5);
Search(-4);
Search(-16);
Search(-17);
Search(-8);
Search(7);
Search(69);
Search(68);
Search(-11);
Search(-22);
Search(8111);

Delete(1);
Delete(41);
Delete(69);
Delete(7);
Delete(-33);
Delete(22);
Delete(-5);
Delete(0);
Delete(2);
Delete(5);
Delete(68);
//BUGGY
Delete(-11);
//EVEN THOUGH 0 LEAKS
Delete(-16);
Delete(-8);
Delete(-4);
Delete(-22);
Delete(-17);
/////////////////////

Search(1);
Search(-33);
Search(22);
Search(-5);
Search(41);
Search(0);
Search(2);
Search(5);
Search(-4);
Search(-16);
Search(-17);
Search(-8);
Search(7);
Search(69);
Search(68);
Search(-11);
Search(-22);
Search(8111);



PrintTreeOrder(Origin,0);




FreeTree(Origin);

return 0;
}

Node * LMost(Node **O){
//Node** O = &Origin;
if(*O==NULL){
return *O;
}
while((*O)->left!=NULL){
O=&((*O)->left);
}
return *O;
}

Node* RMost(Node**O){
//Node** O = &Origin;
if(*O==NULL){
return *O;
}
while((*O)->right!=NULL){
O=&((*O)->right);
}
return *O;
}

//Length of depth by going depth first
int Depth(Node** Ptr){
if(Ptr==NULL){
printf("\nNO POINTER\n");
return 0;
}
if(*Ptr==NULL){
return 0;
}
if((*Ptr)->right!=NULL&&(*Ptr)->left!=NULL){
return 1+(Depth(&((*Ptr)->right))>Depth(&((*Ptr)->left)) ? Depth(&((*Ptr)->right)):Depth(&((*Ptr)->left)));
}
else if((*Ptr)->right==NULL&&(*Ptr)->left!=NULL){
return 1+Depth(&((*Ptr)->left));
}
else if((*Ptr)->right!=NULL&&(*Ptr)->left==NULL){
return 1+Depth(&((*Ptr)->right));
}
return 0;
}
bool InsertFix(int Data){
Node** Ptr = &Origin;

VisitNode* V1 = NULL;

while((*Ptr)!=NULL){
if(Data>(*Ptr)->data){
AddToVisited((*Ptr),&V1);
Ptr=&((*Ptr)->right);
}
else if(Data<(*Ptr)->data){
AddToVisited((*Ptr),&V1);
Ptr=&((*Ptr)->left);
}
else{
//FOUND THE POINTER

//Delete(Data);

VisitNode**V = &V1;

if(*V!=NULL){
Node*Prev=(*V)->N;
Node*Prev2=(*V)->N;

int count=0;

while((*V)!=NULL){
if(count>=2){
Prev2=Prev;
}
Prev=(*V)->N;
V=&((*V)->Next);
count++;
}



if(Prev!=NULL&&Prev2!=NULL&&Prev!=Prev2&&Prev!=(*Ptr)&&count>=2){

printf("\nHAVE TRIO:%d %d %d",Prev2->data,Prev->data,(*Ptr)->data);

if((Prev->data>Prev2->data&&Data>Prev->data)||(Prev->data>Prev2->data&&Data<Prev->data)){
//Right Right or Right Left
printf("\n RIGHT RIGHT OR RIGHT LEFT\n");
//RCCWise(&Prev2,false);
//BalanceAllTree(&Prev2);


if(Prev2->left==NULL){
RCCWise(&(Prev2),false);
BalanceAllTree(&Prev2);
/*
////RCCWise(&Prev2,false);
//
//Delete(Data);

Delete((*Ptr)->data);

Prev2->left=malloc(sizeof(Node));
Prev2->left->left=NULL;
Prev2->left->right=NULL;
Prev2->left->depth=0;
Prev2->left->data=Prev2->data;
Prev2->data=Prev->data;
Prev->data=Data;

//Delete(Data);

//
*/
}
else{
printf("\nINSERTIONS: %d %d %d ARE ALREADY OPTIMIZED!\n",Prev2->data,Prev->data,Data);
////FreeAllVisited(Visit);
//
//Delete((*Ptr)->data);

//
}
}
//
else if((Prev->data<Prev2->data&&Data<Prev->data)||(Prev->data<Prev2->data&&Data>Prev->data)){
//Left Left or Left Right
printf("\n LEFT LEFT OR LEFT RIGHT\n");
//RCWise(&Prev2,false);
//BalanceAllTree(&Prev2);
//RCWise(&Prev2,false);


if(Prev2->right==NULL){

RCWise(&Prev2,false);
BalanceAllTree(&Prev2);



/*
//
////RCWise(&Prev2,false);

Delete((*Ptr)->data);

//Delete(Data);

Prev2->right=malloc(sizeof(Node));
Prev2->right->right=NULL;
Prev2->right->left=NULL;
Prev2->right->depth=0;
Prev2->right->data=Prev2->data;
Prev2->data=Prev->data;
Prev->data=Data;

//Delete(Data);
//
*/
}
else{

////FreeAllVisited(Visit);
printf("\nINSERTIONS: %d %d %d ARE ALREADY OPTIMIZED!\n",Prev2->data,Prev->data,Data);

}

}

//
}//

}

//Delete((*Ptr)->data);

return true;
}

}




return false;


}


bool Insert(int Data){
Node** Ptr = &Origin;
if(*Ptr==NULL){
*Ptr=malloc(sizeof(Node));
(*Ptr)->data=Data;
//(*Ptr)->depth=Depth(Ptr);
(*Ptr)->left=NULL;
(*Ptr)->right=NULL;
(*Ptr)->depth=Depth(Ptr);
return true;
}

VisitNode* Visit = NULL;

while(*Ptr!=NULL){
printf("\nDATA: %d\n",(*Ptr)->data);
if(Data>(*Ptr)->data){
printf("RIGHT");
(*Ptr)->depth=Depth(Ptr);
AddToVisited((*Ptr),&Visit);
Ptr=&((*Ptr)->right);
}
else if(Data< (*Ptr)->data){
printf("LEFT");

(*Ptr)->depth=Depth(Ptr);
AddToVisited((*Ptr),&Visit);
Ptr=&((*Ptr)->left);
}
else{
printf("\nSame data\n");
//DeleteVisited(Visit);
FreeAllVisited(Visit);
return false;
}
}
if(*Ptr==NULL){
//Node*Prev2 = NULL;
//Node*Prev = NULL;


/*
VisitNode** V = &Visit;
int count=0;
if(*V!=NULL){
Prev=(*V)->N;
Prev2=(*V)->N;

//int count=0;

while((*V)!=NULL){
if(count>=2){
Prev2=Prev;
}
Prev=(*V)->N;
V=&((*V)->Next);
count++;
}

}

if(Prev!=NULL&&Prev2!=NULL&&Prev!=Prev2&&count>=2){
//Found last two before added in
printf("\nFOUND LAST TRIO: %d %d %d\n",Prev2->data,Prev->data,Data);

//return true;

if((Prev->data>Prev2->data&&Data>Prev->data)||(Prev->data>Prev2->data&&Data<Prev->data)){
//Right Right or Right Left
printf("\n RIGHT RIGHT OR RIGHT LEFT\n");
if(Prev2->left==NULL){
//RCCWise(&Prev2,false);

Prev2->left=malloc(sizeof(Node));
Prev2->left->left=NULL;
Prev2->left->right=NULL;
Prev2->left->depth=0;
Prev2->left->data=Prev2->data;
Prev2->data=Prev->data;
Prev->data=Data;

}
else{

//FreeAllVisited(Visit);
(*Ptr)=malloc(sizeof(Node));
(*Ptr)->data=Data;
(*Ptr)->depth=Depth(Ptr);
(*Ptr)->left=NULL;
(*Ptr)->right=NULL;
(*Ptr)->depth=0;

}
}
else if((Prev->data<Prev2->data&&Data<Prev->data)||(Prev->data<Prev2->data&&Data>Prev->data)){
//Left Left or Left Right
printf("\n LEFT LEFT OR LEFT RIGHT\n");
if(Prev2->right==NULL){

//RCWise(&Prev2,false);
Prev2->right=malloc(sizeof(Node));
Prev2->right->right=NULL;
Prev2->right->left=NULL;
Prev2->right->depth=0;
Prev2->right->data=Prev2->data;
Prev2->data=Prev->data;
Prev->data=Data;

}
else{
//FreeAllVisited(Visit);
(*Ptr)=malloc(sizeof(Node));
(*Ptr)->data=Data;
(*Ptr)->depth=Depth(Ptr);
(*Ptr)->left=NULL;
(*Ptr)->right=NULL;
(*Ptr)->depth=0;
}
}
//
//exit(0);
FreeAllVisited(Visit);
printf("\n\nAFTER INSERTION\n\n");
PrintTreeOrder(Origin,0);

//BalanceAllTree(&Origin);

return true;

}
*/


FreeAllVisited(Visit);
(*Ptr)=malloc(sizeof(Node));
(*Ptr)->data=Data;
//(*Ptr)->depth=Depth(Ptr);
(*Ptr)->left=NULL;
(*Ptr)->right=NULL;
(*Ptr)->depth=Depth(Ptr);

//BalanceAllTree(&Origin);

return true;
}
return true;
}

void Search(int Data){
Node** Ptr = &Origin;
if(*Ptr==NULL){
printf("\nData: %d not found in tree\n",Data);
return;
}
while(*Ptr!=NULL){
if(Data>(*Ptr)->data){
Ptr=&((*Ptr)->right);
}
else if(Data< (*Ptr)->data){
Ptr=&((*Ptr)->left);
}
else{
printf("\nFound data:%d\n",(*Ptr)->data);
return;
}
}
if(*Ptr==NULL){
printf("\nData: %d not found in tree\n",Data);
return;
}
return;
}

//Sets Max depth first Tree depth of all nodes
void SetDepth(Node**Ptr){
//Node** Ptr = &Origin;
if(*Ptr==NULL){
//printf("\nData: %d not found in tree\n",Data);
return;
}

(*Ptr)->depth=Depth(Ptr);
SetDepth(&((*Ptr)->right));
SetDepth(&((*Ptr)->left));

/*while(*Ptr!=NULL){
if(Data>(*Ptr)->data){
Ptr=&((*Ptr)->right);
(*Ptr)->depth=Depth(Ptr);
}
else if(Data< (*Ptr)->data){
Ptr=&((*Ptr)->left);
(*Ptr)->depth=Depth(Ptr);
}
}*/
return;
}


void Delete(int Data){
Node** Ptr = &Origin;
if(*Ptr==NULL){
printf("\nData: %d not found in tree\n",Data);
return;
}

while(*Ptr!=NULL){
if(Data>(*Ptr)->data){
Ptr=&((*Ptr)->right);
}
else if(Data< (*Ptr)->data){
Ptr=&((*Ptr)->left);
}

else{
printf("\nFound data to delete:%d\n",(*Ptr)->data);
//Has two children...
if((*Ptr)->right!=NULL&&(*Ptr)->left!=NULL){
Node** P = &((*Ptr)->right->left);
//Left most child of right subtree becomes the new parent, including root right sub or just normal!
PopulateVisited((*Ptr)->right->left,&Visited);

if(!isVisited((*Ptr)->right->left,&Visited)){
printf("\nNO NODES IN SUBTREE, DELETING:%d\n",(*Ptr)->data);
P=&((*Ptr)->right);
(*Ptr)->data=(*P)->data;

(*Ptr)->right=(*Ptr)->right->right;

free(*P);
*P=NULL;
}
else{
Node**S=NULL;
Node** I = P;

while(isVisited(*P,&Visited)){
P=&((*Ptr)->right->left);
while((*P)!=NULL&&isVisited(*P,&Visited)){
printf("\n DATA: %d",(*P)->data);
I=P;
P=&((*P)->left);
}
printf("\n DELETE DATA: %d\n",(*I)->data);
DeleteVisited(*I,&Visited);
if((*I)->left==NULL){
//Have a slot, save to delete
S=I;
(*Ptr)->data=(*I)->data;
(*Ptr)->depth=Depth(Ptr);
(*I)=(*I)->right;
free(*S);
*S=NULL;
//if(S!=NULL){
//if((*S)!=NULL)
//(*Ptr)->data=(*S)->data;
//}
//(*Ptr)->depth=Depth(Ptr);
break;
}
P=&((*Ptr)->right->left);
}
}
FreeAllVisited(Visited);
}
//has only right child
else if((*Ptr)->right!=NULL&&(*Ptr)->left==NULL){
printf("ONLY RIGHT CHILD");
if((*Ptr)==Origin){
//Node** U = &Origin;
Origin=Origin->right;
//free(*U);
//*U=NULL;
return;
}

Node** P = &((*Ptr)->right->left);
//Left most child of right subtree becomes the new parent, including root right sub or just normal!
PopulateVisited((*Ptr)->right->left,&Visited);
//
if(Visited==NULL){
printf("\nNO NODES IN SUBTREE, DELETING:%d\n",(*Ptr)->data);
P=&((*Ptr)->right);
(*Ptr)->data=(*P)->data;

(*Ptr)->right=(*Ptr)->right->right;

free(*P);
*P=NULL;
}
else{
Node**S=NULL;
Node** I = P;
//
while(isVisited(*P,&Visited)){
P=&((*Ptr)->right->left);
while((*P)!=NULL&&isVisited(*P,&Visited)){
printf("\n DATA: %d",(*P)->data);
I=P;
P=&((*P)->left);
}
printf("\n DELETE DATA: %d\n",(*I)->data);
DeleteVisited(*I,&Visited);
if((*I)->left==NULL){
////Have a slot, save to delete
S=I;
(*Ptr)->data=(*I)->data;
(*Ptr)->depth=Depth(Ptr);
(*I)=(*I)->right;
free(*S);
*S=NULL;
break;
}
P=&((*Ptr)->right->left);
}
}
FreeAllVisited(Visited);
}

//has only left child
//Opposite of CASE 1, in order to be correctly balanced
else if((*Ptr)->right==NULL&&(*Ptr)->left!=NULL){
if((*Ptr)==Origin){
//Node** U = &Origin;
Origin=Origin->left;
//free(*U);
//*U=NULL;
return;
}

printf("\n CASE 2\n");

Node** P = &((*Ptr)->left->right);
//Right most child of left subtree becomes the new parent, including root right sub or just normal!
FreeAllVisited(Visited);
PopulateVisited(*P,&Visited);
////
//
printf("\n\nPRINTF VISITED\n");
PrintVisited(&Visited);
if(Visited==NULL){
printf("\nNO NODES IN SUBTREE, DELETING:%d\n",(*Ptr)->data);
P=&((*Ptr)->left);
(*Ptr)->data=(*P)->data;
//
(*Ptr)->left=(*Ptr)->left->left;
//
free(*P);
*P=NULL;
}
else{
printf("MADE IT, Data tree : %d",(*P)->data);
Node**S=NULL;
Node** I = P;
////
while(isVisited(*P,&Visited)){
P=&((*Ptr)->left->right);
while((*P)!=NULL&&isVisited(*P,&Visited)){
printf("\n DATA: %d",(*P)->data);
I=P;
P=&((*P)->left);
}
printf("\n DELETE DATA: %d\n",(*I)->data);
DeleteVisited(*I,&Visited);
if((*I)->left==NULL){
//////Have a slot, save to delete
S=I;
(*Ptr)->data=(*I)->data;
(*Ptr)->depth=Depth(Ptr);
(*I)=(*I)->left;
free(*S);
*S=NULL;
break;
}
P=&((*Ptr)->left->right);
}
}
FreeAllVisited(Visited);
}

//has no children
else if((*Ptr)->right==NULL&&(*Ptr)->left==NULL){
printf("HAS NO CHILDREN");
free(*Ptr);
(*Ptr)=NULL;
}



return;
}

}




return;
}

void PrintTree(Node* T){
//printf("\n INORDER TRAVERSAL \n");

if(T!=NULL){
//printf("LEFT SIDE");
PrintTree(T->left);
//printf("LEFT SIDE");
printf("\nData: %d Depth: %d\n",T->data,T->depth);
//printf("LEFT SIDE");
//printf("RIGHT SIDE");
PrintTree(T->right);
//printf("RIGHT SIDE");
}

return;
}

Node* RCCWise(Node**O,bool LSide){
if((*O)->right==NULL){
printf("\nNo-where more to rotate COUNTER-ClockWise\n");
return *O;
}
//INORDER
//Go all to left and add to visited
//then start from top while not in visited
Node** B = O;
Node** O2=B;
while(*O!=NULL){
AddToVisited(*O,&Visited);
if((*O)->left!=NULL){
//AddToVisited(*O);
}
else{
//AddToVisited(*O);
break;
}
printf("\n\nITERATE DATA:%d\n\n",(*O)->data);
O=&((*O)->left);
}
//Have all nodes visited

Node** P = O2;

//bool First = false;

while(isVisited(*O2,&Visited)){
//O2=&Origin;
/*
if(!isVisited(*O2)){
printf("NO MORE NODES TO VISIT");

break;
}*/
//else{
printf("WHILE O  ! = NULL AND IT WAS VISITED\t");
while((*O2)!=NULL&&isVisited(*O2,&Visited)){
printf("DATA:%d \t\t",(*O2)->data);
P=&(*O2);
O2=&((*O2)->left);
}

if(*O2==NULL){
//First Occurrence, so don't delete all
//AddToVisited(*O2);
//First=true;
}
else{
//Print rest of nodes unused
while(*O2!=NULL){
printf("DATA: %d\t\t",(*O2)->data);
O2=&((*O2)->left);
}
printf("DATA: NULL\t\t");
//First=false;
}
//Go until find last not null node that is stil in visited list
//Prev will be the last visited in list
O2=P;
//THE DATA BEFORE NULLED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
//}
//Then node that has been visited
Node** O3=NULL;
Node** O4=NULL;

//Remove duplicates...
if((*O2)->left!=NULL){
O3 = &((*O2)->left->left);
O4=&((*O2)->left->right);
free((*O2)->left);
(*O2)->left=NULL;
}
//CREATE NEW NODE WHETHER null or not, freed if not null.
(*O2)->left=malloc(sizeof(Node));
(*O2)->left->right=NULL;
if((*O2)->left!=NULL){
(*O2)->left->data=(*O2)->data;
if(O3!=NULL){
(*O2)->left->left=*O3;
}
else{
(*O2)->left->left=NULL;
}
if(O4!=NULL){
(*O2)->left->right=*O4;
}
else{
(*O2)->left->right=NULL;
}
}
else{
printf("ERROR, DATA LOSt");
exit(0);
}

//ORIGIN CHECK
if((*O2)!=*B){
printf("\n\n COPIED GROUP OVER TO NEXT SLOT, CAN DELETE THIS PATH NOW: GROUPER: %d\n",(*O2)->data);
Node** FindLow=&((*O2)->right);
Node** G = &((*O2)->left);
if(*FindLow!=NULL){
while(*G!=NULL&&(*G)->data>(*FindLow)->data){
//(*O2)->left->right=(*O2)->right;
G=&((*G)->left);
}
}
if(*G!=NULL){
printf("\n FOUND LOWER TREE PORTION: %d THAN: %d\n",(*G)->data,(*FindLow) == NULL? 0:(*FindLow)->data);
(*G)->right=(*FindLow);
}
else{
printf("\n\n COULDN'T FIND LOWER PORTION TO APPEND, IMPOSSIBLE DUE TO INSERTION ALGORITHM \n\n");
exit(0);
}
if((*O2)!=*G)
((*O2)->right)=NULL;
//No DUPLICATES
}
//IF IT IS ORIGIN, just replace right sides... No need to check if data is greater
///Because every right node of its left children already are copied over to the next right Slot
printf("\n\n THE AFTERMATH \n\n");
PrintTree(*B);

printf("\nSET NEXT AND DELETE VISITED, GO BACK\n");
DeleteVisited(*O2,&Visited);

//Next cluster 
printf("\n NEXT CLUSTER\n");
printf("\nLAST CURR DATA: %d DEPTH %d\n",(*O2)->data,(*O2)->depth);
//O2=&((*O2)->left);
O2=B;
}

//Final node will be freed, the duplicate

//B IS RELATIVE ORIGIN, NOT ABSOLUTE ORIGIN, KEEP B INTACT, DON'T ALTER OR FREE B, or else would need a pointer to right of B, just rotate relative to it!!

//REINSERT DATA PART 1111111111
//B is BASE is Node**, P and O2 and Node**
P=O2=B;
Node* T =NULL;

//FreeAllVisited(Visited);
//PopulateVisited((*O2)->left);


printf("\n\n\n\n\nPARTYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY 1111");
while((*O2)!=NULL){
P=O2;
//RE INSERT DATA
//Node* T = NULL;
//FreeAllVisited(Visited);
if(P!=B){
PopulateVisited((*P)->left,&Visited);
T=InsertALL(&((*P)->left));
FreeAllVisited(Visited);
(*P)->left=NULL;
/*
if((*P)==(*B)->right){
if((*P)!=NULL){
//FreeTree((*P)->left);
(*P)->left=NULL;
//FreeTree((*P)->left);
}
}
*/
}
printf("\nIS IT SUCCESSFUL INSERT 1?:%d\n",T!=NULL? 1111:-1111);
//(*P)->depth=Depth(P);

//if(O2!=NULL){
if((*O2)!=NULL){
//printf("NOT NULL");
O2=&((*O2)->right);

if(*P!=NULL){
if((*O2)!=NULL){
(*P)->data=(*O2)->data;
}
}
}

}

//Don't free RELATIVE BASE
if(P!=B){
printf("\n NORMAL CASE, NO BASE DUPLICATE!\n");
if((*P)!=NULL){
free(*P);
(*P)=NULL;
}
}
else{
//If it is B, that means that right was Null from the start, and have extra node
printf("\nBASE DUPLICATE!!\n");
P=&((*O2)->left);
free(*O2);
*O2=NULL;
*B = *P;
}

//REINSERT DATA PART 2222222222
printf("PART 22222222222222");
O2=B;
while((*O2)!=NULL){
P=O2;
//RE INSERT DATA
if(P!=B){
PopulateVisited((*P)->right,&Visited);
T=InsertALL(&((*P)->right));
FreeAllVisited(Visited);
}
printf("\nIS IT SUCCESSFUL INSERT 2?:%d\n",T!=NULL? 2222:-2222);
//(*P)->depth=Depth(P);
O2=&((*O2)->left);
}

FreeAllVisited(Visited);
SetDepth(&Origin);
printf("\n\n\n DONEEEEEEEEEEEEEe\n\n\n");

return NULL;
}

Node* RCWise(Node** O, bool rWise){
if((*O)->left==NULL){
printf("\nNo-where more to rotate ClockWise\n");
return *O;
}
//INORDER
//Go all to left and add to visited
//then start from top while not in visited
Node** B = O;
Node** O2=B;
while(*O!=NULL){
AddToVisited(*O,&Visited);
if((*O)->right!=NULL){
//AddToVisited(*O);
}
else{
//AddToVisited(*O);
break;
}
printf("\n\nITERATE DATA:%d\n\n",(*O)->data);
O=&((*O)->right);
}

//Have all nodes visited

Node** P = O2;

//bool First = false;

while(isVisited(*O2,&Visited)){
//O2=&Origin;
/*
if(!isVisited(*O2)){
printf("NO MORE NODES TO VISIT");

break;
}*/
//else{
printf("WHILE O  ! = NULL AND IT WAS VISITED\t");
while((*O2)!=NULL&&isVisited(*O2,&Visited)){
printf("DATA:%d \t\t",(*O2)->data);
P=&(*O2);
O2=&((*O2)->right);
}

if(*O2==NULL){
//First Occurrence, so don't delete all
//AddToVisited(*O2);
//First=true;
}
else{
//Print rest of nodes unused
while(*O2!=NULL){
printf("DATA: %d\t\t",(*O2)->data);
O2=&((*O2)->right);
}
printf("DATA: NULL\t\t");
//First=false;
}
//Go until find last not null node that is stil in visited list
//Prev will be the last visited in list, so any nodes right of prev is nulled
O2=P;
//THE DATA BEFORE NULLED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
//}
//Then node that has been visited
Node** O3=NULL;
Node** O4=NULL;

//Remove duplicates...
if((*O2)->right!=NULL){
O3 = &((*O2)->right->right);
O4=&((*O2)->right->left);
free((*O2)->right);
(*O2)->right=NULL;
}
//CREATE NEW NODE WHETHER null or not, freed if not null.
(*O2)->right=malloc(sizeof(Node));
//(*O2)->right->left=NULL;
if((*O2)->right!=NULL){
(*O2)->right->data=(*O2)->data;

if(O3!=NULL){
(*O2)->right->right=*O3;
}
else{
(*O2)->right->right=NULL;
}
if(O4!=NULL){
(*O2)->right->left=*O4;
}
else{
(*O2)->right->left=NULL;
}
}
else{
printf("ERROR, DATA LOSt");
exit(0);
}

//ORIGIN CHECK
if((*O2)!=*B){
printf("\n\n COPIED GROUP OVER TO NEXT SLOT, CAN DELETE THIS PATH NOW: GROUPER: %d\n",(*O2)->data);
Node** FindLow=&((*O2)->left);

//The Last Node, in order to save operations!
Node** G = &((*O2)->right);

//Less than for Max side of tree
if(*FindLow!=NULL){
while(*G!=NULL&&(*G)->data<(*FindLow)->data){
//(*O2)->left->right=(*O2)->right;
G=&((*G)->right);
}
}
if(*G!=NULL){
printf("\n FOUND LOWER TREE PORTION: %d THAN: %d\n",(*G)->data,(*FindLow) == NULL? 0:(*FindLow)->data);
(*G)->left=(*FindLow);
}
else{
printf("\n\n COULDN'T FIND LOWER PORTION TO APPEND, IMPOSSIBLE DUE TO INSERTION ALGORITHM \n\n");
exit(0);
}
if((*O2)!=*G)
((*O2)->left)=NULL;
//Remove DUPE
}
//IF IT IS ORIGIN, just replace right sides... No need to check if data is greater
///Because every right node of its left children already are copied over to the next right Slot
printf("\n\n THE AFTERMATH \n\n");
PrintTree(*B);

printf("\nSET NEXT AND DELETE VISITED, GO BACK\n");
DeleteVisited(*O2,&Visited);

//Next cluster 
printf("\n NEXT CLUSTER\n");
printf("\nLAST CURR DATA: %d DEPTH %d\n",(*O2)->data,(*O2)->depth);
//O2=&((*O2)->left);
O2=B;
}

//Final node will be freed, the duplicate

//B IS RELATIVE ORIGIN, NOT ABSOLUTE ORIGIN, KEEP B INTACT, DON'T ALTER OR FREE B, or else would need a pointer to right of B, just rotate relative to it!!

//REINSERT DATA PART 1111111111
//B is BASE is Node**, P and O2 and Node**
P=O2=B;
Node* T=NULL;
//TOO FAR OFF BY ONE

FreeAllVisited(Visited);

//PopulateVisited((*O2)->right);
while((*O2)!=NULL){
P=O2;
//RE INSERT DATA
//Node*  T = NULL;
if(P!=B){
//if((*P)!=(*B)->left){
PopulateVisited((*P)->right,&Visited);
T=InsertALL(&((*P)->right));
FreeAllVisited(Visited);
//}
(*P)->right=NULL;
/*
if((*P)==(*B)->left){
if((*P)!=NULL){
(*P)->right=NULL;
//FreeTree((*P)->right);
}
}
*/
}
printf("\nIS IT SUCCESSFUL INSERT 3?:%d\n",T!=NULL? 3333:-3333);
//(*P)->depth=Depth(P);

if((*O2)!=NULL){
O2=&((*O2)->left);
if((*O2)!=NULL){
(*P)->data=(*O2)->data;
}
}
}

//Don't free RELATIVE BASE
if(P!=B){
printf("\n NORMAL CASE, NO BASE DUPLICATE!\n");
free(*P);
(*P)=NULL;
}
else{
//If it is B, that means that right was Null from the start, and have extra node
printf("\nBASE DUPLICATE!!\n");
P=&((*O2)->right);
free(*O2);
*O2=NULL;
*B = *P;
}

//REINSERT DATA PART 2222222222
O2=B;
while((*O2)!=NULL){
P=O2;
//RE INSERT DATA
if(P!=B){
PopulateVisited((*P)->left,&Visited);
T=InsertALL(&((*P)->left));
FreeAllVisited(Visited);
}
printf("\nIS IT SUCCESSFUL INSERT 4?:%d\n",T!=NULL? 4444:-4444);
//(*P)->depth=Depth(P);
O2=&((*O2)->right);
}

FreeAllVisited(Visited);
SetDepth(&Origin);
printf("\n\n\n DONEEEEEEEEEEEEEe\n\n\n");



return NULL;
}

void AddToVisited(Node*O,VisitNode** V1){
VisitNode** V = V1;
//printf("\n ADD: %d\n",O);
while(*V!=NULL){
V=&((*V)->Next);
}
if(*V==NULL){
*V=malloc(sizeof(VisitNode));
(*V)->N=O;
(*V)->Next=NULL;
}
return;
}


bool isVisited(Node* O,VisitNode** V1){
VisitNode** V = V1;
while(*V!=NULL){
if(((*V)->N)->data==O->data){
return true;
}
//printf("\nDATA: %d\n",(*V)->N->data);
V=&((*V)->Next);
}
return false;
}

void DeleteVisited(Node* O,VisitNode** V1){
//printf("\n\n DELETING VISITED: %d\n",O);
VisitNode** V = V1;
VisitNode**U = V;
while(*V!=NULL){
if((*V)->N==O){
//Dont free, still in tree, just set to next, could be null next or just another node connection.
U=&((*V)->Next);
free(*V);
*V=NULL;
(*V)=(*U);
return;
}
V=&((*V)->Next);
}
return;
}

void FreeAllVisited(VisitNode* V){
VisitNode* U;
while(V!=NULL){
U=V->Next;
free(V);
V=NULL;
V=U;
}


return;
}

void PrintTreeOrder(Node* T, int type){
if(T==NULL){
printf("NULL\n");
return;
}
if(type==0){
printf("\n TREE DATA: %d, TREE DEPTH: %d\n",T->data,T->depth);
PrintTreeOrder(T->left,0);
PrintTreeOrder(T->right,0);


}

return;
}


//USE VISITED TO SEE WHAT NODES ARE ALREADY IN TREE!!!!!
Node* InsertALL(Node** Ptr){
if(Ptr==NULL){
printf("\nNULL POINTER\n");
return NULL;
}
if((*Ptr)==NULL){
//printf("\nALL INSERTED\n");
return NULL;
}
//printf("\nInserting: %d\n",(*Ptr)->data);
//Node** Ptr2 = &((*Ptr)->left);
//Node** Ptr3=&((*Ptr)->right);
VisitNode* U = Visited;
VisitNode* P = U;
while(U!=NULL){
P=U->Next;
//while(isVisited(*Ptr)){
//P=U->Next;
if(Insert((U->N)->data)){
printf("\nINSERTING: %d\n",(U->N)->data);
free(U->N);
(U->N)=NULL;
}
else{
printf("\n\nALREADY IN PRIME POSITION\n\n");

}
DeleteVisited((U->N),&Visited);
//}
U=P;
}

/*
if(*Ptr3!=NULL){
AddToVisited(*Ptr3);
}
*/
/*
if(isVisited(*Ptr)){
Insert((*Ptr)->data);
}
*/
/*
if((*Ptr)->data==0){

printf("\n\nFOUND 0 PARENT\n\n");

}
if(Ptr3!=NULL){
if(*Ptr3!=NULL){
if((*Ptr3)->data==0){
printf("\n\nFOUND 0 CHILD\n\n");
//exit(0);
}
}
}
if(Insert((*Ptr)->data)){
//True if successfully insert
//False if already satisfied criteria

//DeleteVisited(*Ptr);
free(*Ptr);
*Ptr=NULL;
//if(isVisited(*Ptr3))
//Insert((*Ptr3)->data);
InsertALL(Ptr2);
//if(isVisited(*Ptr2))
//Insert((*Ptr2)->data);
InsertALL(Ptr3);
//DeleteVisited(*Ptr2);
//DeleteVisited(*Ptr3);


return NULL;
}
*/
/*
else if(Ptr2!=NULL||Ptr3!=NULL){
if(*Ptr2!=NULL||*Ptr3!=NULL){
//printf("NO INSERT: REMAINING PTR:%d, Ptr2:%d, Ptr3:%d",Ptr!=NULL? (*Ptr)->data:0,Ptr2!=NULL? (*Ptr2)->data:0,Ptr3!=NULL? (*Ptr3)->data:0);
//Still have more nodes to compar

}
}*/
//The pointer(s) to not free!
return (*Ptr);
}

void FreeTree(Node*O){
if(O==NULL){
return;
}
Node* U1=O->left;
Node* U2=O->right;
free(O);
O=NULL;
FreeTree(U1);
FreeTree(U2);
printf("\nTREE IS FREED\n");
return;
}

void PopulateVisited(Node* Ptr,VisitNode**V1){
if(Ptr==NULL){
printf("\nFINISHED POPULATING VISIT TREE\n");
return;
}
AddToVisited(Ptr,V1);
PopulateVisited(Ptr->left,V1);
PopulateVisited(Ptr->right,V1);
return;
}

//Balance all tree
void BalanceAllTree(Node** O){
if(O==NULL){
return;
}
if((*O)==NULL){
return;
}
//while(Depth(&((*O)->right))-Depth(&((*O)->left))>1||Depth(&((*O)->left))-Depth(&((*O)->right))>1){
//printf("\nNEXT NODE:%d\n",(*O)->data);
if(Depth(&((*O)->right))-Depth(&((*O)->left))>0){
//Right HEAVY
RCCWise(O,true);
//O POINTS TO NEW ROOT
}
else if(Depth(&((*O)->left))-Depth(&((*O)->right))>0){
//Left HEAVY
RCWise(O,true);
//O POINTS TO NEW ROOT
}

printf("BALANCED");

//}

BalanceAllTree(&((*O)->left));
BalanceAllTree(&((*O)->right));

return;
}

void PrintVisited(VisitNode** V1){
VisitNode** V = V1;
while(*V!=NULL){
printf("\nVISITNODE Data: %d\n",((*V)->N)->data);
V=&((*V)->Next);
}

return;
}
