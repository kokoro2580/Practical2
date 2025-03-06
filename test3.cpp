#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card {
public:
    string suit, face;
    int fnum, snum;
    static string s[4], f[13];

    Card(string);
    bool operator>(const Card &);
    static Card findTheStrongestCard(const vector<Card> &);
};

// กำหนดค่าลำดับของ suit และ face
string Card::s[4] = {"SPADE", "HEART", "DIAMOND", "CLUB"};
string Card::f[13] = {"2", "A", "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3"};

Card::Card(string text) {
    for (char &c : text) c = toupper(c);  // แปลงเป็นตัวพิมพ์ใหญ่ทั้งหมด

    char face_c[10], suit_c[10];
    if (sscanf(text.c_str(), "%s %s", suit_c, face_c) != 2) {
        throw invalid_argument("Invalid card format");
    }

    suit = string(suit_c);
    face = string(face_c);

    for (int i = 0; i < 4; i++) {
        if (suit == s[i]) {
            snum = 4 - i;  // กำหนดให้ SPADE มีค่ามากสุด
        }
    }
    for (int i = 0; i < 13; i++) {
        if (face == f[i]) {
            fnum = 13 - i;  // กำหนดให้ '2' มีค่ามากสุด
        }
    }
}

// เปรียบเทียบไพ่ 2 ใบ ว่าไพ่ใบไหนแข็งแกร่งกว่า
bool Card::operator>(const Card &c) {
    if (fnum > c.fnum) return true;
    if (fnum == c.fnum && snum > c.snum) return true;
    return false;
}

// ค้นหาไพ่ที่แข็งแกร่งที่สุดโดยใช้ Insertion Sort
Card Card::findTheStrongestCard(const vector<Card> &c) {
    vector<Card> temp = c;  // คัดลอก vector เพื่อไม่ให้แก้ไขต้นฉบับ
    int index = temp.size();

    for (int i = 1; i < index; i++) {
        Card v = temp[i];
        int j = i - 1;

        while (j >= 0 && temp[j] > v) {  // ใช้ operator> ในการเปรียบเทียบ
            temp[j + 1] = temp[j];
            j--;
        }
        temp[j + 1] = v;
    }

    return temp[0];  // คืนค่าตัวที่แข็งแกร่งที่สุด
}

// ฟังก์ชัน findTheStrongestCard นอกคลาส
Card findTheStrongestCard(vector<Card> &c) {
    return Card::findTheStrongestCard(c);
}

int main() {
    vector<Card> hands;
    hands.push_back(Card("Heart Q"));
    hands.push_back(Card("Spade Q"));
    hands.push_back(Card("Spade 10"));

    Card strongest = findTheStrongestCard(hands);
    cout << strongest.suit << " " << strongest.face << endl;

    return 0;
}
