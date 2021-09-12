#include<iostream>
#include<vector>
using namespace std;

template <class T>
void display(vector<T> &v){
    cout<<"Displaying Vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<char> vec1(4, 'a');
    vector<char> vec2(vec1);
    display(vec2);
    vector<float> vec3(4, 12.5);
    display(vec3);
    
    return 0;
}