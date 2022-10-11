// 
#include <iostream>
#include <string> 
using namespace std; 
int score_count(string &str)
{ 
    int digit = 0, symbol = 0;
    int lower = 0, upper = 0, charc = 0; 
    int size = 0, sum = 0; 
    for (auto ch : str)
    { 
        if (ch >= 'a' && ch <= 'z')
        { 
            lower++;
            charc++;  
        }else if (ch >= 'A' && ch <= 'Z')
        { upper++;
         charc++; }
        else if (ch >= '0' && ch <= '9') 
        {
            digit++; 
        }else if ((ch >= 0x21 && ch <= 0x2F) || (ch >= 0x3A && ch <= 0x40) || (ch >= 0x5B && ch <= 0x60) || (ch >= 0x7B && ch <= 0x7E))
        { 
            symbol++;
        } 
    }
    size = str.size();
    if (size <= 4) sum += 5; 
    else if (size <= 7)
        sum += 10; 
     else
         sum += 25;
    if (lower > 0 && upper > 0) 
        sum += 20; 
    else if (lower == charc || upper == charc) 
        sum += 10; 
    if (digit == 1) sum += 10;
    else if (digit > 1) sum += 20;
    if (symbol == 1) sum += 10; 
    else if (symbol > 1) sum += 25;
    if (lower > 0 && upper > 0 && digit > 0 && symbol > 0) sum += 5; 
    else if ((lower > 0 || upper > 0) && digit > 0 && symbol > 0) 
        sum += 3; 
    else if ((lower > 0 || upper > 0) && digit > 0 && symbol == 0) 
        sum += 2; 
    return sum; 
}
int main() {
    string str;
    while(cin >> str) 
    { 
        int score = score_count(str); 
     if (score >= 90) {
     cout << "VERY_SECURE" << endl; }
        else if (score >= 80)
    {
     cout << "SECURE" << endl;

   }
        else if (score >= 70)
        {
     cout << "VERY_STRONG" << endl; 
        }
        else if (score >= 60)
        {
     cout << "STRONG" << endl;
        }
        else if (score >= 50)
        {
      cout << "AVERAGE" << endl; 
        }
        else if (score >= 25)
        {
     cout << "WEAK" << endl;
        }
        else
      {
     cout << "VERY_WEAK" << endl;
        } 
    }return 0;
}
