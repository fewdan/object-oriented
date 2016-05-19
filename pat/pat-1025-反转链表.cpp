#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;

struct data{
    int add,nextadd,num;
    data * next;
    //data * pre;
};

int first,n,k;
int ad,a[100010],nex[100010];
int bh[100010];

data* reverse (data *head)
{
    data *newHead=NULL;
    data *prev=NULL;
    data *begin=head;
    data *end=head;
    data *p=NULL;
    data *q=NULL;
    while (begin)
    {
        int count=k-1;
        end=begin;
        while (count && end->next!=NULL)
        {
            end=end->next;
            count--;
        }
        if (count!=0)
        {
            if (newHead==NULL)
            {
                newHead=begin;
            }
            else
            {
                prev->next=begin;
            }
            return newHead;
        }
        p=begin->next;
        q=begin;
        while (q!=end)
        {
            data *temp=p->next;
            p->next=q;
            q=p;
            p=temp;
        }
        if (prev==NULL)
        {
            newHead=end;
        }
        else
        {
            prev->next=end;
        }
        prev=begin;
        prev->next=NULL;

        begin=p;
    }

    return newHead;
}


void doing ()
{
    cin>>first>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>ad;
        cin>>a[ad]>>nex[ad];
    }
    data* head=(data*)malloc(sizeof(data));
    head->num=a[first];
    head->add=first;
    head->nextadd=nex[first];
    head->next=NULL;
    bool p=0;
    if (head->nextadd==-1)
        p=1;
    //head->pre=NULL;
    data* last=head;
    int now=nex[first];
    int cnt=1;
    while (!p)
    {
        cnt++;
        data* newnode=(data*)malloc(sizeof(data));
        newnode->num=a[now];
        newnode->add=now;
        newnode->nextadd=nex[now];
        last->next=newnode;
        //newnode->pre=last;
        now=nex[now];
        last=newnode;
        if (now==-1)
        {
            newnode->next=NULL; break;
        }
    }
    data* nowd=head;
    nowd=head;
    /*cout<<"============="<<endl;
    while (1)
    {
        if (nowd->nextadd!=-1)
          printf ("%05d %d %05d\n",nowd->add,nowd->num,nowd->nextadd);
        else
          printf ("%05d %d %d\n",nowd->add,nowd->num,nowd->nextadd);
        //cout<<nowd->add<<" "<<nowd->num<<" "<<nowd->nextadd<<endl;
        if (nowd->next==NULL) break;
        nowd=nowd->next;
    }cout<<"============="<<endl;*/
    if (k!=1)
      nowd=reverse(head);
    cnt=0;
    data *nowdd=nowd;
    while (1)
    {
        if (nowdd->next!=NULL)
          bh[++cnt]=(nowdd->next)->add;
        else bh[++cnt]=-1;
        if (nowdd->next==NULL) break;
        nowdd=nowdd->next;
    }
    //for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    //cout<<"============="<<endl;
    cnt=0;
    while (1)
    {
        /*if (nowd->nextadd!=-1)
          printf ("%05d %d %05d\n",nowd->add,nowd->num,nowd->nextadd);
        else
          printf ("%05d %d %d\n",nowd->add,nowd->num,nowd->nextadd);*/
        if (bh[cnt+1]!=-1)
          printf ("%05d %d %05d\n",nowd->add,nowd->num,bh[++cnt]);
        else
          printf ("%05d %d %d\n",nowd->add,nowd->num,bh[++cnt]);
        //cout<<nowd->add<<" "<<nowd->num<<" "<<nowd->nextadd<<endl;
        if (nowd->next==NULL) break;
        nowd=nowd->next;
    }//cout<<"============="<<endl;

    //cout<<sizeof(a)+sizeof(bh)+sizeof(nex)+sizeof(data)*100010<<endl;
}

int main ()
{
    doing ();
    return 0;
}