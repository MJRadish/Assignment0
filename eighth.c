//Binary Tree in C, reads from a txt file in the format:
//i	5 (i->tab->data_to_insert)
//s	4  (i->tab->data_to_search_for)
//d	6 (d->tab->data_to_delete)
//Outputs the contents of the tree


# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
	
struct Junk{ int data; struct Junk* left; struct Junk* right; int size;};

typedef struct Junk Node;

//Node LinkedList;
int size;
int sizeLeft;
int sizeRight;


Node* Origin;

void Rm(Node *F);

int UPALL(Node **ptr);

void addData(int Data, Node** ptr);

int UpdateSize(Node**ptr);
//void deleteData(int Data);

int printData(Node* ptr);
				
int main (int argc, char*  argv[]){

Origin = 0;

Node** ptr = NULL;
if(argc>2||argc<2){
printf("Too many or not enough arguments!");
return -1;
}

FILE * accessed = fopen(argv[1],"r");

if(accessed == NULL){

printf("0");

fclose(accessed);

return 0;						


}else {
char op;
int entry;


while(fscanf(accessed, "%c\t%d\n", &op, &entry) != EOF){

if(op=='i'){
addData(entry,&Origin);


}
else if(op=='d'){
//deleteData(entry);

}
else{

continue;

}



}
fclose(accessed);

}

//ptr=Origin;

ptr=&Origin;
/*
addData(-1,ptr);


addData(1,ptr);

addData(2,ptr);
addData(0,ptr);
addData(3,ptr);
*/
/*
deleteData(-1);
deleteData(1);
deleteData(0);
deleteData(2);
deleteData(3);
*/

printf("FINAL:\n");

printData(Origin);

//free(Origin);

Rm(Origin);
//free(ptr);
return 0;
}


////////////////////////////////////////////////////////////////////

void addData(int Data,Node**ptr){ 

if(*ptr==0){
*ptr = malloc(sizeof(Node));
(*ptr)->data=Data;

(*ptr)->left=0;
(*ptr)->right=0;

size++;

//Node** temp = malloc(sizeof(Node*));
//temp = &Origin;
//Node**t = temp;

UPALL(&Origin);

//free(t);
//t=NULL;

return;
}

else if(Data>(*ptr)->data){
//ptr=ptr->right;
addData(Data, &(*ptr)->right);

}
else if(Data<(*ptr)->data){
//ptr=ptr->left;
addData(Data, &(*ptr)->left);

}

return;
}


void Rm(Node*F){

	if(F!=0)
	{
	Rm(F->left);
	Rm(F->right);
	free(F);
	}

	return;


}


int printData(Node*ptr){
//ptr=Origin;
if(ptr==NULL){
printf("NULL\n");
return 0;
}
else{
printf("%d\n Size: %d\n",ptr->data, ptr->size);

printData(ptr->left)+printData(ptr->right);

}
return 0;
}



int UPALL(Node **ptr){
if((*ptr)==0){
return 0;
}
else{
int size = UpdateSize(ptr);
printf("Ptr: %d", (*ptr)->data);
printf("Size of this ptr:%d\n", size);
(*ptr)->size=UpdateSize(ptr);

return UPALL(&(*ptr)->right) + UPALL(&(*ptr)->left);
}




return 0;
}

int UpdateSize(Node **ptr){
//*(ptr) is the ptr to the tree!!!
if(*ptr==0){
printf("MADE IT 0");
return 0;
}
else if((*ptr)->left!=0&&(*ptr)->right!=0){
printf("MADE IT 1");

return 2+UpdateSize(&(*ptr)->left)+UpdateSize(&(*ptr)->right);

}
else if((*ptr)->left==0&&(*ptr)->right!=0){
printf("MADE IT 2");


return 1+ UpdateSize(&(*ptr)->right);

}
else if((*ptr)->left!=0&&(*ptr)->right==0){
printf("MADE IT 3");
//ADDRESSSSS

return 1+UpdateSize(&(*ptr)->left);

}
else if((*ptr)->left==0&&(*ptr)->right==0){
printf("MADE IT 4");
return 0;

}


}
