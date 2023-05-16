#include "Character.hpp"
namespace ariel {

    Character::Character(const string& name, Point location, int healthPoints)
    : name(name), location(location), healthPoints(healthPoints) {
        this->teamMember = false;
        this->dmgDealt = 0;
    };
    Character::Character() : name(""), healthPoints(DEFAULT_HP), location(Point(0,0)) {
        this->teamMember = false;
    };

    bool Character::isAlive() const {
        return (this->getHealthPoints() > 0);
    }

    double Character::distance(Character* other) {
        return this->getLocation().distance(other->getLocation());
    }

    void Character::hit(int damage) {
        // Leagal damage is 10 or 13, but cuz test issues it is positive
        if (damage <= 0) {
            throw std::invalid_argument("Damage taken must be positive");
        }

        if (!this->isAlive()) {
            throw std::runtime_error("can't hit a dead character");
        }
    
        this->healthPoints -= damage;
        
        if (this->healthPoints < 0) {
            this->healthPoints = 0;
        }
    }

    string Character::getName() {
        return this->name;
    }

    Point Character::getLocation() const {
        return this->location;
    }

    int Character::getHealthPoints() const {
        return this->healthPoints;
    }

    void Character::setLocation(Point point) {
        this->location = point;
    }

    void Character::joinedTeam() {
        this->teamMember = true;
    }

    bool Character::isInTeam() {
        return this->teamMember;
    }

    Character* Character::findClosestCharacter(vector<Character*> characters) {
        int minDistance = 99999; // change it to max_int
        Character* closest;

        for (auto character : characters) {
            if (character->isAlive()) {
                if (this->distance(character) < minDistance) {
                    minDistance = this->distance(character);
                    closest = character;
                }
            }
        }

        return closest;
    }

    int Character::GetDmgDealt() {
        return this->dmgDealt;
    }

    void Character::raiseDmgDealt(int number) {
        this->dmgDealt += number;
    }

}