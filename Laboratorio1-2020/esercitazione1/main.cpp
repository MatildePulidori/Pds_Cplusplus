#include <iostream>
#include <optional>
#include <vector>

using namespace std;

#include "Message.h"
#include "MessageStore.h"
#include "DurationLogger.h"


void test_message(){
    Message buf1[10];
    Message *buf2 = new Message[10];
    for(int i=0; i<10; i++){
        buf1[i] = Message(10000000);
    }

    {
        DurationLogger dl("assign");
        for(int i=0; i<10; i++){
            buf2[i] = buf1[i];
        }
    }

    {
        DurationLogger dl("move");
        for(int i=0; i<10; i++){
            buf2[i] = std::move(buf1[i]);
        }
    }
    delete[] buf2;
}

void test_store(){
    MessageStore store(10);
    std::vector<long> ids; // remember message ids for testing deletes

    for(int i=0; i<100; i++){
        Message m(1000000);
        ids.push_back(m.getId());
        store.add(m);
    }

    // remove odd ids (50 ids)
    for(auto id: ids){
        if(id%2){
            store.remove(id);
        }
    }

    store.compact();

    std::cout<<"dimension: " <<store.getDim()<<std::endl;

}


int main() {
    test_message();
    test_store();
}
