#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void bubblesort(int a[],int n){
    int i,j,t;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1])
            swap(&a[j+1],&a[j]);
        }
    }
}
void insertionsort(int a[],int n){
    int i,j,x;
    for(i=1;i<n;i++){
        j=i-1;
        x=a[i];
        while(j>-1&&a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}
void selectionsort(int a[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(a[j]<a[k])
            k=j;
        }
        swap(&a[i],&a[k]);
    }
}
int partition(int a[],int l,int h){
    int i=l,j=h,pivot=a[l];
    do{
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)
        swap(&a[i],&a[j]);
    }while(i<j);
    swap(&a[l],&a[j]);
    return j;
}
void quicksort(int a[],int l,int h){
    int j;
    if(l<h){
        j=partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
}
void merge(int a[],int l,int mid,int h){
    int i=l,j=mid+1,k=l,b[100];
    while(i<=mid&&j<=h){
        if(a[i]<a[j]){
        b[k++]=a[i++];
        }
        else{
        b[k++]=a[j++];
        }
    }
    for(;j<=h;j++){
        b[k++]=a[j];
    }
    for(;i<=mid;i++){
        b[k++]=a[i];
    }   
    for(int i=l;i<=h;i++){
            a[i]=b[i];
    }
}
void imergesort(int a[],int n){
    int i,l,h,mid,p;
    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(a,l,mid,h);
        }
        if((p/2)<n){
            merge(a,0,(p/2)-1,n);
        }
    }
}
void rmergesort(int a[],int l,int h){
    int mid;
    if(l<h){
        mid=((l+h)/2);
        rmergesort(a,l,mid);
        rmergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
int main()
{
     int a[]={33,433,221,10};
     bubblesort(a,4);
     for(int i=0;i<4;i++){
         cout<<a[i]<<endl;
     }
    cout<<endl;
     int b[]={33,433,221,10};
     insertionsort(b,4);
     for(int i=0;i<4;i++){
         cout<<b[i]<<endl;
     } 
    cout<<endl;
     int c[]={33,433,221,10};
     selectionsort(c,4);
     for(int i=0;i<4;i++){
         cout<<c[i]<<endl;
     } 
    cout<<endl;
     int d[]={33,433,221,10,278733993};
     quicksort(d,0,4);
     for(int i=0;i<4;i++){
         cout<<d[i]<<endl;
     } 
     cout<<endl;
     int e[]={32,433,221,10};
     imergesort(e,4);
     for(int i=0;i<4;i++){
         cout<<e[i]<<endl;
     }
     cout<<endl; 
     int f[]={32,433,221,10};
     rmergesort(f,0,3);
     for(int i=0;i<4;i++){
         cout<<f[i]<<endl;
     } 
     return 0;
}