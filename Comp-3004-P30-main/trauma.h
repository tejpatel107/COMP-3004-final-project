/* Trauma Class
 *
 * concrete entity class that extends
 * the abstract Program class
 *
 * The program trauma gets displayed to the user,
 * along with all of its attributes.
 *
 * attributes (inherited from Program):
 *  programName
 *  minutes
 *  seconds
 *  frequency
*/

#ifndef TRAUMA_H
#define TRAUMA_H

#include"program.h"

class Trauma : public Program
{
public:
    Trauma();
    ~Trauma();
};

#endif // TRAUMA_H
