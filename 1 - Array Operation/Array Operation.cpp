#include<stdio.h>
#include<stdlib.h>

void menu(int a[],int size);
void arrayAdd(int a[],int size){
		int i;
		printf("Enter %d elements: ");
		for(i=0;i<size;i++){
			scanf("%d",&a[i]);
		}
		printf("\nElements Added.");
		system("cls");
		
		menu(a,size);
}
int arrayDisp(int a[],int size){
	int i;
	printf("\nnThe ELements in array are:\n");
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}	
	printf("\n\n");
	menu(a,size);
}
int arrayIns(int a[],int size){
	int i,pos,newElem;
	printf("Enter Position to Insert Element: ");
	scanf("%d",&pos);
	
	while(pos>size)
	{
		printf("Out of Bounds Position cant be greater then size. Re Enter:\n\n");
		printf("ENter Position to Insert Element: ");
		scanf("%d",&pos);
	}
	printf("Enter Element to be inserted: ");
	scanf("%d",&newElem);
	
	for(i = size-1;i>=pos;i--){
		a[i+1]=a[i];
		
	}
	a[pos] = newElem;
	size++;	
	printf("Value Inserted");
	system("cls");
	menu(a,size);
	return size;
}
	
int arrayDel(int a[],int size){
	int i,pos,element;
	
	printf("\nEnter the position of element to be deleted: ");
	scanf("%d", &pos);
	
	element = a[pos];
	for(i = pos;i<=size-1;i++){
		a[i]=a[i+1];
	}
	size--;	
	printf("Value Deleted");
	
	system("cls");
	menu(a,size);
	return size;
}

void menu(int a[],int size){
	int opt = -1;
	printf("\n1. Add element in array:\n");
	printf("2. Display Array Elements:\n");
	printf("3. Insert Array Elment:\n");
	printf("4. Delete element in an array:\n");
	printf("5. Exit\n");

	printf("Choose Among 5 options:\n ");
	scanf("%d",&opt);

	switch (opt){
		
		system("cls");
		case 1:
			arrayAdd(a,size);
			break;
		case 2:
			
			arrayDisp(a,size);
			break;
		case  3:
			size = arrayIns(a,size);
			break;
		case 4:
			size = arrayDel(a,size);
			break;
		case 5:
			printf("Exit Sequence");
			exit(0);
			break;
			
		default:
		
			printf("Invalid Input. Retry:\n");
			menu(a,size);
	}
}

int main(){
	int a[100];
	int size=0;
	printf("Enter Size of Array: ");
	scanf("%d",&size);
	menu(a,size);	
}
