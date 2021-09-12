#include<iostream>
using namespace std;

bool IsArrSorted(int Arr[],int index){
    if(index>=Arr.size()){
        return true;
    }

    if(Arr[index-1]>Arr[index]){
        return false;
    }

    return IsArrSorted(Arr,index+1);
}

int main()
{
    int Arr[] = {1,3,2,4,5};
    int a = IsArrSorted(Arr,1);
    if(a==true){
        cout<<"The array is sorted!";
    }
    else{
        cout<<"The array is not sorted!";
    }
    
    return 0;
}