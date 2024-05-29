#include <iostream>
#include <vector>
using namespace std;

bool solve(int current_circle, int current_power, int skips, int recharges, vector<int>& enemies, vector<bool>& battled,int regain_power) {
    // Base case: Abhimanyu has reached the last circle
    if (current_circle == 11) {
        return true;
    }

    // If Abhimanyu cannot fight the current enemy and has no skips or recharges left, return false and current circle is not equal to 11
    if (current_power < enemies[current_circle] && skips == 0 && recharges == 0) {
        return false;
    }

    // If the current enemy is k3 or k7 and Abhimanyu has already battled in the next circle
    if ((current_circle == 2 || current_circle == 6) && current_circle + 1 < 11 && battled[current_circle + 1]) {
        enemies[current_circle] /= 2;
    }

    // Mark the current circle as battled
    battled[current_circle] = true;

    // Try all options: skip, recharge, battle
    // Option 1: Skip the current enemy
    if (skips > 0) {
        if (solve(current_circle + 1, current_power, skips - 1, recharges, enemies, battled,regain_power)) {
            return true;
        }
    }

    // Option 2: Recharge power 
    if (recharges > 0) {
        if (solve(current_circle + 1, current_power + regain_power, skips, recharges - 1, enemies, battled,regain_power)) {
            return true;
        }
    }
    // if (recharges > 0) {
    //     if (solve(current_circle + 1, current_power + recharges, skips, recharges - 1, enemies, battled,regain_power)) {
    //         return true;
    //     }
    // }

    // Option 3: Battle the current enemy
    if (current_power >= enemies[current_circle]) {
        if (solve(current_circle + 1, current_power - enemies[current_circle], skips, recharges, enemies, battled,regain_power)) {
            return true;
        }
    }

    // Backtrack to unmark the current circle as battled
    battled[current_circle] = false;
    return false;
}

bool can_cross_chakravyuha(int p, int a, int b, vector<int>& enemy_powers) {
    vector<bool> battled(11, false);


    return solve(0, p, a, b, enemy_powers, battled,p);
}

int main() {
    vector<int> enemy_powers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    vector<int> enemy_powers2 = {110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10};


    cout << boolalpha; 
    cout << "Test case 1: " << can_cross_chakravyuha(20, 5, 3, enemy_powers1) << endl;
    cout << "Test case 2: " << can_cross_chakravyuha(20, 2, 3, enemy_powers2) << endl;

    return 0;
}
