#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP
#include "Team.hpp"

namespace ariel {
    /**
     * A derived class of the Team class, representing a team that attacks more strategically than a regular team.
     * The team prioritizes attacking low-health enemies, targets high damage enemies, and maximizes damage cooperation.
     * This class implements the attack method of the parent class to provide smart attack strategy.
    */
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader) : Team(leader) {};

        /**
         * I conducted an analysis to determine which character type dealt the most damage in a single round.
         * To achieve this, I created 400 random teams of 10 characters, with a distribution of:
         * 40% Cowboys and 20% of each type of Ninja.
         * I recorded the winner team of each round, and calculated the amount of damage dealt by each character,
         * categorized by their class character types.
         * This enabled me to calculate the average damage each type does in each game with good probability:
         *      Cowboy:  167.98
         *      Young:   137.73
         *      Trained: 141.57
         *      Old:     160.53
         * The average damage divided by the character's HP amount:
         *      Cowboy:  1.5271
         *      Young:   1.3773
         *      Trained: 1.1798
         *      Old:     1.0702
         * (It basiclly means: for each 1 HP of a character, it deals this amount of damage)
        */
        void attack(Team *enemy_team) override {
            //todo
        };
    };
}

#endif