#include<bits/stdc++.h>
using namespace std;

bool solve(int curr_pos, int curr_power, int skips, int recharges, vector<int>& enemies, vector<bool>& battled,int regain_power) {
    // Base case
    if (curr_pos == 11) {
        return true;
    }

    // If Abhimanyu cannot fight the current enemy and has no skips or recharges left, return false and current circle is not equal to 11
    if (curr_power < enemies[curr_pos] && skips == 0 && recharges == 0) {
        return false;
    }

    // If the current enemy is k3 or k7 and Abhimanyu has already battled in the next circle
    if ((curr_pos == 2 || curr_pos == 6) && curr_pos + 1 < 11 && battled[curr_pos + 1]) {
        enemies[curr_pos] /= 2;
    }

    // Mark the current circle as battled
    battled[curr_pos] = true;

    // Try all options skip, recharge, battle
    // Skip the current enemy
    if (skips > 0) {
        if (solve(curr_pos + 1, curr_power, skips - 1, recharges, enemies, battled,regain_power)) {
            return true;
        }
    }

    //  Recharge power 
    if (recharges > 0) {
        if (solve(curr_pos + 1, curr_power + regain_power, skips, recharges - 1, enemies, battled,regain_power)) {
            return true;
        }
    }
// It is not clear about recharge power whether Abhimanyu will get the initial power or only the current recharge factor will increase  
  // if (recharges > 0) {
    //     if (solve(curr_pos + 1, curr_power + recharges, skips, recharges - 1, enemies, battled,regain_power)) {
    //         return true;
    //     }
    // }

    //  Battle the current enemy
    if (curr_power >= enemies[curr_pos]) {
        if (solve(curr_pos + 1, curr_power - enemies[curr_pos], skips, recharges, enemies, battled,regain_power)) {
            return true;
        }
    }

    // Backtrack to unmark the current circle as battled
    battled[curr_pos] = false;
    return false;
}

bool chakravyuha(int p, int a, int b, vector<int>& enemy_powers) {
    vector<bool> battled(11, false);


    return solve(0, p, a, b, enemy_powers, battled,p);
}

int main() {
    vector<int> nums1 = {3, 5, 2, 5, 8, 9, 12, 20, 9, 10, 11};
    vector<int> nums2 = {110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10};


    cout << boolalpha; 
    cout << "first case : " << chakravyuha(20, 5, 3, nums1) << endl;
    cout << "Second  case : " << chakravyuha(20, 2, 3, nums2) << endl;

    return 0;
}
