#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char *ID;
    struct Node * next;
};

struct Node* createInputList(struct Node* head, char *input){
    char* value = strtok(input, " ");
    struct Node *newNode = NULL;  
    while (value != NULL) {
        newNode = (struct Node *)malloc(sizeof(struct Node *));  
        newNode->ID = (char *)malloc(sizeof(value));      
        strcpy(newNode->ID,value);   
        newNode->next = head;  
        head = newNode; 
        value = strtok(NULL, " ");
    }
    return head;
}

void printList(struct Node* list){
    while(list!=NULL){
        printf("%s -> ",list->ID);
        list = list->next;
    }
    printf("\n");
}


struct Node* createCommonList(struct Node* CommonList, struct Node* l1, struct Node* l2){
   
    struct Node *newNode = NULL; 

    struct Node *ptri = l1;
    struct Node *ptrj = NULL;

    while(ptri!=NULL){
        ptrj = l2;
        while(ptrj!=NULL){
            if(strcmp(ptri->ID,ptrj->ID)==0){
                newNode = (struct Node *)malloc(sizeof(struct Node *));  
                newNode->ID = (char *)malloc(sizeof(ptri->ID));      
                strcpy(newNode->ID,ptri->ID);   
                newNode->next = CommonList;  
                CommonList = newNode; 
            }  
            ptrj = ptrj->next;
        }
        ptri = ptri->next;
    }
    return CommonList;
}



struct Node* createUniqueList(struct Node* UniqueList, struct Node* l1, struct Node* l2,struct Node* CommonList){
   
    struct Node *newNode = NULL; 

    struct Node *ptrj = l1;
    while(ptrj!=NULL){
        newNode = (struct Node *)malloc(sizeof(struct Node *));  
        newNode->ID = (char *)malloc(sizeof(ptrj->ID));      
        strcpy(newNode->ID,ptrj->ID);   
        newNode->next = UniqueList;  
        UniqueList = newNode;   
        ptrj = ptrj->next;
    }

    ptrj = l2;
    struct Node* ptri = CommonList;
    int flag = 0;
    while(ptrj!=NULL){
        ptri = CommonList;
        while(ptri!=NULL){
            if(strcmp(ptrj->ID,ptri->ID)==0){
                flag = 1;
                break;
            }
            ptri=ptri->next;
        }
        if(flag == 0){
            newNode = (struct Node *)malloc(sizeof(struct Node *));  
            newNode->ID = (char *)malloc(sizeof(ptrj->ID));      
            strcpy(newNode->ID,ptrj->ID);   
            newNode->next = UniqueList;  
            UniqueList = newNode;
        }
        flag = 0;   
        ptrj = ptrj->next;
    }


    return UniqueList;
}






int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    char l1[9024];
    char l2[9024];

    fgets(l1, sizeof(l1), stdin);
    fgets(l2, sizeof(l2), stdin);

    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;
    struct Node *head4 = NULL;


     head1 = createInputList(head1,l1);
     head2 = createInputList(head2,l2);
     head3 = createCommonList(head3,head1,head2);
     head4 = createUniqueList(head4,head1,head2,head3);
     printList(head3);
     printList(head4);
  
    return 0;
}

/*
ITT/101 ITT/103 ITT/105 ITT/102 
ITT/105 ITT/107 ITT/109 ITT/101 
*/

