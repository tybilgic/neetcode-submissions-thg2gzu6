/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        do {
            int num = left + (right - left) / 2;
            int res = guess(num);

            if (res == -1)
            {
                right = num - 1;
            }
            else if (res == 1)
            {
                left = num + 1;
            }
            else
            {
                return num;
            }
        } while (true);
    }
};