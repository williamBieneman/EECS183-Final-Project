#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Utility.h"
using namespace std;

int numPeople = 10;
char people[MAX_PEOPLE_PER_FLOOR + 1];

void resetRequests() {}

void removePeople(int indicesToRemove[MAX_PEOPLE_PER_FLOOR], int numPeopleToRemove) {
    // For each index in indicesToRemove:
    //		For all numPeople > j > i, set people[j] = people[j + 1] (i.e. shift everything over)
    //		decrement numPeople
    //		adjust indices to accomodate for removals
    // No need to clean up people; nothing after numPeople will be acessed without being modified first.
    // Reset requests

    int sorted_indices[numPeopleToRemove];
    sort(sorted_indices, sorted_indices + numPeopleToRemove);

    int removed{};
    for (int i = 0; i < numPeopleToRemove; ++i) {
        for (int j = indicesToRemove[i] - removed++; j < numPeople; ++j) {
            people[j] = people[j + 1];
        }
        --numPeople;
    }
    resetRequests();
}

void testFloor() {
    char new_people[MAX_PEOPLE_PER_FLOOR + 1] = "0123456789";
    for (int i{}; i < numPeople; ++i) {
        people[i] = new_people[i];
    }
    for (int i{}; i < numPeople; ++i) {
        cout << people[i];
    }
    cout << endl;
    int indices[] = { 6, 4, 7 };
    removePeople(indices, 3);
    for (int i{}; i < numPeople; ++i) {
        cout << people[i];
    }
    cout << endl;
}

int main() {
    testFloor();

    return 0;
}