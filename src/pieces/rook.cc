#include "rook.h"
using namespace std;

Rook::Rook(const string &colour, int row, int col):
    Piece{colour, 'r', row, col}, hasMoved{false}, initPosn{row, col}{}

bool Rook::validMove(Move move, vector<vector<Piece*>> board) {
    updatePossibleMoves(board);
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        if ((it->getRow() == move.getEndRow()) && (it->getCol() == move.getEndCol())) {
            return true;
        }
    }
    return false;
}

void Rook::updatePossibleMoves(vector<vector<Piece*>> board) {
    if (posn.getRow() != initPosn.getRow() || posn.getCol() != initPosn.getCol()) {
        hasMoved = true; 
    }

    int row;
    int col;
    int incr;
    Position p = {0, 0};

    possibleMoves.clear();

    // Moving the Rook left
    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row, col - incr};
    
    while (p.positionWithinBounds()) {
        if(board[p.getRow()][p.getCol()] == nullptr){
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row, col - incr};
        } else if(board[p.getRow()][p.getCol()]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    // Moving the Rook right
    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row, col + incr};
    
    while (p.positionWithinBounds()) {
        if(board[p.getRow()][p.getCol()] == nullptr){
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row, col + incr};
        } else if(board[p.getRow()][p.getCol()]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    // Moving the Rook up
    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row - incr, col};
    
    while (p.positionWithinBounds()) {
        if(board[p.getRow()][p.getCol()] == nullptr){
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row - incr, col};
        } else if(board[p.getRow()][p.getCol()]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }

    // Moving the Rook down
    row = posn.getRow();
    col = posn.getCol();
    incr = 1;
    p = {row + incr, col};
    
    while (p.positionWithinBounds()) {
        if(board[p.getRow()][p.getCol()] == nullptr){
            possibleMoves.emplace_back(p);
            ++incr;
            p = {row + incr, col};
        } else if(board[p.getRow()][p.getCol()]->getColour() != colour){
            possibleMoves.emplace_back(p);
            break;
        } else {
            break;
        }
    }
}
