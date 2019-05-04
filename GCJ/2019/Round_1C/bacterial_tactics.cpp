#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> coord;
typedef pair<coord, char> move_by_player;

const int MAXN = 20;
char mat[MAXN][MAXN][MAXN];
vector<move_by_player> moves_by_becca;
int R, C;

void restore_current_mat(int current_turn) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            mat[i][j][current_turn] = mat[i][j][current_turn - 1];
        }
    }
}

int spread_mat(move_by_player current_move, int current_turn) {
    if (current_move.second == 'V') {
        for (int i = current_move.first.first; i < R; ++i) {
            if (mat[i][current_move.first.second][current_turn] == '#') return 0;
            if (mat[i][current_move.first.second][current_turn] == 'B') break;
            mat[i][current_move.first.second][current_turn] = 'B';
        }
        for (int i = current_move.first.first - 1; i >= 0; --i) {
            if (mat[i][current_move.first.second][current_turn] == '#') return 0;
            if (mat[i][current_move.first.second][current_turn] == 'B') break;
            mat[i][current_move.first.second][current_turn] = 'B';
        }
    } else {
        for (int j = current_move.first.second; j < C; ++j) {
            if (mat[current_move.first.first][j][current_turn] == '#') return 0;
            if (mat[current_move.first.first][j][current_turn] == 'B') break;
            mat[current_move.first.first][j][current_turn] = 'B';
        }
        for (int j = current_move.first.second - 1; j >= 0; --j) {
            if (mat[current_move.first.first][j][current_turn] == '#') return 0;
            if (mat[current_move.first.first][j][current_turn] == 'B') break;
            mat[current_move.first.first][j][current_turn] = 'B';
        }
    }
    return 1;
}

int becca_wins(int current_turn) {
    
    int can_make_a_move = 0;
    int lost_with_all_possible_moves = 1;
    int won = 0;

    // Use a move with 'V'
    for (int i = 0; i < R; ++i) {
        if (won) { break; }
        for (int j = 0; j < C; ++j) {
            if (mat[i][j][current_turn - 1] != '.') continue;
            can_make_a_move = 1;
            move_by_player new_move = move_by_player(coord(i, j), 'V');
            int player_status_after_move = spread_mat(new_move, current_turn);
            if (player_status_after_move) {
                lost_with_all_possible_moves = 0;
                if (becca_wins(current_turn + 1)) {
                    won = 1;
                    auto it = new_move;
                    cout << it.second << ' ' << it.first.first << ' ' << it.first.second << '\n';
                    cout << "curr turn = " << current_turn << '\n';
                    break;
                }
            }
            restore_current_mat(current_turn);
        }
    }

    // Use a move with 'H'
    for (int i = 0; i < R; ++i) {
        if (won) { break; }
        for (int j = 0; j < C; ++j) {
            if (mat[i][j][current_turn - 1] != '.') continue;
            can_make_a_move = 1;
            move_by_player new_move = move_by_player(coord(i, j), 'H');
            int player_status_after_move = spread_mat(new_move, current_turn);
            if (player_status_after_move) {
                lost_with_all_possible_moves = 0;
                if (becca_wins(current_turn + 1)) {
                    won = 1;
                    auto it = new_move;
                    cout << it.second << ' ' << it.first.first << ' ' << it.first.second << '\n';
                    cout << "curr turn = " << current_turn << '\n';
                    break;
                }
            }
            restore_current_mat(current_turn);
        }
    }

    if ((current_turn % 2) == 0) {
        if (lost_with_all_possible_moves || (!can_make_a_move)) return 1;
    }
    
    return won;
}

int main() {

    cin.tie(0); ios_base::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int nc = 1; nc <= T; ++nc) {

        
        cin >> R >> C;
        moves_by_becca.clear();

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> mat[i][j][0];
            }
        }

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (mat[i][j][0] != '.') continue;
                move_by_player new_move = move_by_player(coord(i, j), 'V');
                int player_dont_lose_after_move = spread_mat(new_move, 1);
                if (player_dont_lose_after_move) {
                    if (becca_wins(2)) {
                        moves_by_becca.push_back(new_move);
                    }
                }
                restore_current_mat(1);
            }
        }

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (mat[i][j][0] != '.') continue;
                move_by_player new_move = move_by_player(coord(i, j), 'H');
                int player_dont_lose_after_move = spread_mat(new_move, 1);
                if (player_dont_lose_after_move) {
                    if (becca_wins(2)) {
                        moves_by_becca.push_back(new_move);
                    }
                }
                restore_current_mat(1);
            }
        }

        cout << "Case #" << nc << ": " << moves_by_becca.size() << '\n';
        for (auto it: moves_by_becca) {
            cout << it.second << ' ' << it.first.first << ' ' << it.first.second << '\n';
        }
    }

    return 0;
}