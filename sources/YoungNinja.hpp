#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
#include "Ninja.hpp"

namespace ariel {
        class YoungNinja : public Ninja {
        public:
            YoungNinja(string name, Point location) : Ninja(name, location, YOUNG_NINJA_HP, YOUNG_NINJA_SPEED) {};
            YoungNinja() : Ninja("", Point(), YOUNG_NINJA_HP, YOUNG_NINJA_SPEED) {};

            virtual ~YoungNinja() = default;

        void print() const override {
            cout << "\t" << this->name << " (YoungNinja):" << endl;
            cout << "\t\tStatus: " << (this->isAlive() ? "Alive" : "Dead") << " (" << getHealthPoints() << " / " << YOUNG_NINJA_HP << ")" << endl;
            cout << "\t\tLocation: ";
            getLocation().print();
            cout << endl;
        }
    };
}

#endif