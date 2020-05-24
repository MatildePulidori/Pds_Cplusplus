#include <iostream>
#include <unistd.h>
#include <vector>
#include <map>

class MyMessage{

public:
    int a;
    int b;
    MyMessage():a(0),b(0){};
    MyMessage(int a, int b):a(a),b(b){};


    std::vector<char> serialize(){
        ushort size = sizeof(int)*2;
        std::vector<char> buff(size);
        std::copy((char*)&a, (char*)&a + sizeof(int), buff.begin());
        std::copy((char*)&b, (char*)&b + sizeof(int), buff.begin() + sizeof(int));
        return buff;
    };

    void deserialize(std::vector<char>& buff){
        std::copy(buff.begin(), buff.begin()+sizeof(int), (char*)&a);
        std::copy(buff.begin()+ sizeof(int), buff.begin()+sizeof(int)*2, (char*)&b);
    }
};

class MyResult {

public:
    int res;
    MyResult():res(0){};
    explicit MyResult(int res):res(res){};

    std::vector<char> serialize(){
        ushort size = sizeof(int);
        std::vector<char> buff(size);
        std::copy((char*)&res, (char*)&res + sizeof(int), buff.begin());
        return buff;
    };

    void deserialize(std::vector<char> buff){
        std::copy(buff.begin(), buff.begin()+sizeof(int), (char*)&res);
    }
};

void write_pipe(int fd, std::vector<char> buff){
    ushort size = buff.size();
    // todo check errors
    write(fd, &size, sizeof(ushort));
    write(fd, reinterpret_cast<char*>(&buff[0]), size);
}

std::vector<char> read_pipe(int fd){
    ushort size;
    // todo: check errors
    read(fd, &size, sizeof(ushort));
    std::vector<char> buff(size);
    read(fd, reinterpret_cast<char*>(&buff[0]), size);
    return buff;
}

MyResult add(MyMessage m){
    std::cout<<"add("<<m.a<<", "<<m.b<<")"<<std::endl;
    return MyResult(m.a +m.b);
}

template<typename MessageT, typename ResultT, typename F>
void forkedRPC(MessageT input, F &fun){
    int parentToChild[2];
    pipe(parentToChild);
    int childToParent[2];
    pipe(childToParent);

    pid_t childPid = fork();

    std::vector <char>buff;
    MessageT m;
    ResultT r;

    switch(childPid){
        case -1:
            std::cout<<"error"<<std::endl;
            close(parentToChild[0]);
            close(parentToChild[1]);
            close(childToParent[0]);
            close(childToParent[1]);
            break;
        case 0:
            close(parentToChild[1]);
            close(childToParent[0]);
            std::cout<<"child: waiting for message"<<std::endl;
            buff = read_pipe(parentToChild[0]);
            m.deserialize(buff);
            r = fun(m);
            write_pipe(childToParent[1], r.serialize());
            std::cout<<"child: result sent"<<std::endl;
            close(parentToChild[0]);
            close(childToParent[1]);
            break;
        default:
            close(parentToChild[0]);
            close(childToParent[1]);
            std::cout<<"parent: sending message"<<std::endl;
            write_pipe(parentToChild[1], input.serialize());
            buff = read_pipe(childToParent[0]);
            r.deserialize(buff);
            std::cout<<"parent: result: "<<r.res<<std::endl;
            close(parentToChild[1]);
            close(childToParent[0]);
    }
}


int main() {
    MyMessage input(-3,-2 );
    forkedRPC<MyMessage, MyResult>(input, add);
}
