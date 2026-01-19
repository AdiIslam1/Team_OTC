#ifndef HEROES_HPP
#define HEROES_HPP

#include <iostream>
#include <string>
#include <color.hpp>
#include <vector>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>

using namespace std;

class Hero {
protected:
    string heroType;
    string name;
    int skillLevel;
    string status; // "Available", "On-Duty", "Resting", "Dead"

public:
    Hero(const string& heroType);
    virtual ~Hero() = default;

    // Getters
    string getHeroType() const { return heroType; }
    string getName() const { return name; }
    int getSkillLevel() const { return skillLevel; }
    string getStatus() const { return status; }

    static void printHeroList(atomic<bool>& isRunning);
};

class Medic : public Hero {
public:
    Medic(const string& name, int skillLevel, const string& status) : Hero("Medic") {
        this->name = name;
        this->skillLevel = skillLevel;
        this->status = status;
    };
};

class Police : public Hero {
public:
    Police(const string& name, int skillLevel, const string& status) : Hero("Police") {
        this->name = name;
        this->skillLevel = skillLevel;
        this->status = status;
    };
};

class Firefighter : public Hero {
public:
    Firefighter(const string& name, int skillLevel, const string& status) : Hero("Firefighter") {
        this->name = name;
        this->skillLevel = skillLevel;
        this->status = status;
    };
};

extern vector<Hero> heroList;

void tabSpace(int n);

#endif
