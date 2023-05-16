#include "Ninja.hpp"

namespace ariel {

    Ninja::Ninja(string name, Point location, int healthPoints, int speed) : Character(name, location, healthPoints), speed(speed) {};

    void Ninja::actionControl(Character* enemy) {

        this->move(enemy);
        this->slash(enemy);

    }

    void Ninja::move(Character* enemy) {
        if (this == enemy) {
            throw std::runtime_error("Ninja can't move throw himself");
        }

        if (!enemy->isAlive()) {
            throw std::runtime_error("Ninja can't move throw a dead enemy");
        }

        if (!this->isAlive()) {
            throw std::runtime_error("Ninja can't move if he's dead");
        }

        Point new_locatin = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->getSpeed());
        this->setLocation(new_locatin);
    }

    void Ninja::slash(Character* enemy) {
        if (this == enemy) {
            throw std::runtime_error("Ninja can't slash himself");
        }

        // if (!enemy->isAlive()) {
        //     throw std::runtime_error("Ninja can't slash a dead enemy");
        // }

        if (!this->isAlive()) {
            throw std::runtime_error("Ninja can't slash if he's dead");
        }    

        if (this->distance(enemy) < 1) {
            enemy->hit(NINJA_DMG);  
        }
    }

    int Ninja::getSpeed() {
        return this->speed;
    }

}
