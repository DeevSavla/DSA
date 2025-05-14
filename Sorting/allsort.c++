// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void bubblesort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionsort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int smallest = arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]<smallest){
                smallest = arr[j];
            }
        }
        swap(arr[i],smallest);
    }
}

void insertionsort(vector<int>& arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void print(vector<int> arr){
    for(int num:arr){
        cout<<num<<" ";
    }
}

void merge(vector<int>& arr,int start,int mid,int end){
    vector<int> sort;
    int i = start;
    int j = mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            sort.push_back(arr[i++]);
        } else {
            sort.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        sort.push_back(arr[i++]);
    }
    while(j<=end){
        sort.push_back(arr[j++]);
    }
    for(int k = 0; k < sort.size(); k++) {
        arr[start + k] = sort[k];
    }
}

void mergesort(vector<int>& arr,int start,int end){
    if(start >= end) return;
    int mid = start + (end-start)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main() {
    vector<int> arr = {3,1,2,9,6,7};
    //bubblesort(arr);
    //selectionsort(arr);
    //insertionsort(arr);
    mergesort(arr,0,arr.size()-1);
    print(arr);
    return 0;
}
