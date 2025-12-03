#include <iostream>
#include "SimpleTextGenerator.h"
#include <thread>
#include <chrono>
using namespace std;

int main() {
    SimpleTextGenerator tg;
    tg.trainFromText("Now is not the time for sleep, now is the time for party!");
    for(int i=0; i<10; ++i){
        cout<<tg.generate("now is",6)<<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}
