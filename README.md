
 # Abhimanyu_and_problem
 There is no clarity about power recharge in this question. So I used initial power for recharge.
 
 if (recharges > 0) {
        if (solve(curr_pos + 1, curr_power + regain_power, skips, recharges - 1, enemies, battled,regain_power)) {
            return true;
        }
    }


    
 It is not clear about recharge power whether Abhimanyu will get the initial power or only the current recharge factor will increase  
  if (recharges > 0) {
      if (solve(curr_pos + 1, curr_power + recharges, skips, recharges - 1, enemies, battled,regain_power)) {
      return true;
     }
 }
