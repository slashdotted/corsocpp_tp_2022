enum Curricula {
    Mechanics = 0, ComputerScience , Electronics, Management, AI
};

enum class Curricula2 {
    ComputerScience, Electronics, Management, AI
};

struct MyStruct {
};

// A fraction type in C
struct FractionInC {
    int num, den;
};

void set_num(FractionInC& f, int i) {
    f.num = i;
}

void set_den(FractionInC& f, int i) {
    if (i != 0) {
        f.num = i;
    }
}

// A fraction type c++
struct FractionInCPP {
//public: // implicit for struct, no need to write it
    void set_num(int i) {
        num = i;
    }

    void set_den(int i) {
        if (i != 0) {
            num = i;
        }
    }
// protected:
    private:
        int num, den;
};

int main() {
    MyStruct m;
    Curricula c = Curricula::ComputerScience;
    if (c == 0) {
        // expecting ComputerScience
    }
    Curricula2 c2 = Curricula2::ComputerScience;
    /*if (c2 == 0) {
        NO AUTOMATIC CONVERSION FROM enum class TO/FROM int
    }*/

    FractionInC f;
    f.num = 1;
    f.den = 2;
    FractionInCPP f2;
    f2.set_num(1);
    f2.set_den(2);

}