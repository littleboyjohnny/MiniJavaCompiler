#pragma once

#include <string>

namespace IRTree {
    //using CLabel = std::string;
    class CLabel {
    public:
        explicit CLabel( const std::string s ) : label(s) {}

    private:
        const std::string label;
    };
}