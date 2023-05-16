#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
using namespace ariel;
using namespace std;
#include <cmath> // for sqrt()

TEST_CASE("Point initialize") {
    // Default constructor
    Point p1 = Point();
    CHECK_EQ(p1.getx(), 0.0);
    CHECK_EQ(p1.gety(), 0.0);

    // Constructor with two doubles
    Point p2(1.0, 2.0);
    CHECK_EQ(p2.getx(), 1.0);
    CHECK_EQ(p2.gety(), 2.0);

    // Verify that the default constructor is equivalent to the constructor with two zeros
    Point p3(0.0, 0.0);
    CHECK_EQ(p1.getx(), p3.getx());
    CHECK_EQ(p1.gety(), p3.gety());

    /* The Point class allows for convenient initialization using two integers
    which are automatically converted to doubles. This test simply verifies
    that this automatic conversion works as expected.*/
    Point p(3, 4);
    CHECK_EQ(p.getx(), static_cast<double>(3));
    CHECK_EQ(p.gety(), static_cast<double>(4));

    // The gameboard is the first quadrant, which means X and Y must be always non-negative
    CHECK_THROWS_AS(Point(-1, 0), invalid_argument);
    CHECK_THROWS_AS(Point(0, -1), invalid_argument);
}

TEST_CASE("Distance between points") {
    Point a(1, 2);
    Point b(4, 6);
    Point c(1, 2);

    // The distance between a point and itself should be zero
    CHECK_EQ(a.distance(a), 0.0);

    // The distance between identical points should be zero
    CHECK_EQ(a.distance(c), 0.0);

    // Distance should be symmetric
    CHECK_EQ(a.distance(b), b.distance(a));

    // Distance should be calculated correctly
    CHECK_EQ(a.distance(b), 5.0);

    b = Point(3, 5); // Reset

    // Distance between a and b should be the square root of 13
    CHECK_EQ(a.distance(b), sqrt(13.0));

    // Additional test with arbitrary double values
    Point d(2, 8);
    Point e(9, 4);
    CHECK_EQ(d.distance(e), doctest::Approx(8.062258)); // Approx avoid floating-point error
}

TEST_CASE("moveTowards function") {
    Point currentPoint(0, 0);
    Point targetPoint(5, 0);
    int distance = 5;

    Point resultPoint = Point::moveTowards(currentPoint, targetPoint, distance);

    // If 'currentPoint' is exactly 'distance' away from 'targetPoint', return 'targetPoint'.
    CHECK_EQ(resultPoint.getx(), targetPoint.getx());
    CHECK_EQ(resultPoint.gety(), targetPoint.gety());

    // Reset
    currentPoint = Point(0, 0);
    targetPoint = Point(5, 5); // Real distance is 7.07... 
    distance = 8;

    resultPoint = Point::moveTowards(currentPoint, targetPoint, distance);

    // If 'currentPoint' is already within 'distance' of 'targetPoint', return 'targetPoint'.
    CHECK(resultPoint.getx() == targetPoint.getx());
    CHECK(resultPoint.gety() == targetPoint.gety());

    // Reset
    currentPoint = Point(0, 0);
    targetPoint = Point(10, 10);
    distance = 5;

    resultPoint = Point::moveTowards(currentPoint, targetPoint, distance);

    // Verify that the 'distance' is now 5.0
    CHECK_EQ(resultPoint.distance(currentPoint), 5.0);

    // Verify that 'resultPoint' is on the line connecting 'currentPoint' and 'targetPoint'
    CHECK(resultPoint.isOnLine(currentPoint, targetPoint));

    // Verify that 'resultPoint' is in 'distance' away from 'currentPoint'.
    CHECK_EQ(resultPoint.distance(currentPoint), 5.0);

    // Distance supposed to represent a non-negative number
    CHECK_THROWS_AS(Point::moveTowards(currentPoint, targetPoint, -1), invalid_argument);
}

TEST_CASE("Character initialization") {
    /**
     * Cowboy represents any Character.
     * The function in this test belongs to Character.
     * Unique functions of Cowboy and Ninja will be tested later.
     */ 
    Cowboy* c1 = new Cowboy("Champ", Point());

    // Name, location, and HP were set correctly
    CHECK_EQ(c1->getName(), "Champ");
    CHECK_EQ(c1->getLocation().getx(), 0);
    CHECK_EQ(c1->getLocation().gety(), 0);
    CHECK_EQ(c1->getHealthPoints(), 110);

    // The created Character is alive
    CHECK(c1->isAlive());

    delete c1;
}

TEST_CASE("Character hit()") {
    // Cowboy represents any Character*
    Cowboy* c1 = new Cowboy("Champ", Point());

    // Hitting a 'champ' by 20 HP will leave him with 90 and still alive
    c1->hit(20);
    CHECK_EQ(c1->getHealthPoints(), 90);
    CHECK(c1->isAlive());

    // Hitting a 'champ' by 90 HP will leave him with 0 and kill him
    c1->hit(90);
    CHECK_EQ(c1->getHealthPoints(), 0);
    CHECK_FALSE(c1->isAlive());

    // Can't hit a dead Character
    CHECK_THROWS(c1->hit(10));

    Cowboy* c2 = new Cowboy("Coco", Point());

    // Can't hit with a negative number (No heals allowed)
    CHECK_THROWS(c2->hit(-10));

    // Hitting a Character with more HP than he has left will kill him
    CHECK_NOTHROW(c2->hit(110));
    CHECK_FALSE(c2->isAlive());

    delete c1;
    delete c2;
}

TEST_CASE("distance of Character") {
    // Cowboy represents any Character*
    Cowboy* c1 = new Cowboy("Champ", Point(0, 0));
    Cowboy* c2 = new Cowboy("Coco", Point(1, 0));

    // Character's distance is like Point's distance. That's enough cuz it's based on other tests
    CHECK_EQ(c1->distance(c2), c1->getLocation().distance(c2->getLocation()));

    delete c1;
    delete c2;
}

TEST_CASE("Cowboy initialization") {
    Cowboy* cowboy1 = new Cowboy("Cow", Point());

    // Character's fields are like expected when creating a Cowboy
    CHECK_EQ(cowboy1->getName(), "Cow");
    CHECK_EQ(cowboy1->getLocation().getx(), 0);
    CHECK_EQ(cowboy1->getLocation().gety(), 0);
    CHECK_EQ(cowboy1->getHealthPoints(), 110); // A cowboy has 110 HP

    // Cowboy's fields are like expected when creating a Cowboy
    CHECK_EQ(cowboy1->getAmmo(), 6);
    CHECK(cowboy1->isAlive());
    CHECK(cowboy1->hasboolets());

    // Check if Cowboy is also a Character
    CHECK(dynamic_cast<Character*>(cowboy1) != nullptr);

    delete cowboy1;
}

TEST_CASE("Cowboy shooting") {
    Cowboy* cowboy1 = new Cowboy("Cow", Point());
    Cowboy* cowboy2 = new Cowboy("Enemy", Point(1, 1));

    cowboy1->shoot(cowboy2);

    // 'cowboy1' shoots 'cowboy2' and uses 1 bullet; 'cowboy2' loses 10 HP.
    CHECK_EQ(cowboy1->getAmmo(), 5);
    CHECK(cowboy1->hasboolets());
    CHECK_EQ(cowboy2->getHealthPoints(), 100);

    // Use all the ammo
    for (size_t i = 0; i < 5; i++) {
        cowboy1->shoot(cowboy2);
    }

    // 'cowboy1' has no bullets left
    CHECK_EQ(cowboy1->getAmmo(), 0);
    CHECK_FALSE(cowboy1->hasboolets());

    // Cowboy can't shoot if he has no bullets
    CHECK_THROWS(cowboy1->shoot(cowboy2));

    // 'cowboy1' reloads and has 6 bullets again
    cowboy1->reload();
    CHECK_EQ(cowboy1->getAmmo(), 6);
    CHECK(cowboy1->hasboolets());

    Cowboy* cowboy3 = new Cowboy("KillMe", Point(2, 2));

    // Cowboy can't reload unless he has 0 bullets
    for (size_t i = 0; i < 6; i++) {
        CHECK_THROWS(cowboy1->reload());
        cowboy1->shoot(cowboy3);
    }
    CHECK_NOTHROW(cowboy1->reload());

    Cowboy* cowboy4 = new Cowboy("KillMe", Point(3, 3)); // 110 hp

    // 'cowboy1' shoots 'cowboy4' multiple times until 'cowboy4' dies
    for (size_t i = 0; i < 12; i++) {
        if (cowboy1->hasboolets()) {
            cowboy1->shoot(cowboy4);
        }

        else {
            cowboy1->reload();
        }
    }

    // 'cowboy4' is dead
    CHECK_EQ(cowboy4->getHealthPoints(), 0); 
    CHECK_FALSE(cowboy4->isAlive());

    // Edge cases:
    // Cowboy can't shoot a dead Character
    CHECK_THROWS(cowboy1->shoot(cowboy4));

    // Cowboy can't shoot himself
    CHECK_THROWS(cowboy1->shoot(cowboy1));

    // Cowboy can't reload() when he already has ammo
    cowboy1->shoot(cowboy2);
    cowboy1->reload();
    CHECK_THROWS(cowboy1->reload());

    // Cowboy can't shoot if he's dead (reminder: 'cowboy4' is dead)
    CHECK_THROWS(cowboy4->shoot(cowboy1));

    // Cowboy can't reload if he's dead (reminder: 'cowboy4' is dead)
    CHECK_THROWS(cowboy4->reload());

    delete cowboy1;
    delete cowboy2;
    delete cowboy3;
    delete cowboy4;
}

TEST_CASE("Ninja Initialization") {
    // All types of ninjas have the expected HP and speed
    YoungNinja* ninja1 = new YoungNinja("a", Point(1, 1));
    CHECK_EQ(ninja1->getHealthPoints(), 100);
    CHECK_EQ(ninja1->getSpeed(), 14);

    TrainedNinja* ninja2 = new TrainedNinja("b", Point(2, 2));
    CHECK_EQ(ninja2->getHealthPoints(), 120);
    CHECK_EQ(ninja2->getSpeed(), 12);

    OldNinja* ninja3 = new OldNinja("c", Point(3, 3));
    CHECK_EQ(ninja3->getHealthPoints(), 150);
    CHECK_EQ(ninja3->getSpeed(), 8);

    // Check if any type of Ninja is also a Character
    CHECK(dynamic_cast<Character*>(ninja1) != nullptr);
    CHECK(dynamic_cast<Character*>(ninja2) != nullptr);
    CHECK(dynamic_cast<Character*>(ninja3) != nullptr);

    delete ninja1;
    delete ninja2;
    delete ninja3;
}

TEST_CASE("Ninja move() and slash() functions") {
    YoungNinja* ninja1 = new YoungNinja("a", Point());
    Cowboy* enemy1 = new Cowboy("Enemy", Point(10, 10));
    // Distance now: 14.14213 / ninja1 speed: 14

    // Ninja's slash will do nothing to an enemy if he's more than 1 distance away
    int hpBeforeSlash = enemy1->getHealthPoints();
    ninja1->slash(enemy1);
    CHECK_EQ(enemy1->getHealthPoints(), hpBeforeSlash);

    ninja1->move(enemy1); // Current distace: 0.14213

    // Ninja's slash will deal damagea to an enemy if he's less than 1 distance away
    int expectedHP = enemy1->getHealthPoints() - NINJA_DMG; // NINJA_DMG == 13
    ninja1->slash(enemy1);
    CHECK_EQ(enemy1->getHealthPoints(), expectedHP);

    delete ninja1;
    delete enemy1;

    TrainedNinja* ninja2 = new TrainedNinja("a", Point());
    Cowboy* enemy2 = new Cowboy("Enemy", Point(5, 12));
    // Distance now: 13 / ninja2 speed: 12

    ninja2->move(enemy2); // Current distace: 1

    // Ninja's slash will do nothing to an enemy if he's exactly 1 distance away (readme rules)
    hpBeforeSlash = enemy2->getHealthPoints();
    ninja2->slash(enemy2);
    CHECK_EQ(enemy2->getHealthPoints(), hpBeforeSlash);

    // When ninja's distance to victim is shorter than his speed value, he will get to the victim
    ninja2->move(enemy2);
    CHECK_EQ(ninja2->getLocation().getx(), enemy2->getLocation().getx());
    CHECK_EQ(ninja2->getLocation().gety(), enemy2->getLocation().gety());

    // Ninja can't slash himself
    CHECK_THROWS(ninja2->slash(ninja2));

    // Ninja can't move throw himself
    CHECK_THROWS(ninja2->move(ninja2));

    delete ninja2;
    delete enemy2;
}

TEST_CASE("team Initialization") {
    Cowboy* cowboy1 = new Cowboy("Champ", Point());
    Team team1(cowboy1);

    // Basic funcitons of team
    CHECK_EQ(team1.stillAlive(), 1);
    CHECK_EQ(team1.getLeader(), cowboy1);

    delete cowboy1;
}

TEST_CASE("Team add() and stillAlive() functions") {
    // Set up team with a leader
    Cowboy* cowboy1 = new Cowboy("Champ", Point());
    Team team1(cowboy1);
    
    // Basic add() should increase number of team members
    Cowboy* cowboy2 = new Cowboy("Coco", Point());
    team1.add(cowboy2);
    CHECK_EQ(team1.stillAlive(), 2);

    // Team can't add the same Character twice
    CHECK_THROWS(team1.add(cowboy1)); // Leader
    CHECK_THROWS(team1.add(cowboy2)); // Member

    // Team can't contain more than 10 Characters
    for (size_t i = 0; i < 8; i++) {
        team1.add(new Cowboy("Generic Cowboy", Point()));
    }

    CHECK_EQ(team1.stillAlive(), 10);

    Cowboy* cowboy3 = new Cowboy("Candy", Point());
    CHECK_THROWS(team1.add(cowboy3));

    // Team can't add a Character that's already in another team
    Team team2(cowboy3);
    CHECK_THROWS(team2.add(cowboy1)); // Leader
    CHECK_THROWS(team2.add(cowboy2)); // Member

    // Tean can't add a dead Character
    Cowboy* cowboy4 = new Cowboy("ToBeKilled", Point());
    cowboy4->hit(999);
    CHECK_THROWS(team2.add(cowboy4));

    // Team can't be created if the first Leader is in another team
    CHECK_THROWS(Team(cowboy1)); // Leader
    CHECK_THROWS(Team(cowboy2)); // Member

    // If a member is dead, he is no longer part of the team
    cowboy2->hit(999);
    CHECK_EQ(team1.stillAlive(), 9);

    // If The leader is dead, he is no longer part of the team
    cowboy1->hit(999);
    CHECK_EQ(team1.stillAlive(), 8);

    delete cowboy1;
    delete cowboy2;
    delete cowboy3;
    delete cowboy4;
}

TEST_CASE("Team iterating") {
    Cowboy* cowboy1 = new Cowboy("Champ", Point(1, 1));
    Cowboy* cowboy2 = new Cowboy("Coco", Point(1, 1));
    Cowboy* cowboy3 = new Cowboy("Candy", Point(1, 1));
    YoungNinja* ninja1 = new YoungNinja("Yu", Point(30, 30));
    YoungNinja* ninja2 = new YoungNinja("Gi", Point(31, 31));
    YoungNinja* ninja3 = new YoungNinja("Oh", Point(33, 33));

    // Cowboys will be orders by the time they joined, as well as ninjas
    // But all the cowboys will be before any ninja

    Team team(cowboy1);
    team.add(ninja1);
    team.add(ninja2);
    team.add(cowboy2);
    team.add(cowboy3);
    team.add(ninja3);

    // Expected order: c1, c2, c3, n1, n2, n3
    CHECK_EQ(team.getMembers().at(0), cowboy1);
    CHECK_EQ(team.getMembers().at(1), cowboy2);
    CHECK_EQ(team.getMembers().at(2), cowboy3);
    CHECK_EQ(team.getMembers().at(3), ninja1);
    CHECK_EQ(team.getMembers().at(4), ninja2);
    CHECK_EQ(team.getMembers().at(5), ninja3);

    // Iteration works well if the leader is ninja
    YoungNinja* ninja4 = new YoungNinja("Gx", Point(33, 33));
    Cowboy* cowboy4 = new Cowboy("Cow", Point(1, 1));

    Team team_b(ninja4);
    team_b.add(cowboy4);

    // Expected order: c4, n4
    CHECK_EQ(team_b.getMembers().at(0), cowboy4);
    CHECK_EQ(team_b.getMembers().at(1), ninja4);

    delete cowboy1;
    delete cowboy2;
    delete cowboy3;
    delete cowboy4;
    delete ninja1;
    delete ninja2;
    delete ninja3;
    delete ninja4;
}

TEST_CASE("Team2 iterating") {
    Cowboy* cowboy1 = new Cowboy("Champ", Point(1, 1));
    Cowboy* cowboy2 = new Cowboy("Coco", Point(1, 1));
    Cowboy* cowboy3 = new Cowboy("Candy", Point(1, 1));
    YoungNinja* ninja1 = new YoungNinja("Yu", Point(30, 30));
    YoungNinja* ninja2 = new YoungNinja("Gi", Point(31, 31));
    YoungNinja* ninja3 = new YoungNinja("Oh", Point(33, 33));

    // Cowboys will be orders by the time they joined, as well as ninjas
    // But all the cowboys will be before any ninja

    Team2 team(cowboy1);
    team.add(ninja1);
    team.add(ninja2);
    team.add(cowboy2);
    team.add(cowboy3);
    team.add(ninja3);

    // Expected order: c1, c2, c3, n1, n2, n3
    CHECK_EQ(team.getMembers().at(0), cowboy1);
    CHECK_EQ(team.getMembers().at(1), ninja1);
    CHECK_EQ(team.getMembers().at(2), ninja2);
    CHECK_EQ(team.getMembers().at(3), cowboy2);
    CHECK_EQ(team.getMembers().at(4), cowboy3);
    CHECK_EQ(team.getMembers().at(5), ninja3);

    // Iteration works well if the leader is ninja
    YoungNinja* ninja4 = new YoungNinja("Gx", Point(33, 33));
    Cowboy* cowboy4 = new Cowboy("Cow", Point(1, 1));

    Team2 team_b(ninja4);
    team_b.add(cowboy4);

    CHECK_EQ(team_b.getMembers().at(0), ninja4);
    CHECK_EQ(team_b.getMembers().at(1), cowboy4);

    delete cowboy1;
    delete cowboy2;
    delete cowboy3;
    delete cowboy4;
    delete ninja1;
    delete ninja2;
    delete ninja3;
    delete ninja4;
}

TEST_CASE("Team attack() function") {
    // To make things easier, team1 contains only cowboys and team2 contains only ninjas
    // Ofc any team can contains both
    Cowboy* cowboy1 = new Cowboy("Champ", Point(1, 1));
    Team team1(cowboy1);

    for (size_t i = 0; i < 5; i++) {
        team1.add(new Cowboy("Generic Cowboy", Point()));
    }

    YoungNinja* ninja1 = new YoungNinja("Yu", Point(30, 30));
    YoungNinja* ninja2 = new YoungNinja("Gi", Point(31, 31));
    YoungNinja* ninja3 = new YoungNinja("Oh", Point(33, 33));
    Team team2(ninja1);
    team2.add(ninja2);
    team2.add(ninja3);

    // A team can't attack() itself
    CHECK_THROWS(team1.attack(&team1));

    // If a ninja is too far he won't deal damage (in this test that's the only time ninjas attack)
    team2.attack(&team1);
    CHECK_EQ(cowboy1->getHealthPoints(), 110); // 'cowboy1' is the victim but he didn't get damaged.

    // 'team1' has 60 guaranteed damage in attack()
    // The only victim this round is 'ninja1' who has 100 HP
    team1.attack(&team2);
    CHECK_EQ(ninja1->getHealthPoints(), 40);
    CHECK_EQ(ninja2->getHealthPoints(), 100);
    CHECK_EQ(ninja3->getHealthPoints(), 100);

    // In this round, 'ninja1' is supposed to die, then 'ninja2' will be the new victim
    team1.attack(&team2);
    CHECK_FALSE(ninja1->isAlive());
    CHECK_EQ(ninja2->getHealthPoints(), 80);
    CHECK_EQ(team2.getLeader(), ninja1); // Altough he's dead. Readme rules.

    // New leader will be set only if the current leader is dead at the start of the round
    team2.attack(&team1);
    CHECK_EQ(team2.getLeader(), ninja2);

    team1.attack(&team2);

    // New leader must be an alive ('ninja1' is closer to 'ninja2' but he's dead)
    ninja2->hit(999); // Kill manually
    team2.attack(&team1);
    CHECK_EQ(team2.getLeader(), ninja3);

    team1.attack(&team2);

    // If all of a team's members are dead, it can't attack or be attacked
    ninja3->hit(999); // Kill manually
    CHECK_THROWS(team1.attack(&team2));
    CHECK_THROWS(team2.attack(&team1));

    delete cowboy1;
    delete ninja1;
    delete ninja2;
    delete ninja3;
}