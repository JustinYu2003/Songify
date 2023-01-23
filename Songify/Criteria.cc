#include "Criteria.h"

//<< Operator
ostream& operator<<(ostream& o, const Criteria& c) {
    c.print(o);
    return o;
}

//Constructor
A_Criteria::A_Criteria(const string& artist) {
    this->artist = artist;
}

bool A_Criteria::matches(const Song& s) const {
    return (s.getArtist().compare(artist) == 0);
}

void A_Criteria::print(ostream& o) const {
    o<<"Will match if have the same artist: "<<artist<<endl;
}



//Constructor
C_Criteria::C_Criteria(const string& category) {
    this->category = category;
}

bool C_Criteria::matches(const Song& s) const {
    return (s.getCategory().compare(category) == 0);
}

void C_Criteria::print(ostream& o) const {
    o<<"Will match if have the same category: "<<category<<endl;
}



//Contructor
AorC_Criteria::AorC_Criteria(const string& artist, const string& category) 
    : A_Criteria(artist), C_Criteria(category) {
}

bool AorC_Criteria::matches(const Song& s) const {
    return A_Criteria::matches(s) || C_Criteria::matches(s);
}

void AorC_Criteria::print(ostream& o) const {
    o<<"Will match if fufills the following conditions: "<<endl;
    A_Criteria::print(o);
    C_Criteria::print(o);
}