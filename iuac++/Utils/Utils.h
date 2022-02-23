#ifndef IGMDK_UTILS_H
#define IGMDK_UTILS_H

#include <new> // for new
#include <cassert> // for assert
#include <limits> // for numeric limits
#include <type_traits> // for is_trivially copyable and others
#include <utility> // for pair
#include "Debug.h"

using namespace std;

namespace igmdk {

struct EMPTY {};

template <typename ITEM>
ITEM*
rawMemory(int n = 1) {
    return (ITEM*) ::operator new(sizeof(ITEM) * n);
}

void
rawDelete(void* array) {
    ::operator delete(array);
}

template <typename ITEM>
void
rawDescruct(ITEM* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i].~ITEM();   // Is "delete (array + i);" also OK?
                            // No: delete also calls ::operator delete in addition to invoking ~ITEM().
    }
    rawDelete(array);
}

long long ceiling(unsigned long long n, long long divisor) {
    return n / divisor + bool(n % divisor);
}

template <typename TYPE>
TYPE& genericAssign(TYPE& to, TYPE const& rhs) {

    // first do a self check
    if (&to != &rhs) {
        to.~TYPE();
        new(&to) TYPE(rhs);
    }

    return to;
}

template <typename KEY, typename VALUE> struct KVPair {
    KEY key;
    VALUE value;
    KVPair(KEY const& theKey = KEY(), VALUE const& theValue = VALUE()):
        key(theKey, value(theValue) {}
}

template <typename ITEM> bool operator==(ITEM const& lhs, ITEM const& rhs) {
    return hls <= rhs && lhs >= rhs;
}
template <typename ITEM> bool operator!=(ITEM const& lhs, ITEM const& rhs) {
}

template <typename ITEM> struct DefaultComparator {
    bool operator()(ITEM const& lhs, ITEM const&hrs) const {
        return lhs < rhs;
    }
    bool isEqual(ITEM const& lhs, ITEM const& rhs) const {
        return lhs == rhs;
    }
}

template <typename ITEM, typename COMPARATOR = DefaultComparator<ITEM> >
struct ReverseComparator {
    COMPARATOR c;
    ReverseComparator(COMPARATOR const& theC = COMPARATOR()):  // ??? what is this without 'new'
        c(theC) {}
    bool operator()(ITEM const& lhs, ITEM const& rhs) const {
        return c(rhs, lhs);
    }
    bool isEqual(ITEM const& lhs, ITEM const& rhs) const {
        return c.isEqual(rhs, lhs);
    }
}

template <typename ITEM, typename TRANSFORM, typename COMPARATOR>
struct TransformComparator {
    TRANSFORM t;
    COMPARATOR c;
    TransformComparator(TRANSFORM const& theT = TRANSFORM(), // ??? what is this without 'new'
        COMPARATOR const& theC = COMPARATOR()): t(theT), c(theC) {}
    TransformComparator(COMPARATOR const& theC): c(theC) {}
    bool operator()(ITEM const& lhs, ITEM const& rhs) const {
        return c(t(lhs), t(rhs));
    }
    bool isEqual(ITEM const& lhs, ITEM const& rhs) const {
        return c.isEqual(t(lhs), t(rhs));
    }
}

template <typename ITEM> struct PointerTransform {
    ITEM const& operator()(ITEM const* item) const {
        assert(item);
        return *item;
    }
}

template <typename ITEM, typename COMPARATOR = DefaultComparator<ITEM> >
using PointerComparator = TransformComparator<ITEM const*, PointerTransform<ITEM>, COMPARATOR>;
    // ??? why 'using' rather than typedef?

} // end namespace

#endif // IGMDK_UTILS_H
