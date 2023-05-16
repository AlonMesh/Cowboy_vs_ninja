#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include "Ninja.hpp"

namespace ariel {
    class TrainedNinja : public Ninja {
        public:
            TrainedNinja(string name, Point location) : Ninja(name, location, TRAINED_NINJA_HP, TRAINED_NINJA_SPEED) {};
            TrainedNinja() : Ninja("", Point(), TRAINED_NINJA_HP, TRAINED_NINJA_SPEED) {};

            virtual ~TrainedNinja() = default;

        void print() const override {
            cout << "\t" << this->name << " (TrainedNinja):" << endl;
            cout << "\t\tStatus: " << (this->isAlive() ? "Alive" : "Dead") << " (" << getHealthPoints() << " / " << TRAINED_NINJA_HP << ")" << endl;
            cout << "\t\tLocation: ";
            getLocation().print();
            cout << endl;
        }
    };
}

#endif