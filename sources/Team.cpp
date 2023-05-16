#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *leader) : leader(leader)
    {
        this->numCowboys = 0;
        this->add(leader);
    }

    void Team::add(Character *champion)
    {
        add_validation(champion, this->getMembers());

        if (dynamic_cast<Ninja *>(champion) != nullptr)
        {
            // champion is a Ninja
            this->champions.push_back(champion);
            champion->joinedTeam();
        }
        else if (dynamic_cast<Cowboy *>(champion) != nullptr)
        {
            // champion is a Cowboy
            champions.insert(champions.begin() + numCowboys, champion);
            this->numCowboys += 1;
            champion->joinedTeam();
        }
        else
        {
            throw runtime_error("A character must be cowboy or ninja");
        }
    }

    void Team::add_validation(Character *character, vector<Character*> members)
    {
        if (character->isInTeam())
        {
            throw runtime_error("Character can be only in one team");
        }

        if (members.size() >= 10)
        {
            throw runtime_error("Team can has only 10 members");
        }

        if (!character->isAlive())
        {
            throw runtime_error("A dead character can't join a team");
        }
    }

    void Team::attack(Team *enemy_team)
    {
        // if (enemy_team == nullptr) {
        //     throw invalid_argument("Can't work with nullptr");
        // }

        // if (this == enemy_team)
        // {
        //     throw runtime_error("Team can't attack itself");
        // }

        // if (this->stillAlive() <= 0 || enemy_team->stillAlive() <= 0)
        // {
        //     throw runtime_error("If all characters in team are dead, it can't attack or be attacked");
        // }

        // if (!this->leader->isAlive())
        // {
        //     // Find the closest enemy to the dead leader
        //     Character* newLeader = this->leader->findClosestCharacter(this->getMembers());
        //     // Set him new leader
        //     this->leader = newLeader;
        // }

        // // Find the closest enemy to leader of the attacking team
        // // Set him new target
        // Character* target = this->leader->findClosestCharacter(enemy_team->getMembers());

        // // attacking
        // for (auto champion : this->champions)
        // {
        //     if (champion->isAlive())
        //     {
        //         if (dynamic_cast<Cowboy *>(champion) != nullptr)
        //         {
        //             Cowboy *cowboy = dynamic_cast<Cowboy *>(champion);
        //             if (cowboy->hasboolets())
        //             {
        //                 cowboy->shoot(target);
        //                 cowboy->raiseDmgDealt(COWBOY_DMG);
        //             }
        //             else
        //             {
        //                 cowboy->reload();
        //             }
        //         }
        //         else
        //         {
        //             if (dynamic_cast<YoungNinja*>(champion) != nullptr) {
        //                 YoungNinja *ninja = dynamic_cast<YoungNinja*>(champion);
        //                 ninja->actionControl(target);
        //                 ninja->raiseDmgDealt(NINJA_DMG);
        //             }
        //             else if (dynamic_cast<TrainedNinja*>(champion) != nullptr) {
        //                 TrainedNinja *ninja = dynamic_cast<TrainedNinja*>(champion);
        //                 ninja->actionControl(target);
        //                 ninja->raiseDmgDealt(NINJA_DMG);
        //             }
        //             else {
        //                 OldNinja *ninja = dynamic_cast<OldNinja*>(champion);
        //                 ninja->actionControl(target);
        //                 ninja->raiseDmgDealt(NINJA_DMG);
        //             }
        //         }

        //         if (!target->isAlive()) {
        //             if (enemy_team->stillAlive() == 0) {
        //                 break;
        //             }

        //             target = this->leader->findClosestCharacter(enemy_team->getMembers());                    
        //         }
        //     }
        // }
    }

    int Team::stillAlive()
    {
        int alive_characters = 0;

        // for (auto champion : this->champions)
        // {
        //     if (champion->isAlive())
        //     {
        //         alive_characters++;
        //     }
        // }
        return alive_characters;
    }

    void Team::print()
    {
        cout << "Team (" << this->getLeader()->getName();
        cout << ") has " << this->stillAlive() << " / " << this->getMembers().size() << " members alive" << endl;
        for (auto champion : this->champions)
        {
            champion->print();
        }
    }

    Character *Team::getLeader()
    {
        return this->leader;
    }

    vector<Character*> Team::getMembers() {
        return this->champions;
    }

}
