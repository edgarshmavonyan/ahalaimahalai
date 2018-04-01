#include <type_traits>
#include <iostream>

template<unsigned int... N_s>
class AhalaiMahalai;

template<unsigned int N_1, unsigned int... N_s>
class AhalaiMahalai<N_1, N_s...>: public AhalaiMahalai<N_s...> {
private:

    template<unsigned int... Ns>
    constexpr static typename std::enable_if_t<sizeof...(Ns) != 0, unsigned int>
    xorHelper() {
        return AhalaiMahalai<N_s...>::xorsum;
    }

    template<unsigned int... Ns>
    constexpr static typename std::enable_if_t<sizeof...(Ns) == 0, unsigned int>
    xorHelper() {
        return 0;
    }

    template<unsigned int... Ns>
    constexpr static typename std::enable_if_t<sizeof...(Ns) != 0, unsigned int>
    maxHelper() {
        return AhalaiMahalai<N_s...>::maxHeap;
    }

    template<unsigned int... Ns>
    constexpr static typename std::enable_if_t<sizeof...(Ns) == 0, unsigned int>
    maxHelper() {
        return 0;
    }

protected:
    const static unsigned int value = N_1;
    const static unsigned int xorsum = N_1 ^ xorHelper<N_s...>();
    const static unsigned int maxHeap = std::max(N_1, maxHelper<N_s...>());

private:

    template<unsigned int which, unsigned int... Ns>
    static constexpr typename std::enable_if_t<which == 1 && maxHeap == value, unsigned int >
    whenceHelper() {
        return 1;
    }

    template<unsigned int which, unsigned int... Ns>
    static constexpr typename std::enable_if_t<which == 1 && maxHeap != value && sizeof...(Ns) != 0, unsigned int >
    whenceHelper() {
        return 1 + AhalaiMahalai<N_s...>::whence;
    }

    template<unsigned int which, unsigned int... Ns>
    static constexpr typename std::enable_if_t<which != 1, unsigned int >
    whenceHelper() {
        return 0;
    }

    template<unsigned int which>
    static constexpr typename std::enable_if_t<which == 1, unsigned int >
    howHelper() {
        return maxHeap - (maxHeap ^ xorsum);
    }

    template<unsigned int which>
    static constexpr typename std::enable_if_t<which != 1, unsigned int >
    howHelper() {
        return 0;
    }

public:
    constexpr AhalaiMahalai() = delete;

    const static unsigned int who = ((unsigned int) (xorsum == 0)) + 1;

    const static unsigned int how = howHelper<who>();

    const static unsigned int whence = whenceHelper<who, N_s...>();

};

template<>
class AhalaiMahalai<> {
protected:
    const static unsigned int value = 0;
    const static unsigned int xorsum = 0;
    const static unsigned int maxHeap = 0;
};
