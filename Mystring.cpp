/*
 * File:   mystring.cpp
 * Author: wingning
 *
 * mystring class implementation:
 * methods whose implementations are provided:
 * default constructor
 * a constructor taking c-style string
 * the destructor
 * size, length, capacity, max_size
 * << operator for cout
 * c_str
 *
 * methods to be implemented:
 * a copy constructor
 * ...
 */

#include "Mystring.h"
#include <cstring>

// default constructor
Mystring::Mystring()
{
    ptr_buffer  = new char[1];
    *ptr_buffer = '\0';
    buf_size    = 1;
    len         = 0;
}

// constructor from c-style string or "abc"
Mystring::Mystring(const char * s)
{
    len        = strlen(s);
    buf_size   = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, s);
}

// TODO NOT TESTED
Mystring::Mystring(const Mystring& orig) {
    len = orig.length();
    buf_size = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, orig.ptr_buffer);
}

//TODO I DONT KNOW IF THIS IS RIGHT
void Mystring::reserve(size_type n) {
    if(n <= buf_size)
        return;
    else
    {
        char *del = ptr_buffer;
        ptr_buffer = new char[n];
        strcpy(ptr_buffer, del);
        delete del;
        buf_size = n;
    }
}

//TODO NOT FINISHED
bool Mystring::empty() const {
    if(len == 0)
        return true;
    else
        return false;
}

//TODO NOT FINISHED
void Mystring::clear() {
    len = 0;
    *ptr_buffer = '\0';
}

void Mystring::push_back(char c) {
    //reserve(len + 1);
    char *iterate = ptr_buffer;
    while(*iterate != '\0')
        iterate++;
    *iterate = c;
    iterate++;
    *iterate = '\0';
    len++;
}

Mystring & Mystring::append(const Mystring &str, size_type subpos, size_type sublen) {
    for(int i = subpos; i <= sublen; i++)
    {
        push_back(*(str.ptr_buffer + i));
    }
    return *this;
}

Mystring & Mystring::append(const char *str, size_type n) {
    for(int i = 0; i < n; i++)
    {
        push_back(*(str + i));
    }
    return *this;
}

Mystring &Mystring::insert(size_type pos, const char *str) {
    char *inserted = new char[len + strlen(str)];
    for(int i = 0; i < pos; i++)
    {
        inserted[i] = ptr_buffer[i];
    }
    for(int i = 0; str[i] != '\0'; i++)
    {
        inserted[i + pos] = str[i];
    }
    int k = pos;
    for(int i = (pos + strlen(str)); i < len + strlen(str); i++)
    {
        inserted[i] = ptr_buffer[k];
        k++;
    }
    ptr_buffer = inserted;
    len = strlen(inserted);
    buf_size = len + 1;
    return *this;
}

Mystring &Mystring::insert(size_type pos, const Mystring &str) {
    return insert(pos, str.c_str());
}

Mystring &Mystring::replace(size_type start, size_type span, const char *str) {
    for(int i = 0; i < span && str[i] != '\0'; i++)
    {
        ptr_buffer[i + start] = str[i];
    }
    return *this;
}

Mystring &Mystring::replace(size_type start, size_type span, const Mystring &str) {
    return replace(start, span, str.c_str());
}


Mystring::size_type Mystring::find_first_of(const char *s, size_type pos, size_type n) const {
    for(int i = 0; i <= n; i++)
    {
        for(int k = 0; s[k] != '\0'; k++)
        {
            if(ptr_buffer[i + pos] == s[k])
                return i + pos;
        }
    }
    return -1;
}

Mystring::size_type Mystring::find_last_not_of(const char *s, size_type pos) const {
    if(pos > len)
        pos = len - 1;
    for(int i = pos; i >= 0; i--)
    {
        bool charFound = false;
        for(int k = 0; s[k] != '\0'; k++)
        {
            if(ptr_buffer[i] == s[k])
            {
                charFound = true;
                break;
            }
        }
        if(!charFound)
            return i;
    }
    return -1;
}

Mystring & Mystring::operator+=(const Mystring &str) {
    append(str.c_str(), str.length());
}

Mystring & Mystring::operator+=(const char *str) {
    append(str, strlen(str));
    return *this;
}

char & Mystring::operator[](size_type pos) {
    return *(ptr_buffer + pos);
}

char Mystring::operator[](size_type pos) const {
    return *(ptr_buffer + pos);
}

// one of the over loaded assignment operator if you have time
Mystring& Mystring::operator=(const Mystring& orig)
{
    if(this != &orig)
    {
        delete[] ptr_buffer;
        ptr_buffer = new char[buf_size];
        len = orig.len;
        buf_size = orig.buf_size;
        strcpy(ptr_buffer, orig.ptr_buffer);
    }
    return *this;
}


Mystring &Mystring::operator=(const char *str) {
    return operator=(*new Mystring(str));
}

// some simple methods implemented for you
Mystring::size_type Mystring::size() const
{
    return len;
}

Mystring::size_type Mystring::length() const
{
    return len;
}

Mystring::size_type Mystring::capacity() const
{
    return buf_size;
}

Mystring::size_type Mystring::max_size() const
{
    return (int)pow(2,30) -4 ;
}

// Destructor
Mystring::~Mystring()
{
    delete [] ptr_buffer;
}

// Provided for the lab so we may cout mystring
ostream& operator<<(ostream& out, const Mystring& str)
{
    out << str.c_str();
    return out;
}

// implemented for the lab to support the implementation of <<
const char * Mystring::c_str() const
{
    return ptr_buffer;
}