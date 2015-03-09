#include <iostream>
using namespace std;

class Player {
public:
    void NonVirtual() {
        cout << "Base NonVirtual called.\n";
    }
    virtual void Virtual() {
        cout << "THIS SHOULD DO NOTHING";
    }
};
class Toolbox : public Player{
public:
    void NonVirtual() {
        cout << "Derived NonVirtual called.\n";
    }
    void Virtual() {
        cout << "TOOLBOX";
    }
};

int main() {
    Player* bBase = new Player();
    Player* bDerived = new Toolbox();

    bBase->NonVirtual();
    bBase->Virtual();
    bDerived->NonVirtual();
    bDerived->Virtual();
}
