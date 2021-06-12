#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    IOS;
    int n, m;
    cin >> n >> m;
    vector<int> piles[m];
    for(int i = 0; i < m; ++i) {
        int stones_here;
        cin >> stones_here;
        piles[i].resize(stones_here);
        for(int j = stones_here - 1; j >= 0; --j) {
            int next_stone;
            cin >> next_stone;
            piles[i][j] = next_stone;
        }
    }

    int actions = 0;
    vector<pii> act_list;
    act_list.reserve(5 * 1e5);
    for(int i = 1; i < m; ++i) {
        // Move everything from all the piles to pile 1
        // Because we are doing FILO this should be in order
        while(!piles[i].empty()) {
            piles[0].push_back(piles[i].back());
            piles[i].pop_back();
            act_list[actions] = make_pair(i + 1, 1);
            ++actions;
        }
    }

    // Iterating from the top of the first pile, move everything.
    // For the special case where it's 1, move it to the pile whose number in your thing is furthest, depending on what is next.
    // You don't have to actually move stuff, allowing us to save time.
    // Blocks should be moved together
    int ones = 0; // Current number of ones on top
    for(int i = piles[0].size() - 1; i >= 0;) {
        // Move all the crap on top that isn't 1 to correct pile
        if(ones == 0 && piles[0][i] != 1) {
            act_list[actions] = make_pair(1, piles[0][i]);
            ++actions;
            --i;
        } else {
            // Count the number of 1's
            while(i >= 0 && piles[0][i] == 1) {
                ++ones;
                --i;
            }
            
            if(i == -1) break; // Have reached bottom 

            int one_begin_seq = actions;
            actions += ones; // reserve space for 1 -> scapegoat

            // Position i should be the beginning of the next block of non-ones
            // All of these should be zero-indexed
            // You want to search through this block for as long as possible to shift as many things before
            // Putting the 1's back on top.
            // The way you do this is by assigning a scapegoat pile.  All the 1's go to that scapegoat pile for temporary stay.
            // It should be the latest one possible.
            int scapegoat_pile = -1;
            int last_usable_pointer = 1;
            bool contained_in_block[m];
            fill(contained_in_block, contained_in_block + m, false);

            while(i >= 0 && piles[0][i] != 1) {
                contained_in_block[piles[0][i] - 1] = true;
                int before_move = last_usable_pointer;
                while(contained_in_block[last_usable_pointer] && last_usable_pointer < m) {
                    last_usable_pointer++;
                }// Advance the pointer to next unfound pile
                if(last_usable_pointer >= m) {
                    scapegoat_pile = before_move;
                    break;
                }
                // You are allowed to move it AFTER you ensure you aren't covering the scapegoat pile
                act_list[actions] = make_pair(1, piles[0][i]);
                ++actions;
                --i;
            }
            if(scapegoat_pile == -1) scapegoat_pile = last_usable_pointer;
            
            // Go back and update the targets of all the 1 hops
            for(int j = one_begin_seq; j < one_begin_seq + ones; ++j) {
                act_list[j] = make_pair(1, scapegoat_pile + 1);
            }
            // Also add the back-one-hops
            for(int j = 0; j < ones; ++j) {
                act_list[actions] = make_pair(scapegoat_pile + 1, 1); 
                ++actions;
            }
            
        }
        
    }

    cout << actions << "\n";
    for(int i = 0; i < actions; ++i) {
        cout << act_list[i].first << " " << act_list[i].second << "\n";
    }
}

