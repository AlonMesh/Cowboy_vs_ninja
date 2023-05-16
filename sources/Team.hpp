#ifndef TEAM_HPP
#define TEAM_HPP
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>

namespace ariel
{
    class Team
    {
    protected:
        Character *leader;
        vector<Character *> champions;

    private:
        int numCowboys;

    public:
        Team(Character *leader);

        virtual ~Team() = default;

        // Insert a Character to a team
        virtual void add(Character *character);

        // mine
        static void add_validation(Character *character, vector<Character*> members);

        // edit
        virtual void attack(Team *enemy_team);

        // Returns the amout of alive champions in team
        int stillAlive();

        // edit
        void print();

        // mine
        Character *getLeader();

        // mine
        vector<Character*> getMembers();
    };
}

#endif