#ifndef CHAR_HPP
#define CHAR_HPP
#include <string>
#include <vector>
#include "Point.hpp"
#define DEFAULT_HP 100
using namespace std;

namespace ariel
{
    /**
     * Abstract class representing a character in a game.
     * This class represents the common properties and behaviors of characters in a game. It's an abstract class and cannot be
     * instantiated directly. It's intended to be inherited by more specific character classes, like Cowboy and Ninjas.
     */
    class Character
    {
    protected:
        string name;
        Point location;
        int healthPoints;
        bool teamMember;
        int dmgDealt;

    public:
        /**
         * Character constructor with name, location and health points.
         *
         * @param name The name of the character.
         * @param location The location of the character.
         * @param healthPoints The initial health points of the character.
         */
        Character(const string &name, Point location, int healthPoints);

        /**
         * Character default constructor.
         * Initializes the name to an empty string, the health points to the default value,
         * and the location to the origin (0,0).
         */
        Character();
        virtual ~Character() = default;

        // Copy Constructor
        Character(const Character &other)
        {
            name = other.name;
            location = other.location;
            healthPoints = other.healthPoints;
        }

        // Copy Assignment Operator
        Character &operator=(const Character &other)
        {
            if (this == &other)
            {
                return *this;
            }
            name = other.name;
            location = other.location;
            healthPoints = other.healthPoints;
            return *this;
        }

        // Move Constructor
        Character(Character &&other) noexcept
        {
            name = move(other.name);
            location = move(other.location);
            healthPoints = move(other.healthPoints);
        }

        // Move Assignment Operator
        Character &operator=(Character &&other) noexcept
        {
            if (this == &other)
            {
                return *this;
            }
            name = move(other.name);
            location = move(other.location);
            healthPoints = move(other.healthPoints);
            return *this;
        }

        /**
         * Check if the Character is alive
         * @return true if the Character's health points are greater than 0, false otherwise
         */
        bool isAlive() const;

        /**
         * Calculates the distance between the current character and another character.
         * @param other A pointer to the other character.
         * @return The distance between the two characters.
         */
        double distance(Character *other);

        /**
         * Decreases the health points of the character by the given damage amount.
         * If the character's health points go below 0, isAlive() will return false.
         * @param damage the amount of damage to deal to the character
         */
        void hit(int damage);

        // Returns the name of the Character
        string getName();

        // Returns Point object with the same x and y values of the position of the Character
        Point getLocation() const;

        // Returns the current HP of a Character
        int getHealthPoints() const;

        /**
         * Change the location of a Character
         * @param point the new location
         */
        void setLocation(Point point);

        // Change the membership status of a Character
        void joinedTeam();

        // Return true if a Character is a member of a team
        bool isInTeam();

        /**
         * Find the closest Chracter to a given Character from a group of Characters
         * @param characters Group of Characters
         * @returns Pointer to the closest member in 'characters' to the given Character
         */
        Character* findClosestCharacter(vector<Character*> characters);

        /**
         * Print information about the Character to the console, including name, status (alive/dead), health points,
         * and location.
         */
        virtual void print() const = 0; // pure virtual function

        // Get the amount of damage a Character dealt
        int GetDmgDealt();

        // Sum the amount of damage a Character dealt
        void raiseDmgDealt(int number);
    };
}
#endif