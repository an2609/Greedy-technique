///////////////////////////////////////////////////////////////////////////////////////////////////////
//                                           HUFFMAN CODING                                          //
//                                          BY:-ANKUR SINGLA                                         //
//                                            NIT JALANDHAR                                          //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
int finaltree[260];
int top=0,top1=0,topper=0;
int arr[1000];
struct tree
{
    int i;
    struct tree *left,*right;
    int weight;
    int weight_length;
}*tem,*n1,*n2,*n3;
struct node
{
    int a,b;
    struct tree *p;
} ab[260];
void print(tree *root,int arr[],int topper)
{
    if(root->left!=NULL)
    {
        arr[topper]=0;
        print(root->left,arr,topper+1);
    }
    if(root->right!=NULL)
    {
        arr[topper]=1;
        print(root->right,arr,topper+1);
    }
    if(root->left==NULL)
    {
        printf("%c ",root->i);
        for(int i=0; i<topper; i++)
        {
            printf("%d",arr[i]);
        }
        printf("\n");
        finaltree[root->i]=topper;
    }
}
struct tree *stac[1000];
void inorder(struct tree *node)
{
    if(node==NULL) return;
    inorder(node->left);
    printf("%c ",node->i);
    inorder(node->right);
}
void swap(struct node *a,struct node *b)
{
    node temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(node ar[],int l,int n)
{
    int k=2*l;
    if(k+1<=n)
    {
        if((ar[k].a<ar[l].a)&&(ar[k].a<ar[k+1].a))
        {
            swap(&ar[k],&ar[l]);
            heapify(ar,k,n);
        }
        else if((ar[k+1].a<ar[l].a)&&(ar[k+1].a<=ar[k].a))
        {
            swap(&ar[k+1],&ar[l]);
            heapify(ar,k+1,n);
        }
    }
    else
    {
        if(k<=n&&ar[k].a<ar[l].a)
            swap(&ar[k],&ar[l]);
    }
}
void heap(node ar[],int n)
{
    for(int i=n/2; i>=1; i--)
    {
        heapify(ar,i,n);
    }
}
int has[260];
int k=1;
char ar[1000010];
int main()
{
    int counter=0;
    for(int i=0; i<260; i++)
    {
        has[i]=0;
        ab[i].p=NULL;
    }
    cout<<"Enter the string to be encoded\n";
    cin.getline(ar,1000000);
    for(int i=0; i<strlen(ar); i++)
    {
        has[ar[i]]++;
    }
    for(int i=0; i<260; i++)
    {
        if(has[i])
        {
            ab[k].a=has[i];
            ab[k++].b=i;
            counter++;
        }
    }
    k=k-1;
    heap(ab,k);
    for(int i=0; i<k-1; i++)
    {
        struct node temp=ab[1];
        if(ab[1].p==NULL)
        {
            n1=(struct tree *)malloc(sizeof(struct tree));
            n1->left=NULL;
            n1->right=NULL;
            n1->i=ab[1].b;
            n1->weight=0;
            n1->weight_length=0;
        }
        else
        {
            n1=ab[1].p;
        }
        ab[1]=ab[k-i];
        heapify(ab,1,k-i-1);

        if(ab[1].p==NULL)
        {
            n2=(struct tree *)malloc(sizeof(struct tree));
            n2->left=NULL;
            n2->right=NULL;
            n2->i=ab[1].b;
            n2->weight=0;
            n2->weight_length=0;
        }
        else
        {
            n2=ab[1].p;
        }
        node temp2=ab[1];
        n3=(struct tree *)malloc(sizeof(struct tree));
        n3->left=n1;
        n3->right=n2;
        n3->i=-1;
        temp.a+=temp2.a;
        ab[1]=temp;
        ab[1].p=n3;
        heapify(ab,1,k-i-1);
    }

    int bits=0;
    int fkd=ceil(log2(counter))*strlen(ar);
    int asc=strlen(ar)*8;
    cout<<"\nString length = "<<strlen(ar)<<endl;
    cout<<"Number of distinct characters in string = "<<counter<<endl;
    cout<<"Number of bits in fixed length code = "<<fkd/strlen(ar)<<endl;
    cout<<"If ASCII code is used then the number of bits used = "<<asc<<endl;
    cout<<"If Fixed length code is used then number of bits used = "<<fkd<<endl<<endl;
    cout<<"Huffman codes generated are\n\n";
    print(n3,arr,0);
    for(int i=0; i<260; i++)
    {
        if(has[i])
        {
            bits=bits+(finaltree[i]*has[i]);
        }
    }
    int sss=strlen(ar);
    cout<<"\nIf Huffman code is used then the number of bits used =";
    cout<<bits<<endl;
    double kk=fkd-bits;
    kk=kk/(double)fkd;
    kk*=100;
    cout<<"COMPRESSION RATIO w.r.t. Fixed length code = "<<kk<<"%"<<endl;
    kk=asc-bits;
    kk=kk/(double)asc;
    kk*=100;
    cout<<"COMPRESSION RATIO w.r.t. ASCII code = "<<kk<<"%"<<endl;
    double ansns=(double)bits/(double)sss;
    cout<<"AVERAGE NUMBER OF BITS FOR A MESSSAGE "<<ansns<<endl;
}
