#include<iostream>
#include<string>
#include<vector>

using namespace std;

int ids[] = {99,12,48,105,10,15,25,46,499,128,87,52,221,300,714,188,189,910,412,555};
char genders[] = {'m','f','m','m','f','f','f','m','m','f','m','f','f','m','f','f','f','m','m','f'};
string faculty[] = {"eng","med","econ","med","eng","law","law","dent","med","camt","med","dent","econ","eng","med","eng","eng","econ","econ","agri"};
int N = sizeof(ids)/sizeof(ids[0]);


int main(){
    string text;
    string G;
    string fac;
    cout << "Input gender and faculty to search:\n";
    // getline(cin, text);
    // char format[] = "%s %s";
    // sscanf(text.c_str(), format, G, fac);
    cin >> G;
    cin >> fac;
    
    vector<int> number;
    // cout << G << endl;
    // cout << fac;

    for(int i = 0; i < N; i++){
        if (G[0] == genders[i] && fac == faculty[i]){
            number.push_back(i);
        }
    }
    int index = number.size();
    for (int i = 0; i < index; i++){
        cout << "Student " << i+1 << ": " << ids[number[i]] << endl;
        // cout << genders[number[i]] << endl;
        // cout << faculty[number[i]] << endl;
    }
    if (index == 0) cout << "not found";
    // cout << number.size();

    return 0;
}
