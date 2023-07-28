/* Allegry Class
 *
 * concrete entity class that extends
 * the abstract Program class
 *
 * The program allergy gets displayed to the user,
 * along with all of its attributes.
 *
 * attributes (inherited from Program):
 *  programName
 *  minutes
 *  seconds
 *  frequency
*/

#ifndef ALLERGY_H
#define ALLERGY_H
#include"program.h"

class Allergy : public Program
{
public:
    Allergy();
    ~Allergy();
};

#endif // ALLERGY_H
