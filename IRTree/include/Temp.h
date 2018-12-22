#pragma once

#include <string>
#include <map>

namespace IRTree {
    class CTemp {
    public:
        explicit CTemp( const std::string& regName ) {
            label = "REG::" + regName;
        }

        const std::string& getName() const {
            return label;
        }


        std::string label;
    };
}