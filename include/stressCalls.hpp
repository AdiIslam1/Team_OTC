#ifndef STRESSCALLS_HPP
#define STRESSCALLS_HPP
using namespace std;
#include <iostream>
#include <string>
#include <color.hpp>
#include <vector>
#include <random>
#include <ctime>

class StressCall {
private:
    string type; // Medical, Hazard, Crime, Political, Disaster
    string activity;
    string address;
    string priority; // Low, Medium, High, Very high, Critical
public:
    //getters
    string getType() const {
        return this->type;
    }
    string getActivity() const {
        return this->activity;
    }
    string getAddress() const {
        return this->address;
    }
    string getPriority() const {
        return this->priority;
    }
    //setters
    void setType(string type) {
        this->type = type;
    }
    void setActivity(string activity) {
        this->activity = activity;
    }
    void setAddress(string address) {
        this->address = address;
    }
    void setPriority(string priority) {
        this->priority = priority;
    }
    //constructor
    StressCall(string type, string activity, string address, string priority) {
        setType(type);
        setActivity(activity);
        setAddress(address);
        setPriority(priority);
    }

    static void generate(int level);
    static void printCallList();
};

extern std::vector<std::string> types;
extern std::vector<std::string> priorities;
extern std::vector<std::string> addresses;
extern std::vector<std::string> medicalStressCalls;
extern std::vector<std::string> hazardStressCalls;
extern std::vector<std::string> crimeStressCalls;
extern std::vector<std::string> politicalStressCalls;
extern std::vector<std::string> disasterStressCalls;
extern std::vector<StressCall> calls;

int get_random(int min, int max);

#endif
