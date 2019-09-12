#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<int> > board){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<board.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
}

bool isBoardTraversed(vector<vector<int> > board){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board.at(i).at(j) < 0){
                return 0;
            }
        }
    }
    return 1;
}

bool isPositionValid(vector<vector<int> > board, vector<int> position){
    int x, y;
    x = position.at(0);
    y = position.at(1);
    if(x > 7 || y > 7 || x < 0 || y < 0){
        return 0;
    }
    else{
        if(board.at(x).at(y) > 0){
            return 0;
        }
    }
    return 1;
}

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

vector<int> TraverseBoard(vector<vector<int> > board, vector<int> moveList, vector<int> presentPosition){
    if(!isBoardTraversed(board)){
        int tryMove = moveList.at(moveList.size()-1);
        // cout<<tryMove<<endl;
        vector<int> nextPosition;
        if(tryMove == 1){
            nextPosition.push_back(presentPosition.at(0)+2);
            nextPosition.push_back(presentPosition.at(1)+1);
        }
        if(tryMove == 2){
            nextPosition.push_back(presentPosition.at(0)+1);
            nextPosition.push_back(presentPosition.at(1)+2);
        }
        if(tryMove == 3){
            nextPosition.push_back(presentPosition.at(0)-2);
            nextPosition.push_back(presentPosition.at(1)-1);
        }
        if(tryMove == 4){
            nextPosition.push_back(presentPosition.at(0)-1);
            nextPosition.push_back(presentPosition.at(1)-2);
        }
        if(tryMove == 5){
            nextPosition.push_back(presentPosition.at(0)+2);
            nextPosition.push_back(presentPosition.at(1)-1);
        }
        if(tryMove == 6){
            nextPosition.push_back(presentPosition.at(0)-2);
            nextPosition.push_back(presentPosition.at(1)+1);
        }
        if(tryMove == 7){
            nextPosition.push_back(presentPosition.at(0)+1);
            nextPosition.push_back(presentPosition.at(1)-2);
        }
        if(tryMove == 8){
            nextPosition.push_back(presentPosition.at(0)-1);
            nextPosition.push_back(presentPosition.at(1)+2);
        }
        // cout<<isPositionValid(board, nextPosition)<<endl;
        if(isPositionValid(board, nextPosition)){
            // printVector(nextPosition);
            printBoard(board);
            board.at(nextPosition.at(0)).at(nextPosition.at(1)) = moveList.size();
            moveList.push_back(1);
            cout<<endl;
            return TraverseBoard(board, moveList, nextPosition);
        }

        else{
            moveList.pop_back();
            if(tryMove <= 7){
                tryMove++;
                moveList.push_back(tryMove);
                return TraverseBoard(board, moveList, presentPosition);
            }
            else{
                int oldMove = moveList.at(moveList.size()-1);
                vector<int> previousPosition;
                return TraverseBoard(board, moveList, nextPosition);
                if(oldMove == 1){
                    previousPosition.push_back(presentPosition.at(0)-2);
                    previousPosition.push_back(presentPosition.at(1)-1);
                }
                if(oldMove == 2){
                    previousPosition.push_back(presentPosition.at(0)-1);
                    previousPosition.push_back(presentPosition.at(1)-2);
                }
                if(oldMove == 3){
                    previousPosition.push_back(presentPosition.at(0)+2);
                    previousPosition.push_back(presentPosition.at(1)+1);
                }
                if(oldMove == 4){
                    previousPosition.push_back(presentPosition.at(0)+1);
                    previousPosition.push_back(presentPosition.at(1)+2);
                }
                if(oldMove == 5){
                    previousPosition.push_back(presentPosition.at(0)-2);
                    previousPosition.push_back(presentPosition.at(1)+1);
                }
                if(oldMove == 6){
                    previousPosition.push_back(presentPosition.at(0)+2);
                    previousPosition.push_back(presentPosition.at(1)-1);
                }

                if(oldMove == 7){
                    previousPosition.push_back(presentPosition.at(0)-1);
                    previousPosition.push_back(presentPosition.at(1)+2);
                }

                if(oldMove == 8){
                    previousPosition.push_back(presentPosition.at(0)+1);
                    previousPosition.push_back(presentPosition.at(1)-2);
                }
                if(isPositionValid(board, previousPosition)){
                    board.at(presentPosition.at(0)).at(presentPosition.at(1)) = -1;
                    oldMove++;
                    moveList.at(moveList.size()-1) = oldMove;
                    return TraverseBoard(board, moveList, previousPosition);
                }
            }
        }
    }
    printBoard(board);
    return moveList;
}

int main(){
    vector<vector<int> > board;
    int i, j;
    vector<int> tempVector;
    for(i=0;i<8;i++){
        tempVector.clear();
        for(j=0;j<8;j++){
            tempVector.push_back(-1);
        }
        board.push_back(tempVector);
    }
    vector<int> initalPosition;
    initalPosition.push_back(0);
    initalPosition.push_back(0);
    vector<int> moveList, answerList;
    moveList.push_back(1);
    board.at(initalPosition.at(0)).at(initalPosition.at(1)) = 0;
    // printBoard(board);
    answerList = TraverseBoard(board, moveList, initalPosition);


    return 0;
}
