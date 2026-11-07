#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main() {
    int choice;
    struct node *head=NULL;
    do {
        printf("\n1. add at head\n");
        printf("2. add in between\n");
        printf("3. add at end\n");
        printf("4. delete at head\n");
        printf("5. delete at specific position\n");
        printf("6. delete at end\n");
        printf("7. print linked list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: {
                int addathead;
                printf("Enter value to add at head\n");
                scanf("%d",&addathead);
                struct node *temp=(struct node *)malloc(sizeof(struct node));
                temp->data=addathead;
                temp->next=head;
                head=temp;
                break;
            }
            case 2: {
                int atinbetween, pos;
                struct node *itr=head;
                printf("Enter the value and position (0-indexed):\n");
                scanf("%d %d",&atinbetween,&pos);
                struct node *temp=(struct node *)malloc(sizeof(struct node));
                temp->data=atinbetween;
                if(pos==0) {
                    temp->next=head;
                    head=temp;
                    break;
                }
                int inserted=0;
                for(int i=0; itr!=NULL; i++) {
                    if(i==pos-1) {
                        temp->next=itr->next;
                        itr->next=temp;
                        inserted=1;
                        break;
                    }
                    itr=itr->next;
                }
                if(!inserted) {
                    printf("Position out of bounds\n");
                    free(temp);
                }
                break;
            }
            case 3: {
                int addatend;
                printf("Enter value to add at end\n");
                scanf("%d",&addatend);
                struct node *temp=(struct node *)malloc(sizeof(struct node));
                temp->data=addatend;
                temp->next=NULL;
                if(head==NULL) {
                    head=temp;
                } else {
                    struct node *itr=head;
                    while(itr->next!=NULL) {
                        itr=itr->next;
                    }
                    itr->next=temp;
                }
                break;
            }
            case 4: {
                if(head==NULL) {
                    printf("List is empty\n");
                } else {
                    struct node *temp=head;
                    head=head->next;
                    printf("Deleted %d\n", temp->data);
                    free(temp);
                }
                break;
            }
            case 5: {
                if(head==NULL) {
                    printf("List is empty\n");
                    break;
                }
                int pos;
                printf("Enter position to delete (0-indexed):\n");
                scanf("%d",&pos);
                if(pos==0) {
                    struct node *temp=head;
                    head=head->next;
                    printf("Deleted %d\n", temp->data);
                    free(temp);
                    break;
                }
                struct node *itr=head;
                int deleted=0;
                for(int i=0; itr!=NULL && itr->next!=NULL; i++) {
                    if(i==pos-1) {
                        struct node *temp=itr->next;
                        itr->next=temp->next;
                        printf("Deleted %d\n", temp->data);
                        free(temp);
                        deleted=1;
                        break;
                    }
                    itr=itr->next;
                }
                if(!deleted) {
                    printf("Position out of bounds\n");
                }
                break;
            }
            case 6: {
                if(head==NULL) {
                    printf("List is empty\n");
                } else if(head->next==NULL) {
                    printf("Deleted %d\n", head->data);
                    free(head);
                    head=NULL;
                } else {
                    struct node *itr=head;
                    while(itr->next->next!=NULL) {
                        itr=itr->next;
                    }
                    printf("Deleted %d\n", itr->next->data);
                    free(itr->next);
                    itr->next=NULL;
                }
                break;
            }
            case 7: {
                struct node *itr=head;
                if(itr==NULL) {
                    printf("List is empty\n");
                } else {
                    while(itr!=NULL) {
                        printf("%d -> ", itr->data);
                        itr=itr->next;
                    }
                    printf("NULL\n");
                }
                break;
            }
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
        
    } while(choice!=9);
    return 0;
}

