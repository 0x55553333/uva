/* IPair: Densely packed integer pair */
struct IPair {IPair(int fst, int snd){this->p=0ULL;
this->setFirst(fst);this->setSecond(snd);}
IPair(){this->p=0ULL;}
int first(){return (int)(this->p);}
int second(){return (int)(this->p >> 32);}
void setFirst(int f){this->p&=0xffffffff00000000ULL;
this->p|=(unsigned long long)f;}
void setSecond(int s){this->p&=0x00000000ffffffffULL;
this->p|=(((unsigned long long)s)<<32);}
private:unsigned long long p;  
};
