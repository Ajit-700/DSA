class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int playersAbility = 0; // Pointer 1
        int trainersCapacity = 0; // Pointer 2

        while(playersAbility<players.size() && trainersCapacity< trainers.size() )
        {
            if(players[playersAbility]<= trainers[trainersCapacity])
            {
                playersAbility++;
            }
            trainersCapacity++;

        }
        return playersAbility;
    }

};