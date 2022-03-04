// A fraction type c++
struct Fraction {
//public: // implicit for struct, no need to write it
    void set_num(int i) {
        num = i;
    }

    void set_den(int i) {
        if (i != 0) {
            num = i;
        }
    }

    // This a getter
    // Getter is not supposed to modify the object
    // THEREFORE we declare it as a const method
    int get_num() const {
        return num;
    }

    int get_den() const {
        return den;
    }
// protected:
    private:
        int num, den;
};