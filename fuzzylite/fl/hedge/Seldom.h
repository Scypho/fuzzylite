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
 * Seldom.h
 *
 *  Created on: 4/12/2012
 *      Author: jcrada
 */

#ifndef FL_SELDOM_H
#define FL_SELDOM_H

#include "fl/hedge/Hedge.h"

namespace fl {

    class FL_EXPORT Seldom : public Hedge {
    public:
        std::string name() const;
        scalar hedge(scalar x) const;
        Seldom* clone() const;

        static Hedge* constructor();
    };

}
#endif /* FL_SELDOM_H */
