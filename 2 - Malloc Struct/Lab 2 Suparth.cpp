#include<stdio.h>
#include<stdlib.h>


struct student{
	char name[50];
	int roll;
	float percentage;
};

student *pStd;

void getData(int n){
	int i;
	for(int i=0;i<n;i++){
		printf("FOr Student %d\n",i+1);
		printf("Enter roll no of student: ");
		scanf("%d",&(pStd+i)->roll);
		printf("Enter name of student: ");
		scanf("%s",&(pStd+i)->name);
		printf("Enter %% of student: ");
		scanf("%f",&(pStd+i)->percentage);	
		printf("\n\n");
		}
	for(i=0;i<n;i++){
		printf("Roll No of student: %d\n",(pStd+i)->roll);
		printf("Name of student: %s\n",(pStd+i)->name);
		printf("Percentage of student: %0.3f\n\n",(pStd+i)->percentage);
	}
}



int main(){
	int n;
	printf("Enter total number of students: ");
	scanf("%d",&n);
	pStd = (struct student*)malloc(n*sizeof(struct student));	
	
	getData(n);
	
	
	free (pStd);
}

