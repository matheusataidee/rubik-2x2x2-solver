

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212

#include <bits/stdc++.h>

using namespace std;

stack<pair<int, int> > stk;
unordered_map<string, pair<int, int> > mymap;

bool check(string p) {
    if (!(p[0] == p[1] && p[0] == p[2] && p[0] == p[3])) return false;
    if (!(p[4] == p[5] && p[4] == p[6] && p[4] == p[7])) return false;
    if (!(p[8] == p[9] && p[8] == p[10] && p[8] == p[11])) return false;
    if (!(p[12] == p[13] && p[12] == p[14] && p[12] == p[15])) return false;
    if (!(p[16] == p[17] && p[16] == p[18] && p[16] == p[19])) return false;
    if (!(p[20] == p[21] && p[20] == p[22] && p[20] == p[23])) return false;
    return true;
}

string movement(string p, int side, int direct) {
    string x = p;
    switch (side) {
        case 1:
            if (direct == 0) {
                x[0] = p[12];  x[1] = p[13];
                x[12] = p[8];  x[13] = p[9];
                x[8] = p[4];  x[9] = p[5];
                x[4] = p[0];  x[5] = p[1];
                x[16] = p[18];
                x[18] = p[19];
                x[19] = p[17];
                x[17] = p[16];
            } else {
                x[0] = p[4];  x[1] = p[5];
                x[4] = p[8];  x[5] = p[9];
                x[8] = p[12];  x[9] = p[13];
                x[12] = p[0];  x[13] = p[1];
                x[18] = p[16];
                x[19] = p[18];
                x[17] = p[19];
                x[16] = p[17];
            }
            break;
        case 2:
            if (direct == 0) {
                x[1] = p[21];  x[3] = p[23];
                x[17] = p[1];  x[19] = p[3];
                x[10] = p[17];  x[8] = p[19];
                x[21] = p[10];  x[23] = p[8];
                x[12] = p[14];
                x[14] = p[15];
                x[15] = p[13];
                x[13] = p[12];
            } else {
                x = p;
                x[21] = p[1];  x[23] = p[3];
                x[1] = p[17];  x[3] = p[19];
                x[17] = p[10];  x[19] = p[8];
                x[10] = p[21];  x[8] = p[23];
                x[14] = p[12];
                x[15] = p[14];
                x[13] = p[15];
                x[12] = p[13];
            }
            break;
        case 3:
            if (direct == 0) {
                x[18] = p[7];  x[19] = p[5];
                x[7] = p[21];  x[5] = p[20];
                x[21] = p[12];  x[20] = p[14];
                x[12] = p[18];  x[14] = p[19];
                x[0] = p[2];
                x[2] = p[3];
                x[3] = p[1];
                x[1] = p[0];
            } else {
                x[7] = p[18];  x[5] = p[19];
                x[21] = p[7];  x[20] = p[5];
                x[12] = p[21];  x[14] = p[20];
                x[18] = p[12];  x[19] = p[14];
                x[2] = p[0];
                x[3] = p[2];
                x[1] = p[3];
                x[0] = p[1];
            }
            break;
    }
    return x;
}

void mountAns(string p) {
    pair<int, int> mov = mymap[p];
    pair<int, int> last = make_pair(0, 0);
    while (mov != last) {
        stk.push(mov);
        p = movement(p, mov.first, 1 - mov.second);
        mov = mymap[p];
    }
    while (!stk.empty()) {
        mov = stk.top();
        stk.pop();
        if (mov.first == 1) {
            cout << "Cima ";
        } else if (mov.first == 2) {
            cout << "Lateral ";
        } else {
            cout << "Frente ";
        }
        if (mov.second == 0) {
            cout << "Horario" << endl;
        } else {
            cout << "Antihorario" << endl;
        }
    }
}

void solve(string p) {
    queue<string> myq;
    myq.push(p);
    while (!myq.empty()) {
        p = myq.front();
        myq.pop();
        if (check(p)) {
            mountAns(p);
            break;
        }
        string x;

        x = movement(p, 1, 0);
        if (mymap.find(x) == mymap.end()) {
            mymap[x] = make_pair(1, 0);
            myq.push(x);
        }

        x = movement(p, 1, 1);
        if (mymap.find(x) == mymap.end()) {
            mymap[x] = make_pair(1, 1);
            myq.push(x);
        }

        x = movement(p, 2, 0);
        if (mymap.find(x) == mymap.end()) {
            mymap[x] = make_pair(2, 0);
            myq.push(x);
        }

        x = movement(p, 2, 1);
        if (mymap.find(x) == mymap.end()) {
            mymap[x] = make_pair(2, 1);
            myq.push(x);
        }

        x = movement(p, 3, 0);
        if (mymap.find(x) == mymap.end()) {
            mymap[x] = make_pair(3, 0);
            myq.push(x);
        }

        x = movement(p, 3, 1);
        if (mymap.find(x) == mymap.end()) {
            mymap[x] = make_pair(3, 1);
            myq.push(x);
        }
    }
}


int main() {
    string init = "012345678901234567891234";
    for (int i = 0; i < 6; i++) {
        cout << "Branco = 1;   Verde = 2;   Vermelho = 3;   Amarelo = 4;   Azul = 5;   Rosa = 6" << endl;
        cout << "FACE " << char('A' + i) << endl;
        int g1, g2, g3, g4;
        cin >> g1 >> g2 >> g3 >> g4;
        if (i == 0) {
            init[0] = g1;
            init[1] = g2;
            init[2] = g3;
            init[3] = g4;
        } else if (i == 1) {
            init[4] = g1;
            init[5] = g2;
            init[6] = g3;
            init[7] = g4;
        } else if (i == 2) {
            init[8] = g1;
            init[9] = g2;
            init[10] = g3;
            init[11] = g4;
        } else if (i == 3) {
            init[12] = g1;
            init[13] = g2;
            init[14] = g3;
            init[15] = g4;
        } else if (i == 4) {
            init[16] = g1;
            init[17] = g2;
            init[18] = g3;
            init[19] = g4;
        } else if (i == 5) {
            init[20] = g1;
            init[21] = g2;
            init[22] = g3;
            init[23] = g4;
        }
    }
    pair<int, int> p = {0, 0};
    mymap[init] = p;
    //mymap.insert(pair<state, pair<int, int> >(fir, p));
    //mymap[fir] = p;
    solve(init); 
    return 0;
}

