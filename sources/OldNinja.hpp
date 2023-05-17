#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
#include "Ninja.hpp"

namespace ariel {
        class OldNinja : public Ninja {
        public:
            OldNinja(string name, Point location) : Ninja(name, location, OLD_NINJA_HP, OLD_NINJA_SPEED) {};
            OldNinja() : Ninja("", Point(), OLD_NINJA_HP, OLD_NINJA_SPEED) {};

            virtual ~OldNinja() = default;

        string print() const override {
            string result;
            result += "\t" + this->name + " (OldNinja):\n";
            result += "\t\tStatus: ";
            result += (this->isAlive() ? "Alive" : "Dead");
            result += " (" + to_string(getHealthPoints()) + " / " + to_string(OLD_NINJA_HP) + ")\n";
            result += "\t\tLocation: (" + to_string(getLocation().getx()) + ", " + to_string(getLocation().gety()) + ")\n";
            return result;
        }
    };    
}

#endif