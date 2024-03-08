#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

void sort3ints(int *a, int *b, int *c){
	int j;
    int temp;
    int temp1[] = {*a, *b, *c};
	for( int i = 1; i < 3; i++)
	{
        temp = temp1[i];
		j = i - 1;
		// cout << "Pass " << i << ":";
		while(j >= 0 && temp1[j] < temp)
		{
			temp1[j + 1] = temp1[j];
            j--;
		}
		temp1[j + 1] = temp;
		// for (int i = 0; i < 3; i++) cout << temp1[i] << " ";
		//cout << endl;
	}
    *a = temp1[0];
    *b = temp1[1];
    *c = temp1[2];
}

int main(){
    int a = 5, b = 2, c = 3;
    sort3ints(&a,&b,&c);
    printf("%d %d %d",a,b,c);
}