/*
 Author: Juan Rada-Vilela, Ph.D.
 Copyright © 2010-2015 FuzzyLite Limited.
 All rights reserved.

 This file is part of fuzzylite®.

 fuzzylite® is free software: you can redistribute it and/or modify it under
 the terms of the FuzzyLite License included with the software.

 You should have received a copy of the FuzzyLite License along with 
 fuzzylite®. If not, see <http://www.fuzzylite.com/license/>.

 fuzzylite® is a registered trademark of FuzzyLite Limited.

 */

#ifndef FL_LARGESTOFMAXIMUM_H
#define FL_LARGESTOFMAXIMUM_H

#include "fl/defuzzifier/IntegralDefuzzifier.h"

namespace fl {

    class FL_API LargestOfMaximum : public IntegralDefuzzifier {
    public:
        explicit LargestOfMaximum(int resolution = defaultResolution());
        virtual ~LargestOfMaximum() FL_IOVERRIDE;
        FL_DEFAULT_COPY_AND_MOVE(LargestOfMaximum)

        virtual std::string className() const FL_IOVERRIDE;
        virtual scalar defuzzify(const Term* term,
                scalar minimum, scalar maximum) const FL_IOVERRIDE;
        virtual LargestOfMaximum* clone() const FL_IOVERRIDE;

        static Defuzzifier* constructor();
    };
}
#endif  /* FL_LARGESTOFMAXIMUM_H */

