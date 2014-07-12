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
 * File:   IntegralDefuzzifier.h
 * Author: jcrada
 *
 * Created on 2 November 2013, 9:18 AM
 */

#ifndef FL_INTEGRALDEFUZZIFIER_H
#define FL_INTEGRALDEFUZZIFIER_H

#include "fl/defuzzifier/Defuzzifier.h"

namespace fl {
    //TODO: check  http://en.wikipedia.org/wiki/Adaptive_quadrature

    class FL_EXPORT IntegralDefuzzifier : public Defuzzifier {
    protected:
        static int _defaultResolution;

        int _resolution;
    public:

        static void setDefaultResolution(int defaultResolution);
        static int defaultResolution();

        IntegralDefuzzifier(int resolution = defaultResolution());
        virtual ~IntegralDefuzzifier();

        virtual void setResolution(int resolution);
        virtual int getResolution() const;
    };
}

#endif  /* INTEGRALDEFUZZIFIER_H */

