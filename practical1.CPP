#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

// Bubble Sort
void bubble(vector<int>& a){
    for(int i=0;i<a.size()-1;i++)
        for(int j=0;j<a.size()-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
}

// Selection Sort
void selection(vector<int>& a){
    for(int i=0;i<a.size()-1;i++){
        int m=i;
        for(int j=i+1;j<a.size();j++)
            if(a[j]<a[m]) m=j;
        swap(a[i],a[m]);
    }
}

// Insertion Sort
void insertion(vector<int>& a){
    for(int i=1;i<a.size();i++){
        int key=a[i],j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

// Merge Sort
void merge(vector<int>& a,int l,int m,int r){
    vector<int> L(a.begin()+l,a.begin()+m+1),R(a.begin()+m+1,a.begin()+r+1);
    int i=0,j=0,k=l;
    while(i<L.size()&&j<R.size()) a[k++]=(L[i]<R[j])?L[i++]:R[j++];
    while(i<L.size()) a[k++]=L[i++];
    while(j<R.size()) a[k++]=R[j++];
}
void mergeSort(vector<int>& a,int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

// Quick Sort
int part(vector<int>& a,int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)
        if(a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[h]);
    return i+1;
}
void quick(vector<int>& a,int l,int h){
    if(l<h){
        int p=part(a,l,h);
        quick(a,l,p-1);
        quick(a,p+1,h);
    }
}

int main(){
    const int n=100;
    vector<int> a(n),b;
    srand(time(0));

    for(int &x:a) x=rand()%1000;

    auto test=[&](string name, auto sortFun){
        b=a;
        auto s=high_resolution_clock::now();
        sortFun(b);
        auto e=high_resolution_clock::now();
        cout<<name<<" : "
            <<duration_cast<microseconds>(e-s).count()
            <<" us\n";
    };

    test("Bubble",[](vector<int>& x){bubble(x);});
    test("Selection",[](vector<int>& x){selection(x);});
    test("Insertion",[](vector<int>& x){insertion(x);});
    test("Merge",[](vector<int>& x){mergeSort(x,0,x.size()-1);});
    test("Quick",[](vector<int>& x){quick(x,0,x.size()-1);});

    return 0;
}