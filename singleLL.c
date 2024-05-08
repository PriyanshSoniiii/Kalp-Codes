#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
void begin_insert();   
void last_insert();  
void random_insert();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search();  
void main ()  
{  
    int choice = 0;  
    while(choice != 9)   
    {   
        printf("\n1.Insert at begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            begin_insert();      
            break;  
            case 2:  
            last_insert();         
            break;  
            case 3:  
            random_insert();       
            break;  
            case 4:  
            begin_delete();       
            break;  
            case 5:  
            last_delete();        
            break;  
            case 6:  
            random_delete();          
            break;  
            case 7:  
            search();         
            break;  
            case 8:  
            display();        
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("enter a valid choice");  
        }  
    }  
}  
void begin_insert()  
{  
    struct node *ptr;  
    int val;
    ptr = (struct node *) malloc(sizeof(struct node *));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&val);    
        ptr->data = val;  
        ptr->next = head;  
        head = ptr; 
    }  
      
}  
void last_insert()  
{  
    struct node *ptr,*temp;  
    int val;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value\n");  
        scanf("%d",&val);  
        ptr->data = val;  
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;   
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
        }  
    }  
}  
void random_insert()  
{  
    int pos,val,i;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value");  
        scanf("%d",&val);  
        ptr->data = val;  
        printf("\nEnter pos after which you want to insert ");  
        scanf("\n%d",&pos);  
        temp=head;  
        for(i=0;i<pos;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\nReached end of LL\n");  
                return;  
            }  
          
        }  
        ptr ->next = temp ->next;   
        temp ->next = ptr;     
    }  
}  
void begin_delete()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nLL is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr); 
    }  
}  
void last_delete()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nLL is empty");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);
    }         
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
    }     
}  
void random_delete()  
{  
    struct node *ptr,*ptr1;  
    int pos,i;    
    printf("\n Enter pos of the node after which you want to perform deletion \n");  
    scanf("%d",&pos);  
    ptr=head;  
    for(i=0;i<pos;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
}  
void search()  
{  
    struct node *ptr;  
    int pos,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nLL is empty\n");  
    }  
    else  
    {   
        printf("\nEnter pos to search\n");   
        scanf("%d",&pos);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == pos)  
            {  
                printf("pos found at location %d ",i+1);  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("pos not found\n");  
        }  
    }     
          
}  
  
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("LL is Empty");  
    }  
    else  
    {  
        printf("\n------\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    } 
     printf("\n\n");   
}     