#ifndef TEAM2_HPP
#define TEAM2_HPP
#include "Team.hpp"

namespace ariel {
    /**
     * Represents a team of characters with different iteration order than 'Team'.
     * In 'Team2', the iteration order follows the order in which characters were added to the team,
     * regardless of whether they are a cowboy or a ninja.
    */
    class Team2 : public Team
    {
    public:
        Team2(Character *leader) : Team(leader) {};
        
        void add(Character *champion) override {
            add_validation(champion, this->getMembers());
            this->champions.push_back(champion);
        }
    };
}

#endif