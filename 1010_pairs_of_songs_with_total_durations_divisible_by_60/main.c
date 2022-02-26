int numPairsDivisibleBy60(int* time, int timeSize){
    int seconds[60] = {0}, count = 0;
    for (int i = 0; i < timeSize; i++){
        int target = 60 - (time[i] % 60);
        count += seconds[target % 60];
        seconds[time[i] % 60]++;
    }
    return count;
}

int MYnumPairsDivisibleBy60(int* time, int timeSize){
    int songs[60] = {};

    for (int i = 0; i < timeSize; i++){
        songs[time[i]%60] += 1;
    }
    int pairs = 0;
    for (int i = 1; i < 30; i++){
        pairs += songs[i]*songs[60-i];
    }
    if (songs[0] > 1){
        pairs += (songs[0]*(songs[0]-1))/2;
    }
    if (songs[30] > 1){
        pairs += (songs[30]*(songs[30]-1))/2;
    }
    return pairs;
}
