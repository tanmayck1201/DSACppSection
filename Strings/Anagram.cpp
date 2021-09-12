#include<iostream>
using namespace std;

void Anagram(int H[], string str1, string str2){
    int i;
    // Traverse 1st str & mark it into array(by incr. to 1)
    for (i = 0; str1[i] != '\0'; i++)
    {
        H[str1[i] - 97] += 1;
    }
    
    // Traverse 2nd array & decr. it if same letters are found by 1.
    for (i = 0; str2[i] != '\0'; i++)
    {
        H[str2[i] - 97] -= 1;
        
        // if same letter is not present it will do it -1 means not anagram.
        if (H[str2[i] - 97] < 0){
            cout<<"Not Anagram!";
            break;
        }
    }
    
    // if whole str. is traversed succ.' means it's anagram!
    if (str2[i] == '\0'){
        cout<<"It's Anagram!"; 
    }

}


int main()
{
    string str1, str2;
    int H[26] = {0};

    cout<<"Enter the string 1: ";
    getline(cin, str1);
    cout<<"Enter the string 2: ";
    getline(cin, str2);

    Anagram(H, str1, str2);

    return 0;
}