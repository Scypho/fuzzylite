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
 * File:   DrasticSum.h
 * Author: jcrada
 *
 * Created on 30 November 2013, 1:10 AM
 */

#ifndef FL_DRASTICSUM_H
#define FL_DRASTICSUM_H

#include "fl/norm/SNorm.h"
namespace fl {

    class FL_EXPORT DrasticSum : public SNorm {
    public:
        std::string className() const;
        scalar compute(scalar a, scalar b) const;
        DrasticSum* clone() const;

        static SNorm* constructor();
    };

}

#endif  /* FL_DRASTICSUM_H */

