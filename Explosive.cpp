#include <iostream>
#include <stdio.h>
#include <string>
#include <chrono>
#include <thread>
std::chrono::seconds sleep(1);

class explosive{
    public:
    std::string bombName;
    void init(std::string bombNick="timed explosive"){
        bombName=bombNick;
    }
    void countDown(int timer=10){
        printf("The ");
        std::cout<<bombName; // Because printf decides to break if you try to use %s and a string, I used std::cout to output it.
        printf(" seems to have %i seconds left on the timer.\n", timer) ;
        for(int countDown=timer;countDown!=0;countDown=countDown){
            if(countDown-1==0){
                printf("You watch the timer count down from 1 to...\n");
                std::this_thread::sleep_for(sleep);
                printf("The bomb explodes and you die in the explosion!\n");
                break;
            }
            else{
                printf("You watch the timer count down from %i to %i\n", countDown, (countDown-1));
                countDown--;
                std::this_thread::sleep_for(sleep);
            }
        }
    }
};


int main(){
    explosive grenade;
    grenade.init("grenade");
    grenade.countDown(10);
}