#include <iostream>
#include <utility>

#define mid(a, b) ( (a+b)/2 )
#define INFINITE 0x3f3f3f3f

using namespace std;

typedef pair<int, int> pii;

class SegmentTree {
    int A, B;
    pii max, min;
    SegmentTree *left, *right;

public:
    SegmentTree(int A, int B) {
        this->A = A;
        this->B = B;
        max = make_pair(-INFINITE, 0);
        min = make_pair(+INFINITE, 0);

        if(A == B)
            left = right = NULL;
        else
            left = new SegmentTree(A, mid(A, B)),
            right = new SegmentTree(mid(A, B) + 1, B);
    }

    pii minFind(int a, int b) {
        if(b < a || a < A || b > B) return make_pair(+INFINITE, 0);
        if(a == A && b == B) return min;
        if(b <= mid(A, B)) return left->minFind(a, b);
        if(a > mid(A, B)) return right->minFind(a, b);

        pii minLeft = left->minFind(a, mid(A, B)),
            minRight = right->minFind(mid(A, B)+1, b);
        
        return (minLeft < minRight ? minLeft : minRight);
    }

    pii maxFind(int a, int b) {
        if(b < a || a < A || b > B) return make_pair(-INFINITE, 0);
        if(a == A && b == B) return max;
        if(b <= left->B) return left->maxFind(a, b);
        if(a >= right->A) return right->maxFind(a, b);

        pii maxLeft = left->maxFind(a, mid(A, B)),
            maxRight = right->maxFind(mid(A, B)+1, b);
        
        return (maxLeft > maxRight ? maxLeft : maxRight);
    }

    int difFind(int a, int b) {
        pii max = maxFind(a, b),
            min = minFind(a, b);

        if(max.second != min.second)
            return max.first - min.first;

        pii maxLeft = maxFind(a, max.second-1),
            maxRight = maxFind(max.second+1, b),
            minLeft = minFind(a, min.second-1),
            minRight = minFind(min.second+1, b);
        
        pii secondMax = (maxLeft > maxRight ? maxLeft : maxRight),
            secondMin = (minLeft < minRight ? minLeft : minRight);
        
        int dif1 = max.first - secondMin.first;
        int dif2 = secondMax.first - min.first;            

        return dif1 > dif2 ? dif1 : dif2;
    }

    void update(int a, int v) {
        if(a < A || a > B)
            return;

        if(v < min.first)
            min = make_pair(v, a);
        if(v > max.first)
            max = make_pair(v, a);

        if(right) right->update(a, v);
        if(left) left->update(a, v);
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    SegmentTree baldes(1, N);

    for(int i=1, v; i<=N; i++)
        cin >> v,
        baldes.update(i, v);
    
    while(M--) {
        int op, x, y;
        cin >> op >> x >> y;

        if(op == 1)
            baldes.update(y, x);
        else if(op == 2)
            cout << baldes.difFind(x, y) << endl;
    }

    return 0;
}