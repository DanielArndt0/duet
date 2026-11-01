#pragma once

#include <utility>

template <typename T1, typename T2>
class Duet
{
public:
    Duet() : first_(), second_() {}

    Duet(T1 first, T2 second)
        : first_(std::move(first)), second_(std::move(second)) {}

    Duet(const Duet &) = default;
    Duet(Duet &&) = default;

    Duet &operator=(const Duet &) = default;
    Duet &operator=(Duet &&) = default;

    T1 &getFirst() { return first_; }
    const T1 &getFirst() const { return first_; }

    void setFirst(T1 data) { first_ = std::move(data); }

    T2 &getSecond() { return second_; }
    const T2 &getSecond() const { return second_; }

    void setSecond(T2 data) { second_ = std::move(data); }

    void setDuet(T1 first, T2 second)
    {
        first_ = std::move(first);
        second_ = std::move(second);
    }

    static Duet CreateDuet(T1 first, T2 second)
    {
        return Duet(std::move(first), std::move(second));
    }

private:
    T1 first_;
    T2 second_;
};
