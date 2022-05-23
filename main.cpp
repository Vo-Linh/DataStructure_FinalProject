#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cctype>
#include <iostream>
using namespace std;

// ======================================================================
// *                      Define Structure Shose                        *
// ======================================================================
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

struct nodeShose
{
    SHOES data;
    nodeShose *next;
};
typedef struct nodeShose NODE_SHOSE;
struct listShose
{
    NODE_SHOSE *pHead;
    NODE_SHOSE *pTail;
};
typedef struct listShose LIST_SHOSE;

void initShose(LIST_SHOSE &ds)
{
    ds.pHead = NULL;
    ds.pTail = NULL;
}

NODE_SHOSE *initShose(SHOES x)
{
    NODE_SHOSE *p;
    p = new NODE_SHOSE;
    if (p == NULL)
    {
        printf("KHONG DU BO NHO");
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void insertShose(LIST_SHOSE &ds, NODE_SHOSE *p)
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

void enterShose(LIST_SHOSE &ds, int n)
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
        // x.brand = (char)tolower(brand); // convert to lower
        printf("Enter Price ($): ");
        fflush(stdin);
        scanf("%d", &x.price);
        printf("Enter Number Remaining : ");
        fflush(stdin);
        scanf("%d", &x.numberRemain);
        printf("Enter Number of Products Sold : ");
        fflush(stdin);
        scanf("%d", &x.numberSold);
        printf("Enter Review : ");
        fflush(stdin);
        gets(x.hk);
        printf("\n \n");
        NODE_SHOSE *p = new NODE_SHOSE;
        p = initShose(x);
        insertShose(ds, p);
    }
}
void Print_Shose(LIST_SHOSE ds)
{
    for (NODE_SHOSE *p = ds.pHead; p != NULL; p = p->next)
    {
        printf("%d\t |%s\t |%s\t |%d\t %d\t |%d\t |%s\n",
               p->data.id, p->data.name, p->data.brand, p->data.price, p->data.numberRemain, p->data.numberSold, p->data.hk);
    }
}
// ========== XXX print base on brand ===============
void printBrand(LIST_SHOSE ds)
{
    char brand[10];
    int count = 0;
    printf("Nhap brand can hien thi: ");
    gets(brand);

    for (NODE_SHOSE *p = ds.pHead; p != NULL; p = p->next)
    {
        if (strcmp(p->data.brand, brand) == 0)
        {
            printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",
                   p->data.id, p->data.name, p->data.brand, p->data.price, p->data.numberRemain, p->data.numberSold, p->data.hk);
            count += 1;
        }
    }
    if (count == 0)
    {
        printf("Khong co brand ten %s\n", brand);
        printf("Vui long nhap dung ten Brand\n");
        printf("Danh sach cac brand hien co: \n");
        for (NODE_SHOSE *p = ds.pHead; p != NULL; p = p->next)
        {
            printf("%s \n", p->data.brand);
        }
    }
}

int checkNULL(LIST_SHOSE ds)
{
    if (ds.pHead == NULL)
    {
        return 1;
    }
    return 0;
}

void sortShose(LIST_SHOSE &ds)
{
    NODE_SHOSE *p, *q; // init
    for (p = ds.pHead; p != ds.pTail; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data.id > q->data.id) // compare
            {
                SHOES x = p->data;
                p->data = q->data;
                q->data = x;
            }
        }
    }
}
void XoaCuoi(LIST_SHOSE &ds)
{
    for (NODE_SHOSE *k = ds.pHead; k != NULL; k = k->next)
    {
        if (k->next == ds.pTail)
        {
            delete ds.pTail;
            k->next = NULL;
            ds.pTail = k;
        }
    }
}

// ====================== End Manage Shose ============================

// ======================================================================
// *                      Define Structure Brand                        *
// ======================================================================
struct brand
{
    int id;
    char name[20];
    int numberBrand;
};
typedef struct brand BRAND;

struct nodeBrand
{
    BRAND data;
    nodeBrand *next;
};
typedef struct nodeBrand NODE_BRAND;

struct listBrand
{
    NODE_BRAND *pHead;
    NODE_BRAND *pTail;
};
typedef struct listBrand LIST_BRAND;

NODE_BRAND *initBrand(BRAND x)
{
    NODE_BRAND *p;
    p = new NODE_BRAND;
    if (p == NULL)
    {
        printf("KHONG DU BO NHO");
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void insertBrand(LIST_BRAND &ds_brand, NODE_BRAND *ptr)
{
    if (ds_brand.pHead == NULL)
    {
        ds_brand.pHead = ptr;
        ds_brand.pTail = ptr;
    }
    else
    {
        ds_brand.pTail->next = ptr;
        ds_brand.pTail = ptr;
    }
}
void EnterBrand(LIST_BRAND &ds, int n)
{
    printf("Enter INFORMATION OF Brand\n");
    for (int i = 0; i < n; i++)
    {
        BRAND x;
        printf("Enter ID : ");
        fflush(stdin);
        scanf("%d", &x.id);
        printf("Enter Name: ");
        fflush(stdin);
        gets(x.name);
        printf("Enter Number Brand : ");
        fflush(stdin);
        scanf("%d", &x.numberBrand);
        printf("\n \n");
        NODE_BRAND *p = new NODE_BRAND;
        p = initBrand(x);
        insertBrand(ds, p);
    }
}

void shose2brand(LIST_BRAND dsBrand, LIST_SHOSE dsShose)
{
    string current[10];
    int count = 0;
    int same = 0;
    for (NODE_SHOSE *p = dsShose.pHead; p != NULL; p = p->next)
    {
        current[count] = p->data.brand;
        count++;
    }
    sort(current, current + count);
    //  Delete emlement same value
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (current[i] == current[j])
            {
                for (int k = j; k < count - 1; k++)
                {
                    current[k] = current[k + 1];
                }
                count--;
                j--;
            }
        }
    }
    printf("ID\t |Name\t |Number\t \n");
    printf("-------------------------\n");
    for (int i = 0; i < count; i++)
    {
        BRAND x;
        int c = 0;
        strcpy(x.name, current[i].c_str());
        for (NODE_SHOSE *p = dsShose.pHead; p != NULL; p = p->next)
        {
            if (current[i] == p->data.brand)
            {
                c++;
            }
        }
        x.numberBrand = c;
        x.id = i;

        printf("%d\t |%s\t |%d\t \n", x.id, x.name, x.numberBrand);
        NODE_BRAND *ptr = new NODE_BRAND;
        ptr = initBrand(x);
        insertBrand(dsBrand, ptr);
    }
}
void Print_Brand(LIST_BRAND ds)
{
    for (NODE_BRAND *p = ds.pHead; p != NULL; p = p->next)
    {
        printf("%d\t |%s\t |%d\t \n", p->data.id, p->data.name, p->data.numberBrand);
    }
}
// ====================== End Manage Brand ============================

// ======================================================================
// *                      Define Structure Customer                     *
// ======================================================================

struct customer
{
    char id[20];
    char name[20];
    double money;
};
struct Node
{
    customer key;
    Node *Left, *Right;
};
typedef Node *Tree; //cay

int compare(customer x, customer y)
{
    return strcmp(x.id, y.id);
}

customer inputItem()
{
    customer x;
    char id[20];
    printf("Enter id of customer : ");
    fflush(stdin);
    gets(x.id);

    printf("Enter name of customer: ");
    fflush(stdin);
    gets(x.name);

    printf("Enter money($):");
    fflush(stdin);
    scanf("%lf", &x.money);

    fflush(stdin);
    while (getchar() != '\n')
        ;

    return x;
}

void outItem(customer x)
{
    printf("%-20s %-20s %-3.2f \n", x.id, x.name, x.money);
}

int insertNode(Tree &T, customer x) // chen 1 Node vao cay
{
    if (T != NULL)
    {
        if (compare(T->key, x) == 0)
            return -1; // Node nay da co
        if (compare(T->key, x) > 0)
            return insertNode(T->Left, x); // chen vao Node trai
        else if (compare(T->key, x) < 0)
            return insertNode(T->Right, x); // chen vao Node phai
    }
    T = (Node *)malloc(sizeof(Node));
    if (T == NULL)
        return 0;
    T->key = x;
    T->Left = T->Right = NULL;
    return 1;
}

void CreateTree(Tree &T)
{
    customer x;
    printf("Enter a customer \n: ");
    x = inputItem();
    int check = insertNode(T, x);
    if (check == -1)
        printf("Tree is exits!");
    else if (check == 0)
        printf("Memory full");
}

// Duyet theo LNR
void LNR(Tree T)
{
    if (T != NULL)
    {
        LNR(T->Left);
        outItem(T->key);
        LNR(T->Right);
    }
}

Node *searchMoney(Tree T, int money)
{
    if (T != NULL)
    {
        if (T->key.money < money)
        {
            Node *P = T;
            return P;
        }
        if (T->key.money >= money)
        {
            Node *node = searchMoney(T->Left, money);
            if (node != NULL)
                return node;
            else
            {
                return searchMoney(T->Right, money);
            }
        }
    }
    return NULL;
}

int delKey(Tree &T, customer x) // xoa nut co key x
{
    if (T == NULL)
        return 0;
    else if (compare(T->key, x) > 0)
        return delKey(T->Left, x);
    else if (compare(T->key, x) < 0)
        return delKey(T->Right, x);
    else // T->key == x
    {
        Node *P = T;
        if (T->Left == NULL)
            T = T->Right;
        else if (T->Right == NULL)
            T = T->Left;
        else
        {
            Node *S = T, *Q = S->Left;
            while (Q->Right != NULL)
            {
                S = Q;
                Q = Q->Right;
            }
            P->key = Q->key;
            S->Right = Q->Left;
            delete Q;
        }
    }
    return 1;
}

// ====================== End Manage Customer ============================

int main()
{
    //  Init data
    LIST_SHOSE dsShose;
    LIST_BRAND dsBrand;
    Tree T;
    T = NULL;

    int n;
    int status;

    printf("\n==================================================================\n");
    printf("\n||                    QUAN LY CUA HANG BAN GIAY                  ||\n");
    printf("\n==================================================================\n");
    printf("\n|| SINH VIEN THUC HIEN DE TAI\n");
    printf("\n|| Nguyen Huy Hoang MSSV 20139031\n");
    printf("\n|| Vo Van Linh MSSV 20139080\n");
    printf("\n|| Mai Huynh Tuan Vu MSSV 20139031\n");
    printf("\n==================================================================\n");

    printf("\n");

    while (true)
    {

        printf("1 -> Product: Enter data\n");
        printf("2 -> Product: Find\n");
        printf("3 -> Product: Print Data\n");
        printf("4 -> Brand\n");
        printf("5 -> Customer: Enter data\n");
        printf("6 -> Customer: Print data\n");
        printf("7 -> Customer: Delete data\n");
        printf("0 -> Out program\n");
        scanf("%d", &status);
        if (status == 1)
        {

            printf("Enter N: ");
            scanf("%d", &n);
            initShose(dsShose);
            enterShose(dsShose, n);

            printf("\n======== DANH SACH GIAY THEO BRAND ========\n");
            printBrand(dsShose);
            printf("\n======== DANH SACH GIAY SAP XEP THEO MA ========\n");
            sortShose(dsShose);
        }
        else if (status == 2)
        {
            if (checkNULL(dsShose) == 0)
            {
                printf("\n======== DANH SACH GIAY ========\n");
                Print_Shose(dsShose);
            }
            else
            {
                printf("Please Enter data\n");
            }
        }
        else if (status == 3)
        {
            if (checkNULL(dsShose) == 0)
            {
                printf("\n ======== DANH SACH GIAY THEO BRAND ========\n");
                printBrand(dsShose);
            }
            else
            {
                printf("Please Enter data\n");
            }
        }
        else if (status == 4)
        {
            printf("======================== Brand ========================\n");
            shose2brand(dsBrand, dsShose);
            //Print_Brand(dsBrand);
        }
        else if (status == 5)
        {
            printf("======================== Customer ======================\n");
            printf("Enter N: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                CreateTree(T);
                customer x;
                if (insertNode(T, x) == -1)
                {
                    printf("add failt!");
                }
                else
                {
                    printf("add success:\n");
                    printf("\n");
                }
            }
        }
        else if (status == 6)
        {
            printf("DANH SACH KHACH HANG\n");
            LNR(T);
            printf("\n");
        }

        else if (status == 7)
        {
            double money;
            printf("Nhap so tien, khach hang se bi xoa neu so tien da mua o cua hang nho hon so tien nhap: ");
            scanf("%lf", &money);
            int del = 1;
            while (del)
            {
                Node *node = searchMoney(T, money);
                if (node != NULL)
                {
                    printf("del");
                    del = delKey(T, node->key);
                }
                else
                {
                    printf("null");
                    del = 0;
                }
            }
        }

        else
        {
            break;
        }
    }
}