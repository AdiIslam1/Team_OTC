#include "heroes.hpp"
#include <stressCalls.hpp>

// Hero base class constructor
Hero::Hero(const string& heroType) : heroType(heroType), name(""), skillLevel(0), status("Available") {}

// Move cursor to specific row and column
void moveCursor(int row, int col) {
    cout << "\033[" << row << ";" << col << "H";
}

// Static function to print the hero list
void Hero::printHeroList(atomic<bool>& isRunning) {
    const int startCol = 100;  // Start column for hero list (right side)
    
    while (isRunning) {
        {
        std::lock_guard<std::mutex> lock(callMutex);
        
        int row = 1;
        moveCursor(row++, startCol);
        cout << Color::cyan("======================================");
        moveCursor(row++, startCol);
        cout << Color::yellow(Color::bold(" BACHAO Hero Roster"));
        moveCursor(row++, startCol);
        cout << Color::cyan("======================================");
        moveCursor(row++, startCol);
        cout << "=== AVAILABLE HEROES ===";
        moveCursor(row++, startCol);
        cout << "Total Heroes: " << heroList.size();
        moveCursor(row++, startCol);
        cout << "--------------------------------";

        int idx = 1;
        for (const auto& hero : heroList) {
            moveCursor(row++, startCol);
            cout << idx++ << ". ";
            
            string type = hero.getHeroType();
            if (type == "Medic") cout << Color::red("[MEDIC]");
            else if (type == "Police") cout << Color::blue("[POLICE]");
            else if (type == "Firefighter") cout << Color::yellow("[FIREFIGHTER]");

            cout << " " << hero.getName();
            
            moveCursor(row++, startCol);
            cout << "   Skill Level: " << hero.getSkillLevel();

            string status = hero.getStatus();
            if (status == "Available") cout << " | Status: " << Color::green(status);
            else if (status == "On-Duty") cout << " | Status: " << Color::yellow(status);
            else if (status == "Resting") cout << " | Status: " << Color::cyan(status);
            else if (status == "Dead") cout << " | Status: " << Color::red(status);
            else cout << " | Status: " << status;

            moveCursor(row++, startCol);
            cout << "--------------------------------";
        }
        cout.flush();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// Initialize the heroList with 9 heroes (3 Police, 3 Medics, 3 Firefighters)
vector<Hero> heroList = {
    // Police
    Police("Officer John", 3, "Available"),
    Police("Officer Sarah", 4, "Available"),
    Police("Officer Mike", 5, "Available"),
    // Medics
    Medic("Dr. Emily", 3, "Available"),
    Medic("Dr. James", 4, "Available"),
    Medic("Dr. Lisa", 5, "Available"),
    // Firefighters
    Firefighter("Chief Tom", 3, "Available"),
    Firefighter("Captain Alex", 4, "Available"),
    Firefighter("Lt. Rachel", 5, "Available")
};
