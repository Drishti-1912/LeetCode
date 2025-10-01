class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottles = 0;

        while (numBottles >= numExchange) {  //as long as you have enough bottles to exchange.

            /*You drink numExchange bottles in this round.
            Add that to your total count of consumed bottles. */
            consumedBottles += numExchange;

            numBottles -= numExchange; //Reduce the number of full bottles because you just drank them

            // Exchange them for one full bottle.
            numBottles++;
        }

        // Total bottles drunk = bottles you drank during exchanges + the remaining bottles.
        return consumedBottles + numBottles;
    }
};