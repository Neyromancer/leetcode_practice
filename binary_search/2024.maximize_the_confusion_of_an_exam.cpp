/*
  Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/

  TC: O(N), where N == len(answerKey)
  SC: O(1)
*/

int maxConsecutiveAnswers(string answerKey, int k) {
    int cntT = 0;
    int cntF = 0;
    int res = 0;
    int j = 0;
    for (int i = 0; i < answerKey.size(); ++i) {
        if (answerKey[i] == 'T')
            ++cntT;
        else
            ++cntF;
        
        while (j <= i && cntT > k && cntF > k) {
            if (answerKey[j] == 'T')
                --cntT;
            else
                --cntF;

            ++j;
        }

        int continuousTLength = cntT + cntF + (k - cntF < 0 ? k - cntF : 0);
        int continuousFLength = cntT + cntF + (k - cntT < 0 ? k - cntT : 0);
        res = std::max({res, continuousTLength, continuousFLength});
    }
    return res;
}
