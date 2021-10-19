/*
Author: Casey Roosma
caesar cipher
*/

#include <iostream>
#include <cctype>
using namespace std;
// A helper function to shift one character by rshift
char shiftChar(char c, int rshift);
// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift);

char shiftChar(char c, int rshift)
{
    int charnum = (int)c;
    int y;
    int x;
    //check if alpha, if alpha shift
    //if not return c not modify
    if(isalpha(c))
    {
        //if uppercase or lowercase
        //current char c is uppercase if 65 - 90
        if(charnum >= 65 && charnum <= 90)
        {
            x = (charnum - 65) + rshift;
            y = x % 26;
            charnum = 65 + y;
            c = char(charnum);
        }
        //if lowercase
        if(charnum >= 97 && charnum <= 122)
        {
            x = (charnum - 97) + rshift;
            y = x % 26;
            charnum = 97 + y;
            c = char(charnum);
        }
    }

    return c;
}

string encryptCaesar(string plaintext, int rshift)
{
    string cipher;
    int size = plaintext.length();
    for(int i = 0; i < size; i ++)
    {
        cipher += shiftChar(plaintext[i], rshift);
        
    }
    return cipher;
}

int main()
{
    string word;
    int shift;
    cout << "Enter plaintext: " << endl;
    getline(cin, word);
    cout << "Enter shift: " << endl;
    cin >> shift;
    
    cout << "Ciphertext: " << encryptCaesar(word, shift) << endl;
}
