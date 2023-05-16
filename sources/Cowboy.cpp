#include "Cowboy.hpp"

namespace ariel {

    Cowboy::Cowboy(const string& name, Point location) : Character(name, location, COWBOY_HP), ammo(COWBOY_AMMO) {};

    Cowboy::Cowboy() : Character(), ammo(COWBOY_AMMO) {};

    void Cowboy::shoot(Character* enemy) {
        if (!this->isAlive()) {
            throw runtime_error("A dead cowboy can't shoot");
        }

        if (!enemy->isAlive()) {
            throw runtime_error("Cowboy can't shoot a dead character");
        }

        if (this == enemy) {
            throw runtime_error("Cowboy can't shoot himself");
        }

        if (this->ammo > 0) {
            enemy->hit(COWBOY_DMG);
            this->ammo -= 1;
        }
    }

    bool Cowboy::hasboolets() {
        return (this->getAmmo() > 0);
    }

    void Cowboy::reload() {
        if (this->getAmmo() < 0) {
            throw runtime_error("Somehow a cowboy has negative amount of ammo");
        }

        if (!this->isAlive()) {
            throw runtime_error("A dead cowboy can't relaod");
        }

        this->ammo = 6;
    }

    int Cowboy::getAmmo() {
        return this->ammo;
    }

    void Cowboy::print() const {
        cout << "\t" << this->name << " (Cowboy):" << endl;
        cout << "\t\tStatus: " << (this->isAlive() ? "Alive" : "Dead") << " (" << getHealthPoints() << " / " << COWBOY_HP << ")" << endl;
        cout << "\t\tLocation: ";
        getLocation().print();
        cout << endl;
    }
    
} // namespace ariel
