#include <ostream>
#include "Message.h"
#include "Utils.h"
#include "MessageStore.h"
#include "DurationLogger.h"

int main() {

    DurationLogger d1("main()");
    Message m1(10);
    Message m2(20);
    Message m3( 30);
    Message m4(10);
    std::cout <<m1;
    std::cout <<m2;
    std::cout << "costruiti"<<std::endl;
    std::cout<<std::endl;

    MessageStore m(2);
    m.add(m1);
    m.printMessages();
    std::cout<<std::endl;

    m.add(m3);
    m.printMessages();
    std::cout<<std::endl;
    m.compact();
    m.printMessages();
    std::cout<<std::endl;

    m.add(m4);
    m.printMessages();
    std::cout<<std::endl;

    m.add(m2);
    m.printMessages();

    return 0;
}