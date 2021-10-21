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

// copy constructor to be implemented
Mystring::Mystring(const Mystring& orig) {
    len = orig.length();
    buf_size = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, orig.ptr_buffer);
}

void Mystring::reserve(size_type n) {
    buf_size = n;
}

bool Mystring::empty() const {
    if(len == 0)
        return true;
    else
        return false;
}

void Mystring::clear() {
    len = 0;
    *ptr_buffer = '\0';
}

void Mystring::push_back(char c) {
    char *iterate;
    while(*iterate != '\0')
        iterate++;
    *iterate = c;
    iterate++;
    *iterate = '\0';
}

Mystring & Mystring::append(const Mystring &str, size_type subpos, size_type sublen) {
    for(int i = subpos; i < sublen; i++)
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
/*Mystring& Mystring::operator=(const Mystring& orig)
{
}*/

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