//  ทำ findStrongestcard ไม่ได้

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Card{
    int j = 0;
    public:
            Card(string);
            string t;
            char face[3], suit[8];
            int fnum, snum;
            string s[4]  = {"SPADE", "HEART", "DIAMOND", "CLUB"};
            string f[13] = {"2", "A", "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3"};
            bool operator>(const Card &);
            Card findTheStrongestCard(const vector<Card> &);
};

Card::Card(string text){
    int i = 0;
    t = text;
    while(text[i]){
        text[i] = toupper(text[i]);
        i++;
    }
    char format[] = "%s %s";
    sscanf(text.c_str(), format, &suit, &face);
    for(int i = 0; i < 4; i++){
        if (suit == s[i]) snum = 4-i;
    }
    for(int i = 0; i < 13; i++){
        if (face == f[i]) fnum = 13-i;
    }
}

bool Card::operator>(const Card &c){
    if(c.fnum < fnum) return true;
    if (c.fnum == fnum){
        if (c.snum < snum) return true;
    }
    return false;
}

bool operator>(const char x, const Card &c){
    if(x > c) return true;
    return false;
}

Card Card::findTheStrongestCard(const vector<Card> &c){
    int index = c.size();

    Card temp(t);
    vector<Card> temp1 = c;
	for( int i = 1; i < index; i++)
	{
        Card v = temp1[i];
		j = i - 1;
		// cout << "Pass " << i << ":";
		while(j >= 0 && temp1[j] < v)
		{
			temp1[j + 1] = temp1[j];
            j--;
		}
		temp1[j + 1] = v;
		// for (int i = 0; i < 3; i++) cout << temp1[i] << " ";
		//cout << endl;
	}


    return temp1[0];
}

Card findTheStrongestCard(vector<Card> &c){
    return c[0];
}

int main(){
    vector<Card> hands;
    hands.push_back(Card("Heart Q"));
    hands.push_back(Card("Spade Q"));
    hands.push_back(Card("Spade 10"));
    Card x = findTheStrongestCard(hands);
    cout << x.face << "\n" << x.suit;

}