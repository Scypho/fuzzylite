/*
 * Somewhat.h
 *
 *  Created on: 4/12/2012
 *      Author: jcrada
 */

#ifndef FL_SOMEWHAT_H_
#define FL_SOMEWHAT_H_

#include "Hedge.h"

namespace fl {

    class Somewhat: public Hedge {
    public:
        std::string name() const;
        scalar hedge(scalar x) const;
    };

} /* namespace fl */
#endif /* FL_SOMEWHAT_H_ */