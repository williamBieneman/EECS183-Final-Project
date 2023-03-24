/*
 * Copyright 2023 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Final Project - Elevators
 */
 
////////////////////////////////////////////////
// You will submit test.cpp to the autograder //
// FOR LAB 8, but NOT the final project Core  //
////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "AI.h"
#include "Building.h"
#include "BuildingState.h"
#include "Elevator.h"
#include "Floor.h"
#include "Game.h"
#include "Move.h"
#include "Person.h"
#include "SatisfactionIndex.h"
#include "Utility.h"

using namespace std;

void testFloor();

void start_tests() {
    testFloor();
    
    return;
}

void testFloor() {
    // Initialize
    Floor test_floor1;
    // Add people
    test_floor1.addPerson(Person("7f4t8a3"), 1);
    test_floor1.addPerson(Person("8f4t9a6"), -1);
    test_floor1.addPerson(Person("9f4t2a9"), 7);
    test_floor1.addPerson(Person("6f4t9a9"), -2);
    test_floor1.addPerson(Person("5f4t3a9"), 5);
    test_floor1.addPerson(Person("4f4t1a9"), 6);
    for (int i{}; i < test_floor1.getNumPeople(); ++i) {
        cout << test_floor1.getPersonByIndex(i);
    }
    
    // Test tick()
    test_floor1.tick(10);
    for (int i{}; i < test_floor1.getNumPeople(); ++i) {
        cout << test_floor1.getPersonByIndex(i);
    }

    // Test removePeople()
    int removals[] = { 2, 0, 5 };
    test_floor1.removePeople(removals, 3);

    for (int i{}; i < test_floor1.getNumPeople(); ++i) {
        cout << test_floor1.getPersonByIndex(i);
    }
}
