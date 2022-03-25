#include <vector>
#include <memory>
#include <iostream>


struct Pod {
    ~Pod() {
        std::cout<< "Destroying Pod\n";
    }

};

void take_int(int *x) {
    // ...
}

void foo(std::unique_ptr<int> v) {

}

void bar(std::unique_ptr<int>& v) {

}

void baz(int* i) {

}

void foo(std::shared_ptr<Pod> s) {

}

int main() {
    using std::vector, std::unique_ptr, std::shared_ptr, std::make_unique, std::make_shared, std::move, std::cout;

    auto i{new int{13}};
    take_int(i);
    // should you delete i?
    vector<int*> v;
    v.push_back(i); // the pointer gets copied not the pointed value

    unique_ptr<int> up{new int{13}};
    unique_ptr<int> up2{i};
    unique_ptr<int> up3{make_unique<int>(45)};
    auto up4{make_unique<int>(45)};
    cout << *up <<'\n'; // unique_ptr can be dereferenced
    
    // up = up2; // cannot copy assign a unique_ptr
    // foo(up); // cannot copy construct a unique_ptr
    bar(up);
    baz(up.get());


    vector<unique_ptr<Pod>> vop;
    {
        std::cout << "--Start--\n";
        auto pp{make_unique<Pod>()};
        vop.push_back(move(pp)); // change ownership
        std::cout << "--End--\n";
    }
    std::cout << "--Back in main--\n";
    // no need to free memory managed by unique_ptr


    // shared_ptr
    shared_ptr<Pod> sp {new Pod};
    shared_ptr<Pod> sp2 {make_shared<Pod>()};
    auto spp{make_shared<Pod>()};
    auto spp2 = spp;
    foo(spp);
    cout << spp.use_count() << '\n';
}