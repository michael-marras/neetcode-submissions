class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<int>> boxes;
        std::unordered_map<int, std::unordered_set<int>> columns;

        for (int i = 0; i < board.size(); i++) {
            std::unordered_set<int> currRow;
            for (int j = 0; j < board[i].size(); j++) {
                int curr = board[i][j];
                if (curr == '.') {
                    continue;
                }
                if (!currRow.insert(curr).second) {
                    return false;
                }
                if (!columns[j].insert(curr).second) {
                    return false;
                }

                if (i < 3) {
                    if (j < 3) {
                        if (!boxes[0].insert(curr).second) {
                            return false;
                        }
                    }
                    else if (j < 6) {
                        if (!boxes[1].insert(curr).second) {
                            return false;
                        }
                    }
                    else {
                        if (!boxes[2].insert(curr).second) {
                            return false;
                        }
                    }
                }
                else if (i < 6) {
                    if (j < 3) {
                        if (!boxes[3].insert(curr).second) {
                            return false;
                        }
                    }
                    else if (j < 6) {
                        if (!boxes[4].insert(curr).second) {
                            return false;
                        }
                    }
                    else {
                        if (!boxes[5].insert(curr).second) {
                            return false;
                        }
                    }
                }
                else {
                    if (j < 3) {
                        if (!boxes[6].insert(curr).second) {
                            return false;
                        }
                    }
                    else if (j < 6) {
                        if (!boxes[7].insert(curr).second) {
                            return false;
                        }
                    }
                    else {
                        if (!boxes[8].insert(curr).second) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
