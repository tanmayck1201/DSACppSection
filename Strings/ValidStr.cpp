#include<iostream>
using namespace std;
 
bool Valid(char *name){
    for (int i = 0; name[i] != '\0'; i++) //changes in condition
    {
        if (!(name[i] >= 65 && name[i] <= 90) 
        && !(name[i] >= 97 && name[i] <= 122) 
        && !(name[i] >= 48 && name[i] <= 57))
            return false;        
    }
    return true;
}
 
 
int main()
{
    char *name[20]; //changes
    cout<<"Enter the string: ";
    cin.get(*name, 20); //changes
 
    if(Valid(*name) == true)
        cout<<"The String is Valid!";
    else
        cout<<"The string is not valid!";    
 
    return 0;
} 