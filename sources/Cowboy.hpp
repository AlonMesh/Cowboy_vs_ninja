#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"
#define COWBOY_HP 110
#define COWBOY_AMMO 6
#define COWBOY_DMG 10

//TODO: Print()

namespace ariel {
    class Cowboy : public Character {
        private:
            int ammo;

        public:
        /**
         * Cowboy constructor with a name and location. Healthpoint and ammo are already defined for cowboy.
         * 
         * @param name The name of the cowboy.
         * @param location The location of the cowboy.
        */
        Cowboy(const string& name, Point location);
        
        /**
         * Cowboy default constructor.
         * Initializes the name to an empty string, the health points to the default value,
         * the location to the origin (0,0) and the ammo to default value.
         */
        Cowboy();

        virtual ~Cowboy() = default;
        
        /**
         * Shoots the enemy character with a cowboy's gun. Decrase 1 ammo.
         * 
         * @param enemy The character to be shot.
         * @throws std::runtime_error if the cowboy has no ammo, is dead, 
         *         the enemy is dead or is the cowboy himself.
         */
        void shoot(Character* enemy);

        /**
         * Checks if the cowboy has any bullets left.
         * 
         * @return True if the cowboy has at least one bullet, False otherwise.
         */
        bool hasboolets();

        /**
         * Reloads the cowboy's gun.
         * 
         * @throws std::runtime_error if the cowboy already has bullets in his gun.
         */
        void reload();

        //mine
        /**
         * Returns the amount of ammo left in the cowboy's gun.
         * 
         * @return The amount of ammo left in the cowboy's gun.
         */
        int getAmmo();

        void print() const override;
    };
}

#endif