#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
#include "Ninja.hpp"

namespace ariel {
        class OldNinja : public Ninja {
        public:
            OldNinja(string name, Point location) : Ninja(name, location, OLD_NINJA_HP, OLD_NINJA_SPEED) {};
            OldNinja() : Ninja("", Point(), OLD_NINJA_HP, OLD_NINJA_SPEED) {};

            virtual ~OldNinja() = default;

        void print() const override {
            cout << "\t" << this->name << " (OldNinja):" << endl;
            cout << "\t\tStatus: " << (this->isAlive() ? "Alive" : "Dead") << " (" << getHealthPoints() << " / " << OLD_NINJA_HP << ")" << endl;
            cout << "\t\tLocation: ";
            getLocation().print();
            cout << endl;
        }
    };    
}

#endif