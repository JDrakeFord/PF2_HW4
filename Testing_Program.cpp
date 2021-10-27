/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Created on October 1, 2010, 11:04 AM
 * Modified on January 18, 2016
 * MOdified October 2021
 *
 * Please note: the definition of capacity in c++ string
 * and ours is different. Ours is always one more than that of c++ string
 * as ours includes the terminating null character and theirs is the number
 * of characters can be stored.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Mystring.h"

// comment out to use string class, now use Mystring class
//#define string Mystring


using namespace std;

/*
 * Check function from the previous lab.
 */
void check (const string s, const string name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}

/*
 * Check-obj function is similar to check, except we will check the object
 * instead of the copy of the object built by the copy constructor.
 */
void check_obj (const Mystring& s, const Mystring name)
{
    cout << "checking " << name << " the object" << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}





int main()
{
    bool exit = false;
    char input;
    string stringInput;
    int intInput;
    do{
        cout << "______________________________HOMEWORK 4 TESTING PROGRAM______________________________\n"
                "______________________________________________________________________________________\n"
                "MENU - Enter the number corresponding to what you want to test (Or e for exit)\n"
                "1. Reserve function\n"
                "2. Append (If test passes, both += operator and append function work, assuming += calls append)\n"
                "3. Insert function\n"
                "4. Replace function\n"
                "5. Equivalent test (== operator)\n"
                "6. Nonequivalent test (!= operator)\n"
                "7. Concatenation GLOBAL operator (+, not +=)\n"
                "8. Array notation operator ([])\n"
                "9. Assignment Operator\n"
                "e. Exit\n"
                "______________________________________________________________________________________\n";
        cin >> input;
        switch(input){
            case '1':
            {
                cout << "What string would you like to test?" << endl;
                cin >> stringInput;
                Mystring s1(stringInput.c_str());
                check_obj(s1, "s1");
                cout << "How much space would you like to reserve?" << endl;
                cin >> intInput;
                s1.reserve(intInput);
                check_obj(s1, "s1"); break;
            }
            case '2':
            {
                cout << "What would you like to use as your primary string? (Please do not use any spaces)" << endl;
                cin >> stringInput;
                Mystring s1(stringInput.c_str());
                check_obj(s1, "s1");
                cout << "What would you like to concatenate to it?" << endl;
                cin >> stringInput;
                Mystring s2(stringInput.c_str());
                s1 += s2;
                check_obj(s1, "s1"); break;
            }
            case '3':
            {
                cout << "What would you like to use as your primary string? (Please do not use any spaces)" << endl;
                cin >> stringInput;
                Mystring s1(stringInput.c_str());
                check_obj(s1, "s1");
                cout << "What would you like to insert into it?" << endl;
                cin >> stringInput;
                Mystring s2(stringInput.c_str());
                cout << "What position would you like to insert " << s2 << " into " << s1 << "?" << endl;
                cin >> intInput;
                s1.insert(intInput, s2);
                check_obj(s1, "s1"); break;
            }
            case '4':
            {
                cout << "What would you like to use as your primary string? (Please do not use any spaces)" << endl;
                cin >> stringInput;
                Mystring s1(stringInput.c_str());
                check_obj(s1, "s1");
                cout << "What would you like to replace a section of that with?" << endl;
                cin >> stringInput;
                Mystring s2(stringInput.c_str());
                cout << "At what position would you like to start replacing " << s1 << " with " << s2 << "?" << endl;
                int start;
                cin >> start;
                cout << "What would you like the span variable to be? (How much of your second string to replace into s1)" << endl;
                int span;
                cin >> span;
                s1.replace(start, span, s2);
                check_obj(s1, "s1"); break;
            }
            case '5':
            {
                cout << "What would you like the first string to be? (Please do not use any spaces)" << endl;
                cin >> stringInput;
                Mystring s1(stringInput.c_str());
                check_obj(s1, "s1");
                cout << "What would you like the second string to be? (Please do not use any spaces)" << endl;
                cin >> stringInput;
                Mystring s2(stringInput.c_str());
                check_obj(s2, "s2");
                if(s1 == s2)
                    cout << "They are equal!" << endl;
                else
                    cout << "They are NOT equal!" << endl; break;
            }
            case '6':
            {
                cout << "What would you like the first string to be? (Please do not use any spaces)" << endl;
                cin >> stringInput;
                Mystring s1(stringInput.c_str());
                check_obj(s1, "s1");
                cout << "What would you like the second string to be? (Please do not use any spaces)" << endl;
                cin >> stringInput;
                Mystring s2(stringInput.c_str());
                check_obj(s2, "s2");
                if(s1 != s2)
                    cout << "They are NOT equal!" << endl;
                else
                    cout << "They are equal!" << endl; break;
            }
            case '7':
            {
                cout << "What would you like the first string to be? (Please do not use any spaces)" << endl;
                cin >> stringInput;
                Mystring s1(stringInput.c_str());
                check_obj(s1, "s1");
                cout << "What would you like the second string to be? (Please do not use any spaces)" << endl;
                cin >> stringInput;
                Mystring s2(stringInput.c_str());
                check_obj(s2, "s2");
                Mystring s3 = s1 + s2;
                check_obj(s3, "s3"); break;
            }
            case '8':
            {
                cout << "What string would you like to test?" << endl;
                cin >> stringInput;
                Mystring s1(stringInput.c_str());
                check_obj(s1, "s1");
                cout << "What index would you like to use to test []?" << endl;
                cin >> intInput;
                cout << "s1[" << intInput << "] is " << s1[intInput] << endl; break;
            }
            case '9':
            {
                cout << "What would you like your first string to be? (Please no spaces)" << endl;
                cin >> stringInput;
                Mystring s1(stringInput.c_str());
                check_obj(s1, "s1");
                cout << "What would you like the second string to be? (Please no spaes)" << endl;
                cin >> stringInput;
                Mystring s2(stringInput.c_str());
                check_obj(s2, "s2");
                cout << "s1 will now be assigned s2 (s1 = s2)" << endl;
                s1 = s2;
                check_obj(s1, "s1"); break;
            }
            case 'e':
                exit = true; break;

        }
        if(!exit){
            cout << "Press any key and hit enter to print menu again" << endl;
            cin >> input; }
    } while(!exit);
}