#include<stdio.h>
#include<stdlib.h>
int roll_number,marks[3],total;
float percentage;
char name[15];
FILE *f;
void add_new_student_details(){
system("cls");
f=fopen("SRS.txt","a");
printf("\nEnter roll number\n");
scanf("%d",&roll_number);
//fprintf(f,"%d",roll_number);
printf("\nEnter name :");
scanf("%s",name);
fprintf(f,"%d %s",roll_number,name);
total=0;
for(int i=0;i<=2;i++){
    printf("\nEnter marks of %d :",i+1);
    scanf("%d",&marks[i]);
    fprintf(f,"%d",marks[i]);
    total+=marks[i];

}
percentage=(float)total/300*100;
fprintf(f,"%d %f\n",total,percentage);
fclose(f);
printf("\n Student details are added successfully \n");
}


void view_all_student_details(){
    system("cls");
    f=fopen("SRS.txt","r");
    if(f!=NULL){
        printf("Details of all students are\n");
        while(fscanf(f,"%d%s",&roll_number,name)!=EOF){
            printf("\nRollNumber:%d\nName:%s\n",roll_number,name);
            for(int i=0;i<=2;i++){
                fscanf(f,"%d",&marks[i]);
                printf("Marks of subjects %d :%d\n",i+1,marks[i]);            
            }
            fscanf(f,"%d%f",&total,&percentage);
            printf("Total:%d\nPercentage=%.2f\n",total,percentage);
        }
        fclose(f); 
    }
    else{
        printf("\nNo Students details to view\n");

    }
}
void search_student_details(){
    system("cls");
    f-fopen("SRS.txt","r");
    if(f!=NULL){
       int r_no,found=0;
       printf("\nEnter roll number: ");
       scanf("%d",&r_no);
       while(fscanf(f,"%d%s",&roll_number,name)!=EOF){
        for(int i=0;i<=2;i++){
            fscanf(f,"%d",&marks[i]);
        }
        fscanf(f,"%d%f",&total,&percentage);
        if(roll_number==r_no){
            found=1;
            printf("\nDeatils of students are\n");
            printf("\nRoll Number :%d\n Name:%s\n",roll_number,name);
            for(int i=0;i<=2;i++){
                printf("Marks of subject %d:%d\n",i+1,marks[i]);
            }
            printf("Total :%d\nPercentage:%.2f\n",total,percentage);
            break;
        }
       }
       fclose(f);
       if(found==0){
         printf("\nStudent of %d roll number does not exits\n",r_no);
       }
    }
    else{
    printf("\nNo Student details to search\n");
    }
}
int main()
{
    int ch;
    do
    {   
        system("cls");
       //for(int i=0;i<=10000000;i++);
        printf("\nEnter 1 to add new student details\n");
        printf("Enter 2 to view all student details \n");
        printf("Enter 3 to search student details\n");
        printf("Enter 4 to exit from application \n ");
        printf("Enter your choice :");
        scanf("%d",&ch);
        switch(ch){
            case 1:
               add_new_student_details();
               break;
               
            case 2:
                view_all_student_details();
              break;

            case 3:
            search_student_details();
               break;
                
            case 4:
               exit(0);
               
            default : 
              printf("\nWrong Choice\n"); 

        }
        printf("\nEnter 1 to go to menu\n");
        scanf("%d",&ch);
    }while(ch==1);
}