#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

class Criteria {
    friend ostream& operator<<(ostream& o, const Criteria& c);

    public:
        virtual bool matches(const Song& s) const = 0;
        virtual void print(ostream& o) const = 0;

};

class A_Criteria: virtual public Criteria {
    public:
        //Constructor
        A_Criteria(const string& artist);

        //Methods
        virtual bool matches(const Song& s) const;
        virtual void print(ostream& o) const;

    private:
        string artist;
};

class C_Criteria: virtual public Criteria {
    public:
        //Constructor
        C_Criteria(const string& category);

        //Methods
        virtual bool matches(const Song& s) const;
        virtual void print(ostream& o) const;

    private:
        string category;
};

class AorC_Criteria: public A_Criteria, public C_Criteria {
    public:
        //Contructor
        AorC_Criteria(const string& artist, const string& category);

        //Methods
        virtual bool matches(const Song& s) const;
        virtual void print(ostream& o) const;
};

#endif