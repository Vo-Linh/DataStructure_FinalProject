#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ======================================================================
// *                      Define Structure Brand                        *
// ======================================================================

struct brand    
{
    int id;
    char name[20];
    int amount;
    int numberBrand;
};
typedef struct brand BRAND;

struct node
{
    BRAND data;
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
NODE *initNode(BRAND x)
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
        BRAND x;
        printf("Enter ID : ");
        fflush(stdin);
        scanf("%d", &x.id);
        printf("Enter Name: ");
        fflush(stdin);
        gets(x.name);
        printf("Enter amount of shose: ");
        fflush(stdin);
        scanf("%d", &x.amount);
        printf("Enter Number Brand : ");
        fflush(stdin);
        scanf("%d", &x.numberBrand);
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
        printf("%d\t |%s\t |%d\t |%d\t \n",
               p->data.id, p->data.name, p->data.amount, p->data.numberBrand);
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
                BRAND x = p->data;
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

    LIST ds;
    int n;

    int status;
    while (1)
    {
        printf("1-> Enter data\n");
        printf("2-> Find\n");
        printf("3-> Print Payment\n");
        printf("4-> Turnover\n");
        printf("0-> Out program\n");
        scanf("%d", &status);
        if (status == 1)
        {
            printf("Enter N: ");
            scanf("%d", &n);
            init(ds);
            Enter(ds, n);
            printf("\nDANH SACH HANG\n");
            Print(ds);
        }
        else if (status == 2)
        {
            printf("\nTINH NANG DANG GIAI DOAN PHAT TRIEN \n");
            printf("====================================== \n \n");
            continue;
        }
        else if (status == 3)
        {
            printf("\nTINH NANG DANG GIAI DOAN PHAT TRIEN \n");
            printf("====================================== \n \n");
            continue;
        }
        else if (status == 4)
        {
            printf("\nTINH NANG DANG GIAI DOAN PHAT TRIEN \n");
            printf("====================================== \n \n");
            continue;
        }
        else
        {
            break;
        }
    }
}