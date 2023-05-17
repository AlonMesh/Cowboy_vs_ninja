#ifndef NINJA_HPP
#define NINJA_HPP
#include "Character.hpp"
#define YOUNG_NINJA_HP 100
#define YOUNG_NINJA_SPEED 14
#define TRAINED_NINJA_HP 120
#define TRAINED_NINJA_SPEED 12
#define OLD_NINJA_HP 150
#define OLD_NINJA_SPEED 8
#define NINJA_DMG 40

namespace ariel {
    class Ninja : public Character {

        private:
            int speed;
        
        protected:
            /**
             * @brief A protected constructor used only by derived classes of Ninja.
             * 
             * @param name The name of the ninja.
             * @param location The location of the ninja.
             * @param healthPoints The health points of the ninja.
             * @param speed The speed of the ninja.
             */
            Ninja(string name, Point location, int healthPoints, int speed);

        public:
            // A virtual destructor for the Ninja class.
            virtual ~Ninja() = default;

            /**
             * A function that moves the ninja through a given enemy.
             * @param enemy A pointer to the enemy to move through.
             */
            void move(Character* enemy);
            
            /**
             * A function that deals massive damage to an enemy if he's close enough.
             * @param enemy A pointer to the enemy to deal damage to.
             */
            void slash(Character* enemy);

            // Returns the speed of the ninja
            int getSpeed();

            // A function that controls the ninja's action against the enemy
            void actionControl(Character* enemy);

            // A pure virtual function that prints the ninja's details
            virtual string print() const = 0;
    };

        


}

#endif