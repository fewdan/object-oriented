#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

struct Node{
    int num;
    Node * next;
};

int x;

void doing ()
{
    Node* head=(Node*)malloc(sizeof(Node));
    Node* last=(Node*)malloc(sizeof(Node));
    Node* rail=(Node*)malloc(sizeof(Node));
    //scanf("%d",&x);
    //if (x==-1) return;
    head->next=NULL;
    head->num=0;
    last=head;
    while (scanf("%d",&x) && x!=-1)
    {
        Node* newnode=(Node*)malloc(sizeof(Node));
        newnode->num=x;
        last->next=newnode;
        last=newnode;
    }
    last->next=rail;
    rail->num=-1;
    rail->next=NULL;

    Node *now=head->next;
    last=head;
    while (1)
    {
        if (now->num%2==0)
        {
            last->next=now->next;
            free(now);
        }
        else
        {
            last=now;
        }
        if (now->next==NULL) break;
        now=now->next;
    }
    if (head->next==rail)
      return ;
    now=head->next;
    while (1)
    {
        if (now->next!=rail)
          printf("%d ",now->num);
        else printf("%d",now->num);
        free(now);
        now=now->next;
        if (now->next==NULL) break;
    }
    putchar('\n');
    free(head);
    free(last);
}

int main ()
{
    doing ();
    return 0;
}