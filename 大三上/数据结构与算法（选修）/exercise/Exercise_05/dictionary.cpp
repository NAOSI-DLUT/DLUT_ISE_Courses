#include "dictionary.h"

#include <istream>
#include <sstream>

using namespace std;

unsigned int hash_function::operator()(const string &s) const
{
    unsigned int h = 0;
    const char *pStr = s.c_str();
    for (; *pStr; ++pStr)
        h = prime_list[0] * h + *pStr;
    return h;
}

bool equality::operator()(const string &A, const string &B) const
{
    return  (A == B);
}