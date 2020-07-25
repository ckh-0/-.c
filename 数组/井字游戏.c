/*  井字游戏
    题目：难度中等12收藏分享切换为英文关注反馈设计一个算法，判断玩家是否赢了井字游戏。输入是一个
	      N x N 的数组棋盘，由字符" "，"X"和"O"组成，其中字符" "代表一个空位。
          以下是井字游戏的规则：
				1.玩家轮流将字符放入空位（" "）中。
				2.第一个玩家总是放字符"O"，且第二个玩家总是放字符"X"。
				3."X"和"O"只允许放置在空位中，不允许对已放有字符的位置进行填充。
				4.当有N个相同（且非空）的字符填充任何行、列或对角线时，游戏结束，对应该字符的玩家获胜。
				5.当所有位置非空时，也算为游戏结束。
				6.如果游戏结束，玩家不允许再放置字符。
		如果游戏存在获胜者，就返回该游戏的获胜者使用的字符（"X"或"O"）；如果游戏以平局结束，则返回
		"Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。
    思路：先定义一个判断函数，如果满足条件就返回相应的值，再选择带入‘X’或‘O’。
    总结：在使用VS编程时，定义了一个char*类型的函数，但返回值不能是"X","O","Draw"或"Pending"，可是后面我用
          Dev-c++就可以编译通过，不过还是提出了警告"无法从const char[]转换为char *"。
*/
#include<stdio.h>
// 判断胜利者是不是player(X或O)
int judge(char player, char** board, int boardSize) {
    int flag = 0;

    // 行
    for (int i = 0; i < boardSize; i++) {
        if (board[i][0] == player) {
            for (int j = 0; j < boardSize; j++) {
                if (board[i][j] != player) {
                    flag = 0;
                    break;
                }
                else
                    flag = 1;
            }
        }
        if (flag == 1) {
            return 1;
        }
    }

    // 列
    for (int j = 0; j < boardSize; j++) {
        if (board[0][j] == player) {
            for (int i = 0; i < boardSize; i++) {
                if (board[i][j] != player) {
                    flag = 0;
                    break;
                }
                else
                    flag = 1;
            }
        }
        if (flag == 1) {
            return 1;
        }
    }


    // 主对角线
    for (int i = 0; i < boardSize; i++) {
        if (board[i][i] != player) {
            flag = 0;
            break;
        }
        flag = 1;
    }
    if (flag == 1)
        return 1;

    // 斜对角线
    for (int i = boardSize - 1; i >= 0; i--) {
        if (board[i][boardSize - 1 - i] != player) {
            flag = 0;
            break;
        }
        flag = 1;
    }
    if (flag == 1)
        return 1;
    else
        return 0;
}

// 判断是否有空格
int have_empty(char** board, int boardSize) {
    int flag = 0;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == ' ') {
                flag = 1;
                return flag;
            }
        }
    }
    return flag;
}

char* tictactoe(char** board, int boardSize) {
    if (judge('X', board, boardSize)) {
        return "X";
    }
    else if (judge('O', board, boardSize)) {
        return "O";
    }
    else if ((!judge('X', board, boardSize)) && (!judge('O', board, boardSize)) && have_empty(board, boardSize)) {
        return "Pending";
    }
    else {
        return "Draw";
    }
}
int main(void) {
    char* board[] = { "OX ","OX ","O  " };
    char* c = tictactoe(board, 3);
    printf("%s", c);
}
