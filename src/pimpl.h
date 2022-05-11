#include <string>
#include <memory>

struct MyDataTypePrePimpl {
    private:
        std::string s;
        int m;
    public:
        int getM() const;
        std::string getS() const; 

};


struct MyDataType {
    private:
        struct pimpl;
        std::unique_ptr<pimpl> m_private;
    public:
        MyDataType();
        virtual ~MyDataType();
        int getM() const;
        std::string getS() const;  
};