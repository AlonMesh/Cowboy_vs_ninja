#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include "Ninja.hpp"

namespace ariel {
    class TrainedNinja : public Ninja {
        public:
            TrainedNinja(string name, Point location) : Ninja(name, location, TRAINED_NINJA_HP, TRAINED_NINJA_SPEED) {};
            TrainedNinja() : Ninja("", Point(), TRAINED_NINJA_HP, TRAINED_NINJA_SPEED) {};

            virtual ~TrainedNinja() = default;

        string print() const override {
            string result;
            result += "\t" + this->name + " (TrainedNinja):\n";
            result += "\t\tStatus: ";
            result += (this->isAlive() ? "Alive" : "Dead");
            result += " (" + to_string(getHealthPoints()) + " / " + to_string(TRAINED_NINJA_HP) + ")\n";
            result += "\t\tLocation: (" + to_string(getLocation().getx()) + ", " + to_string(getLocation().gety()) + ")\n";
            return result;
        }
    };
}

#endif