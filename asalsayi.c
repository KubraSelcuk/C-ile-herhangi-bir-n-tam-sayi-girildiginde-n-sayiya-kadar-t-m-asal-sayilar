#include<stdio.h>
#include<stdlib.h>

int checkPrime(int n);

typedef struct _node{
    int data;
    struct _node* next;
}node;

node* make(int sayi)
{
    node* eklenecek = (node*)malloc(sizeof(node));
    eklenecek->next = NULL;
    eklenecek->data = sayi;
    return eklenecek;
}
void sonaEkle(node**root, int sayi)
{
    node* iter = *root;
    while(iter->next != NULL)
    {
        iter = iter->next;
    }
    node* eklenecek = make(sayi);
    iter->next = eklenecek;
}

void bastir(node* root)
{
    node* iter = root;
    while(iter->next != NULL)
    {
        printf("%d\n", iter->data);
        iter = iter->next;
    }
}

int main() 
{
    int i,n;
        node* root = NULL;
        int flag = 0;
    printf("N tam sayi degerini girin: ");
    scanf("%d",&n);

    printf("%d tam sayisina kadar olan asal sayilar\n",n);  // 1 ve kendisinden basþa tam böleni olmadýðý için direkt 1 den baþlamak istedim
    for(i=1;i<=n;i++)
    {
        if(checkPrime(i))
            {
                 if(flag == 0){
                   root = make(i);
                 }
                  else{
                    sonaEkle(&root, i);
                      }
                    flag = 1;
            }
    }
    bastir(root);
    return 0;
}

int checkPrime(int n){
    int j, sayi = 1;
    for (j = 2; j <= n / 2; ++j) {
        if (n % j == 0){
            sayi = 0;
            break;
        }
    }
    return sayi;
}





