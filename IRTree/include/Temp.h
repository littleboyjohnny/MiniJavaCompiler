#pragma once

#include <string>
#include <map>

namespace IRTree {
    class CTemp {
    public:
        explicit CTemp( const std::string& regName ) : label(regName) {}

        const std::string& getName() const {
            return label;
        }

    private:
        std::string label;
    };
}