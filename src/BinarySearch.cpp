//
// Created by echo_ on 2023-08-20.
//

#include "BinarySearch.hpp"

int BinarySearch::Searching() {
    int result = -1;
    if(m_ArrayInts.size() == 1 && (m_ArrayInts[0] == m_Target)) return 0;

    unsigned int beginPoint = 0;
    unsigned int endPoint = m_ArrayInts.size();
    int midpoint = -1;
    while(beginPoint<endPoint){
        midpoint = static_cast<int>((endPoint + beginPoint)/2);
        if(m_ArrayInts[midpoint] == m_Target){
            result = midpoint;
            break;
        }
        if(m_ArrayInts[midpoint] > m_Target){
            endPoint = midpoint;
        }
        if(m_ArrayInts[midpoint] < m_Target){
            beginPoint = midpoint;
        }
    }
    return result;
}
