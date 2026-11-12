#include <print>
#include <ranges>
#include <algorithm>
#include <functional>

namespace rng = std::ranges;

int main() {
    auto sum_factors = [](int n) {
        auto factors = rng::views::iota(1, n)
            | rng::views::filter([n](int d) {
                return n % d == 0;
            });

        return rng::fold_left(factors, 0, std::plus{});
    };

    auto perfect_numbers = rng::views::iota(1, 10000)
        | rng::views::filter([sum_factors](int n) {
            return n == sum_factors(n);
        })
        | rng::views::take(4);

    rng::for_each(perfect_numbers, [](int n) {
        std::println("{}", n);
    });
}
