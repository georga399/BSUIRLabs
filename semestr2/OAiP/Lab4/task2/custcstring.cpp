#include "custcstring.h"

size_t ctl::strlen(const char* s)
{
    size_t i = 0;
    while (s[i]) i++;
    return i;
}

void* ctl::memcpy(void* s1, const void* s2, size_t n)
{
    char* cs1 = (char*)s1;
    char* cs2 = (char*)s2;
    for(int i = 0; i<n; i++)
    {
        cs1[i] = cs2[i];
    }
    return s1;
}

void* ctl::memmove(void* s1, const void* s2, size_t n)
{
    char* cs1 = (char*)s1;
    char* cs2 = (char*)s2;
    char* t = new char[n];
    for(int i = 0; i<n; i++)
    {
        t[i] = cs2[i];
    }
    for(int i = 0; i<n; i++)
    {
        cs1[i] = t[i];
    }
    delete [] t;
    return s1;
}

char* ctl::strcpy(char* s1, const char* s2)
{
    int i = 0;
    while(s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

char* ctl::strncpy(char* s1, const char* s2, size_t n)
{
    for(int i = 0; i<n; i++)
    {
        s1[i] = s2[i];
    }
    s1[n] = '\0';
    return s1;
}

char* ctl::strcat(char* s1, const char* s2)
{
    size_t size1 = ctl::strlen(s1);
    size_t i = 0;
    while (s2[i])
    {
        s1[size1+i] = s2[i];
        i++;
    }
    s1[size1+i] = '\0';
    return s1;
}

char* ctl::strncat(char* s1, const char* s2, size_t n)
{
    for(int i = 0; i<n; i++)
    {
        s1[i] = s2[i];
    }
    s1[n] = '\0';
    return s1;
}

int ctl::memcmp(const void* s1, const void* s2, size_t n)
{
    char* cs1 = (char*)s1;
    char* cs2 = (char*)s2;
    for(int i = 0; i<n; i++)
    {
        if(cs1[i] == cs2[i]) continue;
        else return cs1[i]-cs2[i];
    }
    return 0;
}

int ctl::strcmp(const char* s1, const char* s2)
{
    int i = 0;
    while(s1[i] && s2[i])
    {
        if(s1[i] != s2[i]) return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

int ctl::strncmp(const char* s1, const char* s2, size_t n)
{
    for(int i = 0; i<n; i++)
    {
        if(s1[i] != s2[i]) return s1[i] - s2[i];
    }
    return 0;
}

char* ctl::strtok(char* s1, const char* s2)
{
    bool (*isDelim)(char, const char*) = [](char ch, const char* s2){
        int i = 0;
        while(s2[i]) 
        {
            if(s2[i] == ch) return true;
            i++;
        }
        return false;
    };
    static char *backup; 
    if(!s1)
    {
        s1 = backup;
    }
    if(!s1)
    {
        return nullptr;
    }

    while (true)
    {
        if(isDelim(*s1, s2))
        {
            s1++;
            continue;
        }
        if(*s1 == '\0') return nullptr;
        break;
    }
    char* ret = s1;
    while (true)
    {
        if(isDelim(*s1, s2)) 
        {
            *s1 = '\0';
            s1++;
            backup = s1;
            return ret;
        }
        if(*s1 == '\0') 
        {
            backup = s1;
            return ret;
        }
        s1++;
    }
    
}

void* ctl::memset(void* s, int c, size_t n)
{
    char *cs = (char*)s;
    char cc = c;
    for(int i = 0; i< n; i++)
    {
        cs[i] = cc;
    }
    return s;
}
