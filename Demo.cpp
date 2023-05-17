/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <random> //mine
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    // Team b(tom); should throw tom is already in team a

     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));


     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
     }

     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;

   // //---- mine ------
   // random_device rd;
   // mt19937 gen(rd());
   // uniform_int_distribution<> distr_character(1, 10);
   // uniform_int_distribution<> distr_x(0, 100);
   // uniform_int_distribution<> distr_y(0, 100);

   // for (int i = 0 ; i < 1 ; i++) {

   // Cowboy* cowboy_c = new Cowboy("LeaderC", Point(distr_x(gen), distr_y(gen)));
   // Team team_c(cowboy_c);
   // for (int i = 0; i < 9; i++) {
   //    int random_num = distr_character(gen);

   //    if (1 <= random_num && random_num <= 4) {
   //       team_c.add(new Cowboy("cowboyC", Point(distr_x(gen), distr_y(gen))));
   //    }
   //    if (5 <= random_num && random_num <= 6) {
   //       team_c.add(new YoungNinja("YoungNinjaC", Point(distr_x(gen), distr_y(gen))));
   //    }
   //    if (7 <= random_num && random_num <= 8) {
   //       team_c.add(new TrainedNinja("TrainedNinjaC", Point(distr_x(gen), distr_y(gen))));
   //    }
   //    if (9 <= random_num && random_num <= 10) {
   //       team_c.add(new OldNinja("OldNinjaC", Point(distr_x(gen), distr_y(gen))));
   //    }
   // }

   // Cowboy* cowboy_d = new Cowboy("LeaderD", Point(distr_x(gen), distr_y(gen)));
   // Team team_d(cowboy_d);
   // for (int i = 0; i < 9; i++) {
   //    int random_num = distr_character(gen);

   //    if (1 <= random_num && random_num <= 4) {
   //       team_d.add(new Cowboy("cowboyD", Point(distr_x(gen), distr_y(gen))));
   //    }
   //    if (5 <= random_num && random_num <= 6) {
   //       team_d.add(new YoungNinja("YoungNinjaD", Point(distr_x(gen), distr_y(gen))));
   //    }
   //    if (7 <= random_num && random_num <= 8) {
   //       team_d.add(new TrainedNinja("TrainedNinjaD", Point(distr_x(gen), distr_y(gen))));
   //    }
   //    if (9 <= random_num && random_num <= 10) {
   //       team_d.add(new OldNinja("OldNinjaD", Point(distr_x(gen), distr_y(gen))));
   //    }
   // }

   // while(team_c.stillAlive() > 0 && team_d.stillAlive() > 0){
   //    team_c.attack(&team_d);
   //    if (team_c.stillAlive() > 0 && team_d.stillAlive() > 0) {
   //       team_d.attack(&team_c);
   //    }
   //    // team_A.print();
   //    // team_B.print();
   // }

   // for (auto member : team_c.getMembers()) {
   //    cout << member->getName() << " dealt " << member->GetDmgDealt() << " dmg" << endl;
   // }
   // }
   // // >----mine-----
     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}