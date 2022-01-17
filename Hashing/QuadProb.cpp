// Hashing pgm of closed hashing->Quadratic Probing
// [Only 1/2 of space can be filled as λ<=0.5 (Analysis phase)]
#include <iostream>
#define SIZE 10
using namespace std;

// hash function
int hashfn(int key)
{
    return key % SIZE;
}

// logic of Quadratic probing
int probe(int H[], int key)
{
    int index = hashfn(key);
    int i = 0;
    // find next empty space quadratically.
    while (H[(index + (i * i)) % SIZE] != 0)
    {
        i++;
    }
    return (index + (i * i)) % SIZE;
}

void Insert(int H[], int key)
{
    int index = hashfn(key);
    // if no free space at given index then go for qp.
    if (H[index] != 0)
    {
        index = probe(H, key);
    }
    H[index] = key;
}

int Search(int H[], int key)
{
    int index = hashfn(key);
    int i = 0;
    // Stop if key or any free space is found!
    while (H[(index + i) % SIZE] != 0 && H[(index + (i * i)) % SIZE] != key)
    {
        i++;
    }
    // free space found means unsuccesful search.
    if (H[(index + (i * i)) % SIZE] == 0)
    {
        return -1;
    }
    // return index of key found/required!
    return (index + (i * i)) % SIZE;
}

int main()
{
    int HT[10] = {0}, n = 5, m;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        Insert(HT, m);
    }

    cout << "Enter the element to search: ";
    cin >> m;
    cout << "Element is found at position: " << Search(HT, m);

    return 0;
}
