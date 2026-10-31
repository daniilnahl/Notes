class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        //sort both vectors
        //while loop until end of players
        //only increment players pointer if found a match or reached end of trainers
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end()); 

        int plr_ptr = 0, tr_ptr = 0, matches = 0;

        while(plr_ptr < players.size()){
            if (players[plr_ptr] <= trainers[tr_ptr]){
                matches++;
                plr_ptr++;

                //remove trainer[j]
                trainers.erase(trainers.begin() + tr_ptr);
            }else{
                tr_ptr++;
            }

            if (trainers.size() == 0) break;
            if (tr_ptr == trainers.size()){
                tr_ptr = 0;
                plr_ptr++;
            }
        }



        return matches;
    }
};


//players[i] = 'ability of player i'
//trainers[j] = 'trining capacity of trainer j'
//i player can match j trainer if players[i] <= trainer[j]
//only one i player match per j trainer and vice versa
//return max number of matchings between players and trainers


/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to first have two sorted vectors and starting with the player i who has the lowest ability player[i] find matches within j trainers such that the trainer with
 least amount of ability trainer[j] could satisfy the training needs of this lowest ability player.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used two pointers
 
 * WHAT TIME COMPLEXITY? Time complexity is O (n log n + m log m + n*M) N*M comes from this: n from loops to iterate over all players and M from the erase function. 
 So overall time complexity of O (N*M)
 * 
 * WHAT SPACE COMPLEXITY? Space complexity is O(n) due to erase function

 *  ***/

