#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct shoes
{
    int id;
    char name[20];
    char brand[20];
    int price;
    int numberRemain;
    int numberSold;
    char hk[15];
};
typedef struct shoes SHOES;

struct node
{
    SHOES data;
    node *next;
};
typedef struct node NODE;
struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

void init(LIST &ds)
{
    ds.pHead = NULL;
    ds.pTail = NULL;
}

int checkNULL(LIST ds)
{
    if (ds.pHead == NULL)
    {
        return 1;
    }
    return 0;
}
NODE *initNode(SHOES x)
{
    NODE *p;
    p = new NODE;
    if (p == NULL)
    {
        printf("KHONG DU BO NHO");
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}
void insertEnd(LIST &ds, NODE *p)
{
    if (ds.pHead == NULL)
    {
        ds.pHead = p;
        ds.pTail = p;
    }
    else
    {
        ds.pTail->next = p;
        ds.pTail = p;
    }
}
void Enter(LIST &ds, int n)
{
    printf("Enter INFORMATION OF SHOSE\n");
    for (int i = 0; i < n; i++)
    {
        SHOES x;
        printf("Enter ID : ");
        fflush(stdin);
        scanf("%d", &x.id);
        printf("Enter Name: ");
        fflush(stdin);
        gets(x.name);
        printf("Enter Brand : ");
        fflush(stdin);
        gets(x.brand);
        printf("Enter Price : ");
        fflush(stdin);
        scanf("%d", &x.price);
        printf("Enter Number Remaining : ");
        fflush(stdin);
        scanf("%d", &x.numberRemain);
        printf("Enter Number of Products Sold : ");
        fflush(stdin);
        scanf("%d", &x.numberSold);
        printf("\n \n");
        NODE *p = new NODE;
        p = initNode(x);
        insertEnd(ds, p);
    }
}
void Print(LIST ds)
{
    for (NODE *p = ds.pHead; p != NULL; p = p->next)
    {
        printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",
               p->data.id, p->data.name, p->data.brand, p->data.price, p->data.numberRemain, p->data.numberSold, p->data.hk);
    }
}
void SVD13CNPM(LIST ds)
{
    for (NODE *p = ds.pHead; p != NULL; p = p->next)
    {
        if (strcmp(p->data.brand, "D13CNPM") == 0)
        {
            printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",
                   p->data.id, p->data.name, p->data.brand, p->data.price, p->data.numberRemain, p->data.numberSold, p->data.hk);
        }
    }
}

NODE *FindId(LIST ds, int id)
{
    for (NODE *p = ds.pHead; p != NULL; p = p->next)
    {
        if (p->data.id == id)
        {
            return p;
        }
    }
}

void Sort(LIST &ds)
{
    NODE *p, *q;
    for (p = ds.pHead; p != ds.pTail; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data.id > q->data.id)
            {
                SHOES x = p->data;
                p->data = q->data;
                q->data = x;
            }
        }
    }
    Print(ds);
}
void XoaCuoi(LIST &ds)
{
    for (NODE *k = ds.pHead; k != NULL; k = k->next)
    {
        if (k->next == ds.pTail)
        {
            delete ds.pTail;
            k->next = NULL;
            ds.pTail = k;
        }
    }
    Print(ds);
}

int main()
{
    
}