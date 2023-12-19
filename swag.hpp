#pragma once

#include <cassert>
#include <functional>
#include <stack>

template <class T, T (*op)(T, T), T (*e)()>
struct swag {
    struct prod_stack {
        bool left;
        std::stack<T> st, prd;
        prod_stack() : left(false) {}
        prod_stack(bool left) : left(left) {}
        void push(T x) {
            T p = prod();
            st.push(x);
            if (left) prd.push(op(x, p));
            else prd.push(op(p, x));
        }
        void pop() {
            assert(!empty());
            st.pop(), prd.pop();
        }
        T top() {
            assert(!empty());
            return st.top();
        }
        T prod() { return empty() ? e() : prd.top(); }
        int size() { return prd.size(); }
        bool empty() { return prd.empty(); }
    };

    prod_stack front_st, back_st;
    swag() : front_st(true), back_st(false) {}
    void push(T x) { back_st.push(x); }
    void balance() {
        while (!back_st.empty()) {
            front_st.push(back_st.top());
            back_st.pop();
        }
    }
    void pop() {
        assert(!empty());
        if (front_st.empty()) balance();
        front_st.pop();
    }
    void front() {
        assert(!empty());
        if (front_st.empty()) balance();
        return front_st.top();
    }
    T prod() { return op(front_st.prod(), back_st.prod()); }
    int size() { return front_st.size() + back_st.size(); }
    bool empty() { return size() == 0; }
};
/*
 * @brief SWAG (Sliding Window Aggregation)
 * @docs docs/swag.md
 */