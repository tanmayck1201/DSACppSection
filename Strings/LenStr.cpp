#include<iostream>
using namespace std;

void length_str(char str[]){
	int i;
	int count = 0;
	for(i=0;str[i]!='\0';i++){
		count++;
	}
	cout<<"The length of the string:"<<count;
}

int main(){
	char str[] = "Welcome";
	length_str(str);
}

