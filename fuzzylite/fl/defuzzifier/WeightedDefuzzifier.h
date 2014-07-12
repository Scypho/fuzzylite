/*
 Author: Juan Rada-Vilela, Ph.D.
 Copyright (C) 2010-2014 FuzzyLite Limited
 All rights reserved

 This file is part of fuzzylite.

 fuzzylite is free software: you can redistribute it and/or modify it under
 the terms of the GNU Lesser General Public License as published by the Free
 Software Foundation, either version 3 of the License, or (at your option)
 any later version.

 fuzzylite is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with fuzzylite.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * File:   WeightedDefuzzifier.h
 * Author: jcrada
 *
 * Created on 13 June 2014, 6:22 PM
 */

#ifndef FL_WEIGHTEDDEFUZZIFIER_H
#define FL_WEIGHTEDDEFUZZIFIER_H

#include "fl/defuzzifier/Defuzzifier.h"

namespace fl {
    class Activated;

    class FL_EXPORT WeightedDefuzzifier : public Defuzzifier {
    public:

        //The type is solely for the sake of performance. If the type is known
        //in advance to be Takagi-Sugeno or Tsukamoto, the defuzzification will
        //be slightly faster than using Automatic.

        enum Type {
            Automatic, TakagiSugeno, Tsukamoto
        };

        WeightedDefuzzifier(Type type = Automatic);
        virtual ~WeightedDefuzzifier();

        virtual void setType(Type type);
        virtual Type getType() const;
        virtual Type inferType(const Term* term) const;
        virtual bool isMonotonic(const Term* term) const;

        virtual scalar tsukamoto(const Term* monotonic, scalar activationDegree,
                scalar minimum, scalar maximum) const;

    protected:
        Type _type;

    };

}

#endif  /* FL_WEIGHTEDDEFUZZIFIER_H */

