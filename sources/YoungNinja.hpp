#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
#include "Ninja.hpp"

namespace ariel {
        class YoungNinja : public Ninja {
        public:
            YoungNinja(string name, Point location) : Ninja(name, location, YOUNG_NINJA_HP, YOUNG_NINJA_SPEED) {};
            YoungNinja() : Ninja("", Point(), YOUNG_NINJA_HP, YOUNG_NINJA_SPEED) {};

            virtual ~YoungNinja() = default;

        string print() const override {
            string result;
            result += "\t" + this->name + " (YoungNinja):\n";
            result += "\t\tStatus: ";
            result += (this->isAlive() ? "Alive" : "Dead");
            result += " (" + to_string(getHealthPoints()) + " / " + to_string(YOUNG_NINJA_HP) + ")\n";
            result += "\t\tLocation: (" + to_string(getLocation().getx()) + ", " + to_string(getLocation().gety()) + ")\n";
            return result;
        }
    };
}

#endif