#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor\n"; }
    ~Base() { cout << "Base destructor\n"; }
};

class Derived : public Base {
    int* data;
public:
    Derived(int val) {
        cout << "Derived constructor\n";
        data = new int(val);
        cout << "Resource allocated at " << data << " with value " << *data << endl;
    }
    ~Derived() {
        cout << "Derived destructor\n";
        delete data;
        cout << "Resource deleted\n";
    }
};

void testWithoutVirtual() {
    cout << "=== Without virtual destructor ===\n";
    Base* ptr = new Derived(42);
    delete ptr;
}

class VBase {
public:
    VBase() { cout << "VBase constructor\n"; }
    virtual ~VBase() { cout << "VBase destructor\n"; }
};

class VDerived : public VBase {
    int* data;
public:
    VDerived(int val) {
        cout << "VDerived constructor\n";
        data = new int(val);
        cout << "Resource allocated at " << data << " with value " << *data << endl;
    }
    ~VDerived() {
        cout << "VDerived destructor\n";
        delete data;
        cout << "Resource deleted\n";
    }
};

void testWithVirtual() {
    cout << "=== With virtual destructor ===\n";
    VBase* ptr = new VDerived(99);
    delete ptr;
}

int main() {
    testWithoutVirtual();
    cout << endl;
    testWithVirtual();
    return 0;
}
