#include <iostream>
#include <color.hpp>
#include <stressCalls.hpp>
using namespace std;

int main() {
    cout << Color::cyan("======================================") << endl;
    cout << Color::yellow(Color::bold(" BACHAO Stress Calls Dispatch Terminal")) << endl;
    cout << Color::cyan("======================================") << endl;
    StressCall::generate(5);
    StressCall::printCallList();
}
