#include <iostream>
# include <map>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int main()
{
    cout << "shootes and ladders!" << endl;
    map<int, int> board;
    // ladders
    board[1] = 38;
    board[4] = 14;
    board[9] = 31;
    board[28] = 84;
    board[21] = 42;
    board[36] = 44;
    board[80] = 100;
    board[51] = 67;
    board[71] = 91;
    // chutes
    board[98] = 78;
    board[95] = 75;
    board[93] = 73;
    board[87] = 24;
    board[64] = 60;
    board[62] = 19;
    board[56] = 53;
    board[47] = 26;
    board[49] = 11;
    board[16] = 6;
    queue<vector<int>> q;
    set<int> visited;
    for(int i=1;i<=6;i++) {
        vector<int> v;
        if(board.count(i)>0) {
            v.push_back(board[i]);
            visited.insert(board[i]);
        }
        else {
            v.push_back(i);
            visited.insert(i);
        }
        q.push(v);
    }
    bool found = false;
    while(!found) {
        vector<int> v = q.front();
        q.pop();
        int startingSquareNum = v[v.size()-1];
        int newSquareNum;
        for(int i=1;i<=6;i++) {
            if(board.count(startingSquareNum +i) >0) {
                newSquareNum = board[startingSquareNum+i];
            }
            else {
                newSquareNum = startingSquareNum +i;
            }
            vector<int> vCopy(v);
            if(!visited.count(newSquareNum)>0) {
                vCopy.push_back(newSquareNum);
                visited.insert(newSquareNum);
            }
            if(newSquareNum ==100) {
                found = true;
                for(int num : vCopy) {
                    cout<<num <<" ";
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}
