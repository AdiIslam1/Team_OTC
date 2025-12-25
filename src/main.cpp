#include <iostream>
#include <thread>
#include <chrono>
#include <color.hpp>
#include <stressCalls.hpp>
using namespace std;

int main() {
    cout << "\033[2J\033[H"; //putting cursor on top left
    cout << Color::cyan("======================================") << endl;
    cout << Color::yellow(Color::bold(" BACHAO Stress Calls Dispatch Terminal")) << endl;
    cout << Color::cyan("======================================") << endl;

    int timeToPlay = 120;
    atomic<bool> isRunning(true);

    StressCall::generate(get_random(2, 4));

    thread worker(StressCall::printCallList, ref(isRunning));

    while (timeToPlay > 0) {
        // Every 20 seconds, generate more calls
        if (timeToPlay < 120 && timeToPlay % 20 == 0) {
            StressCall::generate(get_random(1, 3));
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        timeToPlay--;
    }

    isRunning = false;
    if (worker.joinable()) {
        worker.join();
    }

    cout << "\n" << Color::bold("Thanks for playing") << endl;
}
