#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
        //cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> vec1;
    int n;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter an element to add to this vector: ";
        cin>>n;
        vec1.push_back(n);
    }
    //vec1.pop_back();
    display(vec1);
    vector<int> :: iterator iter = vec1.begin();
    //vec1.insert(iter+1,2, 32); 
    display(vec1);
    
    return 0;
}