#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                st.push(asteroid);
                continue;
            }

            bool is_destroid = false;
            
            while (!st.empty()) {
                int top = st.top();
                if (top < 0) break;
                
                if (top < abs(asteroid)) {
                    st.pop();
                }
                else if (top == abs(asteroid)) {
                    st.pop();
                    is_destroid = true;
                    break;
                }
                else {
                    is_destroid = true;
                    break;
                }
                
            }

            if (!is_destroid) st.push(asteroid);
        }

        vector<int> res; 
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
