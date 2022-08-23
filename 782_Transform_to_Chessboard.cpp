class Solution {
public:
    int one_cnt(int x)
    {
        int cnt = 0;
        while (x != 0)
        {
            if (x & 1)
                cnt++;
            x = x >> 1;
        }
        return cnt;
    }
    
    int movesToChessboard(vector<vector<int>>& board) 
    {
        int row = board.size();
        int col = board[0].size();

        unordered_set<int>r_num;
        for (int i = 0; i < row; ++i)
        {
            int x = 0;
            for (int j = 0; j < col; ++j)
            {
                x += (1 <<j)* board[i][j];
            }
            r_num.insert(x);
        }
        if (r_num.size() != 2)
            return -1;
        
        int std1 = 0;
        int std2 = 0;
        for (int i = 0; i < col; ++i)
        {
            if (i % 2 == 0)
                std1 += 1 << i;
            else
                std2 += 1 << i;
        }
        int b = *r_num.begin();
        int a = *(++r_num.begin());
        int ans_row = -1;
        if ((a ^ std1) == (b ^ std2))
        {
            int a1 = a ^ std1;
            int b1 = b ^ std2;
            int cnt = one_cnt(a1);
            if (cnt % 2 == 0)
        {
            a1 = a1 & a;
            int cnt1 = one_cnt(a1);
            if (cnt1 == cnt / 2)
            {
                if (ans_row == -1)
                    ans_row = cnt1;
                else
                    ans_row = ans_row < cnt1 ? ans_row : cnt1;
            }
        }
        }
        if ((a ^ std2) == (b ^ std1))
        {
            int a1 = a ^ std2;
            int b1 = b ^ std1;
            int cnt = one_cnt(a1);
            if (cnt % 2 == 1&& ans_row == -1)
                return -1;
            a1 = a1 & a;
            int cnt1 = one_cnt(a1);
            if (cnt1 != cnt / 2 && ans_row == -1)
                return -1;
            else if (cnt1 == cnt / 2)
            {
                if (ans_row == -1)
                    ans_row = cnt1;
                else
                    ans_row = ans_row < cnt1 ? ans_row : cnt1;
            }
                
        }
        
        unordered_set<int>c_num;
        for (int i = 0; i < col; ++i)
        {
            int x = 0;
            for (int j = 0; j < row; ++j)
            {
                x += (1 << j)* board[j][i];
            }
            c_num.insert(x);
        }
        if (c_num.size() != 2)
            return -1;
        int bc = *c_num.begin();
        int ac = *(++c_num.begin());
        int ans_col = -1;
        if ((ac ^ std1) == (bc ^ std2))
        {
            int a1 = ac ^ std1;
            int b1 = bc ^ std2;
            int cnt = one_cnt(a1);
            if (cnt % 2 == 0)
            {
                a1 = a1 & ac;
                int cnt1 = one_cnt(a1);
                if (cnt1 == cnt / 2)
                {
                    if (ans_col == -1)
                        ans_col = cnt1;
                    else
                        ans_col = ans_col < cnt1 ? ans_col : cnt1;
                } 
            }
        }
        if ((ac ^ std2) == (bc ^ std1))
        {
            int a1 = ac ^ std2;
            int b1 = bc ^ std1;
            int cnt = one_cnt(a1);
            if (cnt % 2 == 0)
            {
                a1 = a1 & ac;
                int cnt1 = one_cnt(a1);
                if (cnt1 == cnt / 2)
                {
                    if (ans_col == -1)
                        ans_col = cnt1;
                    else
                        ans_col = ans_col < cnt1 ? ans_col : cnt1;
                }
            }
        }
        if(ans_row + ans_col<0)
        return -1;
        return ans_row + ans_col;
    }
};