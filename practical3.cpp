#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

void heapify(vector<int>& a, int n, int i, bool isMax) {
    int l=2*i+1, r=2*i+2, idx=i;
    if(l<n && (isMax ? a[l]>a[idx] : a[l]<a[idx])) idx=l;
    if(r<n && (isMax ? a[r]>a[idx] : a[r]<a[idx])) idx=r;
    if(idx!=i){ swap(a[i],a[idx]); heapify(a,n,idx,isMax); }
}

void heapSort(vector<int>& a, bool isMax) {
    int n=a.size();
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i,isMax);
    for(int i=n-1;i>0;i--){ swap(a[0],a[i]); heapify(a,i,0,isMax); }
    if(!isMax) reverse(a.begin(),a.end());
}

void showTime(string name, high_resolution_clock::time_point s, high_resolution_clock::time_point e){
    cout<<"\n==== "<<name<<" ====\n";
    cout<<"Nanoseconds  : "<<duration_cast<nanoseconds>(e-s).count()<<" ns\n";
    cout<<"Microseconds : "<<duration_cast<microseconds>(e-s).count()<<" us\n";
    cout<<"Milliseconds : "<<duration_cast<milliseconds>(e-s).count()<<" ms\n";
    cout<<"Seconds      : "<<duration<double>(e-s).count()<<" s\n";
}

int main(){
    int n; cout<<"Enter size: "; cin>>n;
    vector<int> arr(n); srand(time(0));
    for(int& x:arr) x=rand()%100000;

    auto a1=arr,a2=arr;
    auto s1=high_resolution_clock::now(); heapSort(a1,true);
    auto e1=high_resolution_clock::now();
    auto s2=high_resolution_clock::now(); heapSort(a2,false);
    auto e2=high_resolution_clock::now();

    showTime("MAX HEAP SORT",s1,e1);
    showTime("MIN HEAP SORT",s2,e2);
}
